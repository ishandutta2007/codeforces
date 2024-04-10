#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e18+7;

int64_t xs[5005];
int64_t as[5005];
int64_t bs[5005];
int64_t cs[5005];
int64_t ds[5005];

int64_t dp[5005][5005];

int main(){
  int64_t N,S,E;
  scanf("%I64d %I64d %I64d",&N,&S,&E);
  for(int64_t i=1;i<=N;i++) scanf("%I64d",&xs[i]);
  for(int64_t i=1;i<=N;i++) scanf("%I64d",&as[i]);
  for(int64_t i=1;i<=N;i++) scanf("%I64d",&bs[i]);
  for(int64_t i=1;i<=N;i++) scanf("%I64d",&cs[i]);
  for(int64_t i=1;i<=N;i++) scanf("%I64d",&ds[i]);
  for(int64_t i=0;i<=N;i++){
    std::fill(dp[i],dp[i]+N+1,INF);
  }
  dp[0][0]=0;
  for(int64_t i=1;i<=N;i++){
    for(int64_t k=1;k<N;k++){
      int64_t res=INF;
      if(i==S){
	res=std::min(res,dp[i-1][k-1]+ds[i]-xs[i]);
	res=std::min(res,dp[i-1][k]+cs[i]+xs[i]);
      }else if(i==E){
	res=std::min(res,dp[i-1][k-1]+bs[i]-xs[i]);
	res=std::min(res,dp[i-1][k]+as[i]+xs[i]);
      }else{
	if(i<S||i<E||k>2) res=std::min(res,dp[i-1][k-1]+bs[i]+ds[i]-2*xs[i]);
	res=std::min(res,dp[i-1][k+1]+as[i]+cs[i]+2*xs[i]);
	if(k>(i>S)) res=std::min(res,dp[i-1][k]+bs[i]+cs[i]);
	if(k>(i>E)) res=std::min(res,dp[i-1][k]+as[i]+ds[i]);
      }
      dp[i][k]=res;
    }
  }
  /*
  for(int64_t i=0;i<=N;i++){
    for(int64_t k=0;k<N;k++){
      printf("%I64d ",dp[i][k]);
    }
    printf("\n");
  }
  */
  printf("%I64d\n",dp[N][1]);
  return 0;
}