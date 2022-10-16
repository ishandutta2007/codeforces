#include <cstdio>
#include <vector>
#include <cmath>
#include <stdint.h>
     
const int64_t INF=1e18+7;
     
struct Node{
  int64_t a,b;
  int64_t wait;//amount need to inc a until change
  int64_t inc;//lazy increase of a
}st[1600005];
     
std::vector<int64_t> children[200005];
     
int64_t ps[200005];
int64_t as[200005];
int64_t bs[200005];
std::pair<int64_t,int64_t> at[200005];
int64_t pre[200005];
int64_t post[200005];
int64_t euler=0;
     
void dfs(int64_t node){
  pre[node]=euler++;
  for(int64_t child:children[node]){
    as[child]+=as[node];
    bs[child]+=bs[node];
    dfs(child);
  }
  post[node]=euler;
}
     
void pull(int64_t w,int64_t L,int64_t R){
  int64_t a1=st[w<<1].a,a2=st[w<<1|1].a;
  int64_t b1=st[w<<1].b,b2=st[w<<1|1].b;
  if(a1*b1<a2*b2){
    st[w].a=a2;
    st[w].b=b2;
  }else{
    st[w].a=a1;
    st[w].b=b1;
  }
  st[w].wait=std::min(st[w<<1].wait,st[w<<1|1].wait);
  if(b1!=b2){
    int64_t wait=(a2*b2-a1*b1)/(b1-b2);
    if(wait>=0){
      st[w].wait=std::min(st[w].wait,wait);
    }
  }
  st[w].inc=0;
}
     
void push(int64_t w,int64_t L,int64_t R){
  if(R-L>1){
    st[w<<1].inc+=st[w].inc;
    st[w<<1|1].inc+=st[w].inc;
  }
  st[w].wait-=st[w].inc;
  st[w].a+=st[w].inc;
  st[w].inc=0;
}
     
void build(int64_t w,int64_t L,int64_t R){
  if(R-L==1){
    st[w].a=at[L/2].first;
    st[w].b=at[L/2].second;
    if(L%2==1){
      st[w].b*=-1;
    }
    st[w].wait=INF;
    st[w].inc=0;
  }else{
    int64_t M=(L+R)/2;
    build(w<<1,L,M);
    build(w<<1|1,M,R);
    pull(w,L,R);
  }
}
     
void update(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b,int64_t v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R&&st[w].wait>=v){
    st[w].inc+=v;
    push(w,L,R);
  }else{
    int64_t M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    pull(w,L,R);
  }
}
     
int64_t query(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b){
  push(w,L,R);
  if(b<=L||a>=R) return -INF;
  if(a<=L&&b>=R){
    return st[w].a*st[w].b;
  }else{
    int64_t M=(L+R)/2;
    return std::max(query(w<<1,L,M,a,b),query(w<<1|1,M,R,a,b));
  }
}
     
int main(){
  int64_t N,Q;
  scanf("%I64d %I64d",&N,&Q);
  for(int64_t i=1;i<N;i++){
    scanf("%I64d",&ps[i]);
    ps[i]--;
    children[ps[i]].push_back(i);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  dfs(0);
  for(int64_t i=0;i<N;i++){
    at[pre[i]]={as[i],bs[i]};
  }
  build(1,0,N*2);
  while(Q--){
    int64_t T;
    scanf("%I64d",&T);
    if(T==1){
      int64_t V,X;
      scanf("%I64d %I64d",&V,&X);
      V--;
      update(1,0,N*2,pre[V]*2,post[V]*2,X);
    }else{
      int64_t V;
      scanf("%I64d",&V);
      V--;
      printf("%I64d\n",query(1,0,N*2,pre[V]*2,post[V]*2));
    }
  } 
  return 0;
}