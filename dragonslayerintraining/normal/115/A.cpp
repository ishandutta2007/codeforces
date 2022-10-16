#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> children[2000];

int depth=0;

int dfs(int node){
  int ret=1;
  for(int i=0;i<children[node].size();i++){
    ret=std::max(ret,dfs(children[node][i])+1);
  }
  depth=std::max(depth,ret);
  return ret;
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int P;
    std::cin>>P;
    if(P>0){
      P--;
      children[P].push_back(i);
    }
  }
  for(int i=0;i<N;i++){
    dfs(i);
  }
  std::cout<<depth<<std::endl;
  return 0;
}