#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int as[100005];
int dp[100005][2][2];//0 is on , 1 is off

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  as[N+1]=M;
  for(int j=0;j<2;j++){
    for(int k=0;k<2;k++){
      dp[0][j][k]=-INF;
    }
  }
  dp[0][0][0]=0;
  for(int i=1;i<=N+1;i++){
    for(int j=0;j<2;j++){
      dp[i][j][0]=dp[i-1][j][1];
      dp[i][j][1]=dp[i-1][j][0]+as[i]-as[i-1];
    }
    if(as[i]-as[i-1]>1){
      for(int k=0;k<2;k++){
	dp[i][1][k]=std::max(dp[i][1][k],
			     dp[i-1][0][k]+as[i]-as[i-1]-1);
      }
    }
    /*
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
	printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
      }
    }
    */
  }
  int best=0;
  for(int j=0;j<2;j++){
    for(int k=0;k<2;k++){
      best=std::max(best,dp[N+1][j][k]);
    }
  }
  printf("%d\n",best);
  return 0;
}