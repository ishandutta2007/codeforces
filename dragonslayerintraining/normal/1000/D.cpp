#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int as[1005];
int dp[1005][1005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    dp[i+1][0]=dp[i][0];
    for(int x=1;x<=N;x++){
      dp[i+1][x-1]=(dp[i][x-1]+dp[i][x])%MOD;
    }
    if(as[i]>0&&as[i]<N){
      dp[i+1][as[i]]=(dp[i+1][as[i]]+dp[i][0])%MOD;
    }
  }
  /*
  for(int i=0;i<=N;i++){
    for(int x=0;x<=N;x++){
      printf("dp[%d][%d]=%d\n",i,x,dp[i][x]);
    }
  }
  */
  printf("%d\n",(dp[N][0]+MOD-1)%MOD);
  return 0;
}