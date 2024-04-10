#include <iostream>
#include <vector>

const int MOD=1000000007;

int vtime[100000];
int vtime_max;
int low[100000];

std::vector<int> children[100000];


std::vector<std::vector<int> > components;

std::vector<int> stk;
void scc(int node){
  if(low[node]!=0){
    return;
  }
  vtime[node]=++vtime_max;
  low[node]=vtime[node];
  stk.push_back(node);
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    scc(child);
    low[node]=std::min(low[node],low[child]);
  }
  if(low[node]==vtime[node]){
    std::vector<int> component;
    while(stk.back()!=node){
      component.push_back(stk.back());
      low[stk.back()]=1e9;
      stk.pop_back();
    }
    component.push_back(stk.back());
    low[stk.back()]=1e9;
    stk.pop_back();
    components.push_back(component);
  }
}

int cost[100000];

int main(){
  int N,M;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>cost[i];
  }
  std::cin>>M;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    children[A].push_back(B);
  }
  for(int i=0;i<N;i++){
    scc(i);
  }
  long long total_best=0;
  long long total_ways=1;
  for(int i=0;i<components.size();i++){
    int best=1e9;
    int ways=0;
    for(int j=0;j<components[i].size();j++){
      if(best>cost[components[i][j]]){
	best=cost[components[i][j]];
	ways=1;
      }else if(best==cost[components[i][j]]){
	ways++;
      }
    }
    total_best+=best;
    total_ways=(total_ways*ways)%MOD;
  }
  std::cout<<total_best<<" "<<total_ways<<std::endl;
  return 0;
}