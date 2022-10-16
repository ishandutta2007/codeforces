#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::pair<int,int> > edges[100];
int N,M;

int color[100];

void dfs(int node,int c){
  if(color[node]>=0){
    if(color[node]==c){
      return;
    }
    std::cout<<"Impossible"<<std::endl;
    exit(0);
  }
  color[node]=c;
  for(auto e:edges[node]){
    dfs(e.first,c^e.second);
  }
}

int main(){
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int A,B,C;
    std::cin>>A>>B>>C;
    A--,B--;
    edges[A].emplace_back(B,C^1);
    edges[B].emplace_back(A,C^1);
  }
  std::fill(color,color+N,-1);
  for(int i=0;i<N;i++){
    if(color[i]==-1){
      dfs(i,0);
    }
  }
  std::vector<int> ans;
  for(int i=0;i<N;i++){
    if(color[i]==0){
      ans.push_back(i);
    }
  }
  std::cout<<ans.size()<<std::endl;
  for(int i=0;i<ans.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<ans[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}