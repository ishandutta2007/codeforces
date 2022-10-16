#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;
int perm[100];
int fav[100];

bool visited[100];

std::vector<int> edges[100];

void dfs(int n,std::vector<int>& collect){
  if(visited[n]){
    return;
  }
  visited[n]=true;
  collect.push_back(n);
  for(int i=0;i<edges[n].size();i++){
    dfs(edges[n][i],collect);
  }
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>perm[i];
    perm[i]--;
  }
  for(int i=0;i<N;i++){
    std::cin>>fav[i];
    fav[i]=std::abs(fav[i]);
    if(i+fav[i]<N){
      edges[i].push_back(i+fav[i]);
      edges[i+fav[i]].push_back(i);
    }
    if(i-fav[i]>=0){
      edges[i].push_back(i-fav[i]);
      edges[i-fav[i]].push_back(i);
    }
  }
  for(int i=0;i<N;i++){
    if(!visited[i]){
      std::vector<int> collect;
      dfs(i,collect);
      std::sort(collect.begin(),collect.end());
      std::vector<int> subperm;
      subperm.resize(collect.size());
      for(int i=0;i<collect.size();i++){
	subperm[i]=perm[collect[i]];
      }
      std::sort(subperm.begin(),subperm.end());
      for(int i=0;i<collect.size();i++){
	perm[collect[i]]=subperm[i];
      }
    }
  }
  for(int i=1;i<N;i++){
    if(perm[i]!=i){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}