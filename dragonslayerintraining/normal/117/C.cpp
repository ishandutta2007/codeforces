#include <cstdio>
#include <vector>
#include <algorithm>

char adj[5000][5000];
int N;

int state[5000];

std::vector<int> stk;
std::vector<int> cycle;

void dfs(int node){
  if(cycle.size()){
    return;
  }
  if(state[node]==2){
    return;
  }else if(state[node]==1){
    for(int i=0;i<stk.size();i++){
      if(stk[i]==node){
	std::copy(stk.begin()+i,stk.end(),std::back_inserter(cycle));
	return;
      }
    }
    return;
  }
  stk.push_back(node);
  state[node]=1;
  for(int i=0;i<N;i++){
    if(adj[node][i]=='1'){
      dfs(i);
    }
  }
  state[node]=2;
  stk.pop_back();
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",adj[i]);
  }
  for(int i=0;i<N;i++){
    dfs(i);
  }
  if(cycle.empty()){
    printf("-1\n");
  }else{
    if(adj[cycle[0]][cycle[1]]=='0'){
      std::reverse(cycle.begin(),cycle.end());
    }
    while(cycle.size()>=3){
      if(adj[cycle[0]][cycle[cycle.size()-2]]=='1'){
	printf("%d %d %d\n",cycle[0]+1,cycle[cycle.size()-2]+1,cycle[cycle.size()-1]+1);
	return 0;
      }else{
	cycle.pop_back();
      }
    }
  }
  return 0;
}