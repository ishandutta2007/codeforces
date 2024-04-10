#include <cstdio>
#include <cassert>
#include <algorithm>

const int INF=1e9+7;

int as[35005];


int freq[35005];
int distinct=0;

void add(int x,int cnt){
  distinct-=(freq[x]>0);
  freq[x]+=cnt;
  distinct+=(freq[x]>0);
}

int score(int l,int r){
  assert(l<=r);
  static int L=0,R=0;
  while(R<r) add(as[R++],1);
  while(L>l) add(as[--L],1);
  while(R>r) add(as[--R],-1);
  while(L<l) add(as[L++],-1);
  return distinct;
}

int mem[2][35005];
int *dp=mem[0],*next=mem[1];

void solve(int l,int r,int ql,int qr){
  if(l>r) return;
  int m=(l+r)/2;
  int best=-INF;
  int qm=-1;
  for(int i=ql;i<=std::min(m-1,qr);i++){
    if(best<dp[i]+score(i,m)){
      best=dp[i]+score(i,m);
      qm=i;
    }
  }
  assert(qm!=-1);
  next[m]=best;
  solve(l,m-1,ql,qm);
  solve(m+1,r,qm,qr);
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  dp[0]=0;
  std::fill(dp+1,dp+N+1,-INF);
  for(int i=0;i<K;i++){
    solve(1,N,0,N);
    std::swap(dp,next);
  }
  printf("%d\n",dp[N]);
}