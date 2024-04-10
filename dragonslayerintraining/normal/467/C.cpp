#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t N,M,K;

int64_t ps[5001];
int64_t dp[5001][5001];

int main(){
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&ps[i]);
    ps[i]+=ps[i-1];
  }
  for(int64_t i=M;i<=N;i++){
    for(int64_t k=0;k<=K;k++){
      dp[i][k]=dp[i-1][k];
      if(k){
	dp[i][k]=std::max(dp[i][k],dp[i-M][k-1]+ps[i]-ps[i-M]);
      }
    }
  }
  printf("%I64d\n",dp[N][K]);
  return 0;
}