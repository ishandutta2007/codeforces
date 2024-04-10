#include <iostream>
#include <vector>

int ret[50000];
std::vector<int> edges[50000];

void dfs(int parent,int node){
  ret[node]=parent;
  for(int i=0;i<edges[node].size();i++){
    if(edges[node][i]!=parent){
      dfs(node,edges[node][i]);
    }
  }
}

int main(){
  int N,R1,R2;
  std::cin>>N>>R1>>R2;
  R1--,R2--;
  for(int i=0;i<N;i++){
    if(i==R1){
      continue;
    }
    int num;
    std::cin>>num;
    num--;
    edges[num].push_back(i);
    edges[i].push_back(num);
  }
  dfs(-1,R2);
  bool space=false;
  for(int i=0;i<N;i++){
    if(i==R2){
      continue;
    }
    if(space){
      std::cout<<" ";
    }
    std::cout<<ret[i]+1;
    space=true;
  }
  std::cout<<std::endl;
  return 0;
}