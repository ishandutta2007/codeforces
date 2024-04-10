#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdint.h>

int64_t N,K,P;
int64_t as[1000];
int64_t bs[2000];

int64_t dp[1000][2000];

int main(){
  std::cin>>N>>K>>P;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int64_t i=0;i<K;i++){
    std::cin>>bs[i];
  }
  std::sort(as,as+N);
  std::sort(bs,bs+K);
  for(int64_t j=0;j<K;j++){
    dp[0][j]=std::abs(as[0]-bs[j])+std::abs(bs[j]-P);
    if(j>0){
      dp[0][j]=std::min(dp[0][j],dp[0][j-1]);
    }
  }
  for(int64_t i=1;i<N;i++){
    dp[i][0]=1e18;
    for(int64_t j=1;j<K;j++){
      dp[i][j]=std::min(dp[i][j-1],std::max(dp[i-1][j-1],std::abs(as[i]-bs[j])+std::abs(bs[j]-P)));
    }
  }
  std::cout<<dp[N-1][K-1]<<std::endl;
  return 0;
}