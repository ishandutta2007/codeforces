#include <cstdio>
#include <vector>
#include <set>

int N,M;

std::set<int> edges[100000];

int vtime[100000];
int vtime_max=0;
int low[100000];

int component_cnt=0;

std::vector<int> stk;
void dfs(int node){
  if(low[node]){
    return;
  }
  vtime[node]=++vtime_max;
  low[node]=vtime[node];
  stk.push_back(node);
  for(std::set<int>::iterator it=edges[node].begin();it!=edges[node].end();it++){
    int child=*it;
    edges[child].erase(node);
    dfs(child);
    low[node]=std::min(low[node],low[child]);
  }
  if(low[node]==vtime[node]){
    while(stk.back()!=node){
      low[stk.back()]=1e9;
      stk.pop_back();
    }
    low[stk.back()]=1e9;
    stk.pop_back();
    component_cnt++;
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].insert(B);
    edges[B].insert(A);
  }
  dfs(0);
  if(component_cnt!=1){
    printf("0\n");
  }else{
    for(int i=0;i<N;i++){
      for(std::set<int>::iterator it=edges[i].begin();it!=edges[i].end();it++){
	printf("%d %d\n",i+1,(*it)+1);
      }
    }
  }
  return 0;
}