#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <algorithm>
#include <vector>

const int64_t INF=1e18+7;

std::vector<std::pair<int,int> > children[500005];
int64_t depth[500005];
//pre[node]=node
int post[500005];
int euler=0;
int64_t st[2000005];
int64_t lazy[2000005];
int N;

void dfs_init(int node){
  assert(node==euler);
  euler++;
  for(auto e:children[node]){
    int child=e.first;
    int weight=e.second;
    depth[child]=depth[node]+weight;
    dfs_init(child);
  }
  post[node]=euler;
}

void st_pull(int w,int L,int R){
  st[w]=std::min(st[w<<1],st[w<<1|1]);
}

void st_push(int w,int L,int R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w]+=lazy[w];
  lazy[w]=0;
}

void st_inc(int w,int L,int R,int a,int b,int64_t v){
  st_push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    st_push(w,L,R);
  }else{
    int M=(L+R)/2;
    st_inc(w<<1,L,M,a,b,v);
    st_inc(w<<1|1,M,R,a,b,v);
    st_pull(w,L,R);
  }
}

void st_inc(int a,int b,int64_t v){
  st_inc(1,0,N,a,b,v);
}

int64_t st_query(int w,int L,int R,int a,int b){
  st_push(w,L,R);
  if(b<=L||a>=R) return INF;
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int M=(L+R)/2;
    return std::min<int64_t>(st_query(w<<1,L,M,a,b),st_query(w<<1|1,M,R,a,b));
  }
}

int64_t st_query(int a,int b){
  return st_query(1,0,N,a,b);
}

int64_t ans[500005];
struct Query{
  int id;
  int L,R;
  Query(int id,int L,int R):id(id),L(L),R(R){
  }
};
std::vector<struct Query> queries[500005];

void dfs_solve(int node){
  /*
  printf("node=%d\n",node);
  for(int i=0;i<N;i++){
    printf(" %I64d",st_query(i,i+1));
  }
  printf("\n");
  */
  for(auto q:queries[node]){
    ans[q.id]=st_query(q.L,q.R);
    //printf("Query %d: [%d,%d)=%I64d\n",q.id,q.L,q.R,ans[q.id]);
  }

  for(auto e:children[node]){
    int child=e.first;
    int weight=e.second;
    st_inc(0,N,weight);
    st_inc(child,post[child],-2*weight);
    dfs_solve(child);
    st_inc(0,N,-weight);
    st_inc(child,post[child],2*weight);
  }}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<N;i++){
    int P,W;
    scanf("%d %d",&P,&W);
    children[P-1].push_back({i,W});
  }
  dfs_init(0);
  for(int i=0;i<N;i++){
    if(children[i].empty()){
      st_inc(i,i+1,depth[i]);
    }else{
      st_inc(i,i+1,INF);
    }
  }
  for(int i=0;i<Q;i++){
    int V,L,R;
    scanf("%d %d %d",&V,&L,&R);
    V--,L--;
    queries[V].emplace_back(i,L,R);
  }
  dfs_solve(0);
  for(int i=0;i<Q;i++){
    printf("%I64d\n",ans[i]);
  }
  return 0;
}