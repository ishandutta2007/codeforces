#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::pair<int,int> > roads;

std::vector<int> edges[100];

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
  for(int other:edges[node]){
    dfs(other,c^1);
  }
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    if(A>B){
      std::swap(A,B);
    }
    roads.emplace_back(A,B);
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      if(roads[i].first<roads[j].first&&
	 roads[j].first<roads[i].second&&
	 roads[i].second<roads[j].second){
	edges[i].push_back(j);
	edges[j].push_back(i);
      }
    }
  }
  std::fill(color,color+M,-1);
  for(int i=0;i<M;i++){
    if(color[i]==-1){
      dfs(i,0);
    }
  }
  for(int i=0;i<M;i++){
    std::cout<<(color[i]?'i':'o');
  }
  std::cout<<std::endl;
  return 0;
}