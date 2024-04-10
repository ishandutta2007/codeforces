#include <iostream>
#include <vector>
#include <queue>

int N;
int degree[1<<16];
int sum[1<<16];

std::vector<std::pair<int,int> > edges;
std::queue<int> active;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>degree[i]>>sum[i];
    if(degree[i]==1){
      active.push(i);
    }
  }
  while(!active.empty()){
    int node=active.front();
    active.pop();
    if(degree[node]!=1){
      continue;
    }
    edges.emplace_back(node,sum[node]);
    sum[sum[node]]^=node;
    if(--degree[sum[node]]==1){
      active.push(sum[node]);
    }
    --degree[node];
  }
  std::cout<<edges.size()<<std::endl;
  for(std::pair<int,int> edge:edges){
    std::cout<<edge.first<<" "<<edge.second<<std::endl;
  }
  return 0;
}