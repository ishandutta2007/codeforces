#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> strings[100000];

std::vector<int> impl[200000];

void implies(int a,int b){
  impl[a].push_back(b);
  impl[b^1].push_back(a^1);
}

int pre[200000];
int pre_max=0;
int low[200000];
bool assign[200000];

std::vector<int> stk;

void dfs_2sat(int node){
  if(pre[node]){
    return;
  }
  low[node]=pre[node]=++pre_max;
  stk.push_back(node);
  for(int child:impl[node]){
    dfs_2sat(child);
    low[node]=std::min(low[node],low[child]);
  }
  if(low[node]==pre[node]){
    std::vector<int> cmpt;
    while(stk.back()!=node){
      cmpt.push_back(stk.back());
      low[stk.back()]=1e9;
      stk.pop_back();
    }
    cmpt.push_back(stk.back());
    low[stk.back()]=1e9;
    stk.pop_back();
    if(assign[node^1]){
      return;
    }
    for(int v:cmpt){
      if(assign[v^1]){
	std::cout<<"No"<<std::endl;
	exit(0);
      }
      assign[v]=true;
    }
  }
}


int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    int L;
    std::cin>>L;
    while(L-->0){
      int S;
      std::cin>>S;
      S--;
      strings[i].push_back(S);
    }
  }
  for(int i=0;i<N-1;i++){
    for(int j=0;j<strings[i].size()||j<strings[i+1].size();j++){
      if(j==strings[i].size()){
	break;
      }
      if(j==strings[i+1].size()){
	std::cout<<"No"<<std::endl;
	return 0;
      }
      if(strings[i][j]<strings[i+1][j]){
	implies(strings[i+1][j]<<1,strings[i][j]<<1);
	break;
      }
      if(strings[i][j]>strings[i+1][j]){
	implies(strings[i][j]<<1|1,strings[i][j]<<1);
	implies(strings[i+1][j]<<1,strings[i+1][j]<<1|1);
	break;
      }
    }
  }
  for(int i=0;i<M*2;i++){
    dfs_2sat(i);
  }
  std::cout<<"Yes"<<std::endl;
  std::vector<int> yes;
  for(int i=0;i<M;i++){
    if(assign[i<<1]){
      yes.push_back(i);
    }
  }
  std::cout<<yes.size()<<std::endl;
  for(int i=0;i<yes.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<yes[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}