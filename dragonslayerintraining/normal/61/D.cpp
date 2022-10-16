#include <iostream>
#include <vector>
#include <algorithm>

int N;

struct cedge{
  int other;
  int len;
  cedge(int other,int len):other(other),len(len){
  }
};

std::vector<std::vector<struct cedge> > edges;

long long farthest=0;
long long total=0;

void dfs(int parent,int node,long long dist){
  for(int i=0;i<edges[node].size();i++){
    if(edges[node][i].other!=parent){
      dfs(node,edges[node][i].other,dist+edges[node][i].len);
    }
  }
  farthest=std::max(farthest,dist);
}

int main(){
  std::cin>>N;
  edges.resize(N);
  for(int i=0;i<N-1;i++){
    int x,y,w;
    std::cin>>x>>y>>w;
    x--,y--;
    edges[x].push_back(cedge(y,w));
    edges[y].push_back(cedge(x,w));
    total+=2*w;
  }
  dfs(0,0,0);
  std::cout<<total-farthest<<std::endl;
  return 0;
}