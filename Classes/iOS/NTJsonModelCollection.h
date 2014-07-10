//
//  NTJsonModelCollection.h
//  NTJsonModelStoreTests
//
//  Created by Ethan Nagel on 7/9/14.
//
//

#import <Foundation/Foundation.h>


@class NTJsonCollection;
@class NTJsonModel;
@class NTJsonModelStore;


@interface NTJsonModelCollection : NSObject

@property (nonatomic,readonly,weak) NTJsonCollection *collection;
@property (nonatomic) Class modelClass;

@property (nonatomic,readonly) NSString *name;
@property (nonatomic,readonly) NTJsonModelStore *store;
@property (nonatomic,readonly) NSError *lastError;
@property (nonatomic) int cacheSize;

-(void)addIndexWithKeys:(NSString *)keys;
-(void)addUniqueIndexWithKeys:(NSString *)keys;
-(void)addQueryableFields:(NSString *)fields;

-(void)flushCache;

-(void)beginEnsureSchemaWithCompletionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSError *error))completionHandler;
-(void)beginEnsureSchemaWithCompletionHandler:(void (^)(NSError *error))completionHandler;
-(BOOL)ensureSchemaWithError:(NSError **)error;
-(BOOL)ensureSchema;

-(void)beginInsert:(NTJsonModel *)model completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NTJsonRowId rowid, NSError *error))completionHandler;
-(void)beginInsert:(NTJsonModel *)model completionHandler:(void (^)(NTJsonRowId rowid, NSError *error))completionHandler;
-(NTJsonRowId)insert:(NTJsonModel *)model error:(NSError **)error;
-(NTJsonRowId)insert:(NTJsonModel *)model;

-(void)beginInsertBatch:(NSArray *)models completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSError *error))completionHandler;
-(void)beginInsertBatch:(NSArray *)models completionHandler:(void (^)(NSError *error))completionHandler;
-(BOOL)insertBatch:(NSArray *)models error:(NSError **)error;
-(BOOL)insertBatch:(NSArray *)models;

-(void)beginUpdate:(NTJsonModel *)model completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSError *error))completionHandler;
-(void)beginUpdate:(NTJsonModel *)model completionHandler:(void (^)(NSError *error))completionHandler;
-(BOOL)update:(NTJsonModel *)model error:(NSError **)error;
-(BOOL)update:(NTJsonModel *)model;

-(void)beginRemove:(NTJsonModel *)model completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSError *error))completionHandler;
-(void)beginRemove:(NTJsonModel *)model completionHandler:(void (^)(NSError *error))completionHandler;
-(BOOL)remove:(NTJsonModel *)model error:(NSError **)error;
-(BOOL)remove:(NTJsonModel *)model;

-(void)beginCountWhere:(NSString *)where args:(NSArray *)args completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(void)beginCountWhere:(NSString *)where args:(NSArray *)args completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(int)countWhere:(NSString *)where args:(NSArray *)args;
-(int)countWhere:(NSString *)where args:(NSArray *)args error:(NSError **)error;

-(void)beginCountWithCompletionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(void)beginCountWithCompletionHandler:(void (^)(int count, NSError *error))completionHandler;
-(int)countWithError:(NSError **)error;
-(int)count;

-(void)beginFindWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy limit:(int)limit completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSArray *models, NSError *error))completionHandler;
-(void)beginFindWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy limit:(int)limit completionHandler:(void (^)(NSArray *models, NSError *error))completionHandler;
-(NSArray *)findWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy limit:(int)limit error:(NSError **)error;
-(NSArray *)findWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy limit:(int)limit;

-(void)beginFindWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NSArray *models, NSError *error))completionHandler;
-(void)beginFindWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy completionHandler:(void (^)(NSArray *models, NSError *error))completionHandler;
-(NSArray *)findWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy error:(NSError **)error;
-(NSArray *)findWhere:(NSString *)where args:(NSArray *)args orderBy:(NSString *)orderBy;

-(void)beginFindOneWhere:(NSString *)where args:(NSArray *)args completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(NTJsonModel *model, NSError *error))completionHandler;
-(void)beginFindOneWhere:(NSString *)where args:(NSArray *)args completionHandler:(void (^)(NTJsonModel *model, NSError *error))completionHandler;
-(id)findOneWhere:(NSString *)where args:(NSArray *)args error:(NSError **)error;
-(id)findOneWhere:(NSString *)where args:(NSArray *)args;

-(void)beginRemoveWhere:(NSString *)where args:(NSArray *)args completionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(void)beginRemoveWhere:(NSString *)where args:(NSArray *)args completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(int)removeWhere:(NSString *)where args:(NSArray *)args error:(NSError **)error;
-(int)removeWhere:(NSString *)where args:(NSArray *)args;

-(void)beginRemoveAllWithCompletionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)(int count, NSError *error))completionHandler;
-(void)beginRemoveAllWithCompletionHandler:(void (^)(int count, NSError *error))completionHandler;
-(int)removeAllWithError:(NSError **)error;
-(int)removeAll;

-(void)beginSyncWithCompletionQueue:(dispatch_queue_t)completionQueue completionHandler:(void (^)())completionHandler;
-(void)beginSyncWithCompletionHandler:(void (^)())completionHandler;
-(BOOL)syncWait:(dispatch_time_t)duration;
-(void)sync;

-(NSString *)description;

@end
