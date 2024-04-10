#include <iostream>

int N;
int as[100005];
long long dp[100005];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X;
    std::cin>>X;
    as[X]++;
  }
  dp[0]=0;
  dp[1]=as[1];
  for(long long i=2;i<=100004;i++){
    dp[i]=dp[i-1];
    if(as[i]>0){
      dp[i]=std::max(dp[i],i*as[i]+dp[i-2]);
    }
  }
  std::cout<<dp[100004]<<std::endl;
  return 0;
}