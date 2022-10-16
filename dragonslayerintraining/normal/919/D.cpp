#include <iostream>
#include <cstdlib>
#include <vector>

int N;
std::string str;
std::vector<int> dp;
std::vector<int> edges[300000];

void dfs_cycle(int node){
  if(dp[node]==1){
    std::cout<<-1<<std::endl;
    exit(0);
  }else if(dp[node]==2){
    return;
  }
  dp[node]=1;
  for(int child:edges[node]){
    dfs_cycle(child);
  }
  dp[node]=2;
}

void dfs_solve(int node,char c){
  if(dp[node]>=0){
    return;
  }
  dp[node]=0;
  for(int child:edges[node]){
    dfs_solve(child,c);
    dp[node]=std::max(dp[node],dp[child]);
  }
  dp[node]+=(str[node]==c);
}

int main(){
  int M;
  std::cin>>N>>M;
  std::cin>>str;
  for(int i=0;i<M;i++){
    int X,Y;
    std::cin>>X>>Y;
    X--,Y--;
    edges[X].push_back(Y);
  }
  dp.resize(N);
  for(int i=0;i<N;i++){
    dfs_cycle(i);
  }
  int best=0;
  for(char c='a';c<='z';c++){
    std::fill(dp.begin(),dp.end(),-1);
    for(int i=0;i<N;i++){
      dfs_solve(i,c);
      best=std::max(best,dp[i]);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}