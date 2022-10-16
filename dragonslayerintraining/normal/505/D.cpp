#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

std::vector<int> edges[100000];
int vtime[100000];
int low[100000];
int vtime_max=0;

std::vector<int> stk;
void scc(int node,bool& has_cycles){
  if(low[node]==1e9){
    return;
  }
  if(low[node]>0){
    has_cycles=true;
    return;
  }
  vtime[node]=++vtime_max;
  low[node]=vtime[node];
  stk.push_back(node);
  for(int child:edges[node]){
    scc(child,has_cycles);
    low[node]=std::min(low[node],low[child]);
  }
  if(low[node]==vtime[node]){
    while(stk.back()!=node){
      low[stk.back()]=1e9;
      stk.pop_back();
    }
    low[stk.back()]=1e9;
    stk.pop_back();
  }
}

int uf[100000];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M;
  std::cin>>N>>M;
  std::iota(uf,uf+N,0);
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    uf[find(A)]=find(B);
  }
  std::map<int,std::set<int> > conn;
  for(int i=0;i<N;i++){
    conn[find(i)].insert(i);
  }
  int total=0;
  for(auto component:conn){
    bool has_cycles=false;
    for(auto n:component.second){
      scc(n,has_cycles);
    }
    total+=component.second.size();
    if(!has_cycles){
      total--;
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}