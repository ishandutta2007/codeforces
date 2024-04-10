#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> plants;

int dp[5000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    int S;
    double X;
    std::cin>>S>>X;
    plants.push_back(S-1);
  }
  for(int i=0;i<N;i++){
    int min=1e9;
    for(int j=0;j<M;j++){
      min=std::min(min,dp[j]);
      dp[j]=min+(plants[i]!=j);
    }
  }
  int min=1e9;
  std::cout<<*std::min_element(dp,dp+M)<<std::endl;
  return 0;
}