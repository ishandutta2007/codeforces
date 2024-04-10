#include <cstdio>
#include <algorithm>
#include <cassert>
#include <stdint.h>

const int INF=1e9+7;

struct Node{
  int min,cnt;
  Node():min(INF),cnt(0){
  }
  Node(int min,int cnt):min(min),cnt(cnt){
  }
};

struct Node combine(struct Node a,struct Node b){
  struct Node res;
  res.min=std::min(a.min,b.min);
  if(res.min==a.min) res.cnt+=a.cnt;
  if(res.min==b.min) res.cnt+=b.cnt;
  return res;
}

struct Node st[1200005];
int lazy[1200005];

void push(int w,int L,int R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w].min+=lazy[w];
  lazy[w]=0;
}

void build(int w,int L,int R){
  if(R-L==1){
    st[w]=Node(0,1);
  }else{
    int M=(L+R)/2;
    build(w<<1,L,M);
    build(w<<1|1,M,R);
    st[w]=combine(st[w<<1],st[w<<1|1]);
  }
}

void update(int w,int L,int R,int a,int b,int v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    st[w]=combine(st[w<<1],st[w<<1|1]);
  }
}

struct Node query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(b<=L||a>=R) return Node();
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int M=(L+R)/2;
    return combine(query(w<<1,L,M,a,b),query(w<<1|1,M,R,a,b));
  }
}

int as[300005];
int last[300005];

int main(){
  int N;
  scanf("%d",&N);
  build(1,0,N);
  int start=0;
  int64_t ans=0;
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    start=std::max(start,last[as[i]]);
    update(1,0,N,0,i,1);
    update(1,0,N,0,last[as[i]-1],-1);
    update(1,0,N,0,last[as[i]+1],-1);
    last[as[i]]=i;
    struct Node res=query(1,0,N,start,last[1]);
    if(res.min==1) ans+=res.cnt;
    /*
      printf("R=%d start=%d\n",i,start);
      for(int l=0;l<i;l++){
      struct Node res=query(1,0,N,l,l+1);
      assert(res.cnt==1);
      printf("L=%d: %d\n",l,res.min);
      }
      printf("ans=%d\n",ans.cnt);
    */
  }
  printf("%I64d\n",ans);
  return 0;
}