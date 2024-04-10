#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

const int INF=1e9+7;

int as[250];

int dp[251][251][501];
int N,M;

int solve(int i,int limit,int in){
  assert(limit>=0&&limit<=M);
  if(i==N){
    return (in==0)?0:INF;
  }
  if(in<-M||in>M) return INF;
  if(dp[i][limit][M+in]!=-1){
    return dp[i][limit][M+in];
  }
  int tmp=(limit>0)?solve(i,limit-1,in):INF;
  int out=as[i]+in-limit;
  int ans=std::min(tmp,solve(i+1,limit,out)+std::abs(out));
  //printf("solve(%d,%d,%d)=%d\n",i,limit,in,ans);
  return dp[i][limit][M+in]=ans;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  memset(dp,-1,sizeof(dp));
  printf("%d\n",solve(0,M,0));
}