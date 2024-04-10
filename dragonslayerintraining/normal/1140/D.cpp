#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int64_t dp[505][505];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      dp[i][j]=INF;
    }
  }
  for(int i=1;i<N;i++){
    dp[i-1][i]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=i+2;j<N;j++){
      for(int k=i+1;k<j;k++){
	dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]+(i+1)*(j+1)*(k+1));
      }
    }
  }
  printf("%I64d\n",dp[0][N-1]);
  return 0;
}