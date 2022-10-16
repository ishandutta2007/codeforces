#include <cstdio>
#include <algorithm>
#include <cassert>

const int64_t INF=1e10+7;
int N,K;
int as[100005];

int cnt[100005];
int64_t total=0;
int l=0,r=0;

void add(int x,int v){
  total-=1LL*cnt[x]*(cnt[x]-1)/2;
  cnt[x]+=v;
  total+=1LL*cnt[x]*(cnt[x]-1)/2;
}

int64_t query(int L,int R){
  while(r<R) add(as[r++],1);
  while(l>L) add(as[--l],1);
  while(r>R) add(as[--r],-1);
  while(l<L) add(as[l++],-1);
  return total;
}

int64_t dp[21][100005];

void compute(int k,int al,int ar,int bl,int br){
  if(bl>br) return;
  int bm=(bl+br)/2;
  int am=-1;
  for(int a=al;a<=ar;a++){
    if(dp[k][bm]>dp[k-1][a]+query(a,bm)){
      dp[k][bm]=dp[k-1][a]+query(a,bm);
      am=a;
    }
  }
  //printf("k=%d: [%d,%d,%d] [%d,%d,%d]\n",k,al,am,ar,bl,bm,br);
  if(bl!=br){
    compute(k,al,am,bl,bm-1);
    compute(k,am,ar,bm+1,br);
  }
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int k=0;k<=K;k++){
    for(int i=0;i<=N;i++){
      dp[k][i]=INF;
    }
  }
  dp[0][0]=0;
  for(int k=1;k<=K;k++){
    compute(k,0,N-1,1,N);
  }
  printf("%I64d\n",dp[K][N]);
  return 0;
}