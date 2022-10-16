#include <iostream>
#include <algorithm>

int dp[101][3];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    dp[i+1][0]=std::min(dp[i][0],std::min(dp[i][1],dp[i][2]))+1;
    dp[i+1][1]=(A&1)?std::min(dp[i][0],dp[i][2]):1e9;
    dp[i+1][2]=(A&2)?std::min(dp[i][0],dp[i][1]):1e9;
  }
  std::cout<<*std::min_element(dp[N],dp[N]+3)<<std::endl;
  return 0;
}