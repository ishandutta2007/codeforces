#include <cstdio>
#include <stdint.h>
#include <algorithm>

int64_t N;
int64_t as[5000];
int64_t dp[5000];

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t best=N-1;
  for(int64_t i=1;i<N;i++){
    dp[i]=i;
    int64_t v=as[i];
    for(int64_t j=i-1;j>=0;j--){
      if(v%2==0){
	v/=2;
	if((as[j]%v==0)&&((as[j]/v)%2==1)){
	  dp[i]=std::min(dp[i],dp[j]+i-j-1);
	}
      }else{
	if(as[j]%v==0){
	  dp[i]=std::min(dp[i],dp[j]+i-j-1);
	}
      }
    }
    best=std::min(best,dp[i]+N-i-1);
  }
  printf("%I64d\n",best);
  return 0;
}