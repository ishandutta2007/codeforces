#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

std::vector<int64_t> edges[200000];
int64_t pleasant[200000];
int64_t sum[200000];
int64_t best=-1e15;

int64_t dfs(int64_t parent,int64_t id){
  std::vector<int64_t> chain;
  sum[id]=pleasant[id];
  for(int64_t i=0;i<edges[id].size();i++){
    int64_t other=edges[id][i];
    if(other!=parent){
      int64_t v=dfs(id,other);
      chain.push_back(v);
      sum[id]+=sum[other];
    }
  }
  std::sort(chain.begin(),chain.end());
  std::reverse(chain.begin(),chain.end());
  if(chain.size()>=2){
    best=std::max(best,chain[0]+chain[1]);
  }
  int64_t ret=sum[id];
  if(chain.size()>0){
    ret=std::max(ret,chain[0]);
  }
  return ret;
}

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>pleasant[i];
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(-1,0);
  if(best>-1e15){
    std::cout<<best<<std::endl;
  }else{
    std::cout<<"Impossible"<<std::endl;
  }
  return 0;
}