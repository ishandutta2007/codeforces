#include <iostream>
#include <vector>

std::vector<int> edges[100000];

int level[100000];

void dfs(int node,int depth){
  level[depth]^=1;
  for(int child:edges[node]){
    dfs(child,depth+1);
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    int P;
    std::cin>>P;
    P--;
    edges[P].push_back(i);
  }
  dfs(0,0);
  int total=0;
  for(int i=0;i<N;i++){
    total+=level[i];
  }
  std::cout<<total<<std::endl;
  return 0;
}