#include <iostream>
#include <vector>
#include <stdint.h>

std::vector<int> edges[100000];

int64_t color[2];

void dfs(int node,int parent,int c){
  color[c]++;
  for(int child:edges[node]){
    if(child!=parent){
      dfs(child,node,c^1);
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N-1;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs(0,0,0);
  std::cout<<color[0]*color[1]-N+1<<std::endl;
  return 0;
}