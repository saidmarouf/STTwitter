//
//  STOAuthProtocol.h
//  STTwitterRequests
//
//  Created by Nicolas Seriot on 9/18/12.
//  Copyright (c) 2012 Nicolas Seriot. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol STTwitterProtocol <NSObject>

- (BOOL)canVerifyCredentials;
- (void)verifyCredentialsWithSuccessBlock:(void(^)(NSString *username))successBlock
                               errorBlock:(void(^)(NSError *error))errorBlock;

- (NSString *)fetchResource:(NSString *)resource
                 HTTPMethod:(NSString *)HTTPMethod
              baseURLString:(NSString *)baseURLString
                 parameters:(NSDictionary *)params
              progressBlock:(void(^)(NSString *requestID, id response))progressBlock
               successBlock:(void(^)(NSString *requestID, NSDictionary *headers, id response))successBlock
                 errorBlock:(void(^)(NSString *requestID, NSDictionary *headers, NSError *error))errorBlock;

- (NSString *)consumerName;
- (NSString *)loginTypeDescription;

@optional

- (void)postTokenRequest:(void(^)(NSURL *url, NSString *oauthToken))successBlock
           oauthCallback:(NSString *)oauthCallback
              errorBlock:(void(^)(NSError *error))errorBlock;

- (void)postAccessTokenRequestWithPIN:(NSString *)pin
                         successBlock:(void(^)(NSString *oauthToken, NSString *oauthTokenSecret, NSString *userID, NSString *screenName))successBlock
                           errorBlock:(void(^)(NSError *error))errorBlock;

- (void)invalidateBearerTokenWithSuccessBlock:(void(^)())successBlock
                                   errorBlock:(void(^)(NSError *error))errorBlock;

// access tokens are available only with plain OAuth authentication
- (NSString *)oauthAccessToken;
- (NSString *)oauthAccessTokenSecret;

- (NSString *)bearerToken;

// reverse auth phase 1, implemented only in STTwitterOAuth
- (void)postReverseOAuthTokenRequest:(void(^)(NSString *authenticationHeader))successBlock
                          errorBlock:(void(^)(NSError *error))errorBlock;

// reverse auth phase 2, implemented only in STTwitterOS
- (void)postReverseAuthAccessTokenWithAuthenticationHeader:(NSString *)authenticationHeader
                                              successBlock:(void(^)(NSString *oAuthToken, NSString *oAuthTokenSecret, NSString *userID, NSString *screenName))successBlock
                                                errorBlock:(void(^)(NSError *error))errorBlock;

@end
