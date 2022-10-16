#include <iostream>
#include <stdint.h>

int64_t N,K;

int64_t dp[201][27*200];

int main(){
  for(int64_t k=0;k<=200;k++){
    for(int64_t i=0;i<27*200;i++){
      dp[k][i]=-1e9;
    }
  }
  dp[0][0]=0;
  std::cin>>N>>K;
  for(int64_t t=0;t<N;t++){
    int64_t A;
    std::cin>>A;
    int64_t pow2=0,pow5=0;
    for(;A%2==0;A/=2){
      pow2++;
    }
    for(;A%5==0;A/=5){
      pow5++;
    }
    for(int64_t k=K;k>=1;k--){
      for(int64_t i=pow5;i<27*200;i++){
	dp[k][i]=std::max(dp[k][i],dp[k-1][i-pow5]+pow2);
      }
    }
  }
  int64_t best=0;
  for(int64_t i=0;i<27*200;i++){
    best=std::max(best,std::min(i,dp[K][i]));
  }
  std::cout<<best<<std::endl;
}