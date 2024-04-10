#include <iostream>
#include <vector>

std::vector<int> edges[5000];
int size[5000];
int N;

void dfs_size(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child!=parent){
      dfs_size(child,node);
      size[node]+=size[child];
    }
  }
}

std::vector<int> total;

void dfs_calc(int node,int parent){
  std::vector<int> cand;
  if(parent!=node){
    cand.push_back(N-size[node]);
  }
  for(int child:edges[node]){
    if(child!=parent){
      dfs_calc(child,node);
      cand.push_back(size[child]);
    }
  }
  std::vector<int> forms(N);
  forms[0]=1;
  for(int c:cand){
    for(int i=N-1;i>=c;i--){
      forms[i]|=forms[i-c];
    }
  }
  for(int i=0;i<N;i++){
    total[i]|=forms[i];
  }
}

int main(){
  std::cin>>N;
  total.resize(N);
  for(int i=1;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs_size(0,0);
  dfs_calc(0,0);
  std::vector<int> good;
  for(int i=1;i<N-1;i++){
    if(total[i]){
      good.push_back(i);
    }
  }
  std::cout<<good.size()<<std::endl;
  for(int g:good){
    std::cout<<g<<" "<<N-g-1<<std::endl;
  }
  return 0;
}