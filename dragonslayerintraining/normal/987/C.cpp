#include <cstdio>
#include <stdint.h>
#include <algorithm>

const int64_t INF=1e9+7;

int64_t N;
int64_t ss[3005];
int64_t cs[3005];
int64_t dp[4][3005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ss[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&dp[1][i]);
  }
  for(int64_t i=0;i<N;i++){
    dp[2][i]=INF;
    for(int64_t j=0;j<i;j++){
      if(ss[j]<ss[i]){
	dp[2][i]=std::min(dp[2][i],dp[1][j]+dp[1][i]);
      }
    }
  }
  for(int64_t i=0;i<N;i++){
    dp[3][i]=INF;
    for(int64_t j=0;j<i;j++){
      if(ss[j]<ss[i]){
	dp[3][i]=std::min(dp[3][i],dp[2][j]+dp[1][i]);
      }
    }
  }
  int64_t x=*std::min_element(dp[3],dp[3]+N);
  printf("%I64d\n",(x==INF)?-1:x);
  return 0;
}