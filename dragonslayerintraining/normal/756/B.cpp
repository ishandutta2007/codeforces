#include <iostream>
#include <algorithm>

long long N;
long long trips[100005];
long long dp[100005];

int main(){
  long long N;
  std::cin>>N;
  for(long long i=1;i<=N;i++){
    std::cin>>trips[i];
  }
  long long start_90=1;
  long long start_1440=1;
  for(long long i=1;i<=N;i++){
    while(trips[i]-trips[start_90]>=90){
      start_90++;
    }
    while(trips[i]-trips[start_1440]>=1440){
      start_1440++;
    }
    dp[i]=std::min(dp[start_90-1]+50,dp[start_1440-1]+120);
    dp[i]=std::min(dp[i],dp[i-1]+20);
  }
  for(long long i=1;i<=N;i++){
    std::cout<<dp[i]-dp[i-1]<<std::endl;
  }
  return 0;
}