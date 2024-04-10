#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t N;
std::pair<int64_t,int64_t> dp[5001][4];

int main(){
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    for(int64_t k=0;k<4;k++){
      dp[i+1][k]=dp[i][k];
    }
    dp[i+1][0].first+=A;
    dp[i+1][1].first-=A;
    dp[i+1][2].first+=A;
    dp[i+1][3].first-=A;
    for(int64_t k=1;k<4;k++){
      dp[i+1][k]=std::max(dp[i+1][k],std::make_pair(dp[i+1][k-1].first,i+1));
    }
  }
  std::vector<int64_t> res;
  for(int64_t i=N,k=3;k>0;k--){
    res.push_back(dp[i][k].second);
    i=dp[i][k].second;
  }
  std::reverse(res.begin(),res.end());
  for(int64_t i=0;i<res.size();i++){
    if(i!=0){
      std::cout<<" ";
    }
    std::cout<<res[i];
  }
  std::cout<<std::endl;
  return 0;
}