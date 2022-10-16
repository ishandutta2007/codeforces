#include <iostream>
#include <vector>

int N;

std::vector<int> edges[3000];

int ring[3000];

int vtime[3000];
int vtime_max=0;
int low[3000];

std::vector<int> stk;
void dfscycles(int node,int parent){
  if(low[node]!=0){
    return;
  }
  vtime[node]=++vtime_max;
  low[node]=vtime[node];
  stk.push_back(node);
  for(int i=0;i<edges[node].size();i++){
    int child=edges[node][i];
    if(child!=parent){
      dfscycles(child,node);
      low[node]=std::min(low[node],low[child]);
    }
  }
  if(low[node]==vtime[node]){
    int flag=1e9;
    if(stk.back()!=node){
      flag=0;
    }
    while(stk.back()!=node){
      low[stk.back()]=1e9;
      ring[stk.back()]=flag;
      stk.pop_back();
    }
    low[stk.back()]=1e9;
    ring[stk.back()]=flag;
    stk.pop_back();
  }
}

void dfsdist(int node,int parent,int dist){
  ring[node]=dist;
  for(int i=0;i<edges[node].size();i++){
    int child=edges[node][i];
    if(child!=parent){
      if(ring[child]!=0){
	dfsdist(child,node,dist+1);
      }
    }
  }
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfscycles(0,0);
  for(int i=0;i<N;i++){
    if(ring[i]==0){
      dfsdist(i,i,0);
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<ring[i];
  }
  std::cout<<std::endl;
  return 0;
}