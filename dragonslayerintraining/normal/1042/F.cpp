#include <cstdio>
#include <algorithm>
#include <vector>

const int INF=1e9+7;

std::vector<int> edges[1000005];
int deg[1000005];
int K;

int cost=0;
int dfs(int node,int parent){
  if(deg[node]==1){
    return 0;
  }
  std::vector<int> depth;
  depth.push_back(-1);
  for(int child:edges[node]){
    if(child==parent) continue;
    int x=dfs(child,node);
    if(x>=0){
      depth.push_back(x+1);
    }
  }
  std::sort(depth.begin(),depth.end());
  while(depth.size()>1&&
	depth[depth.size()-1]+depth[depth.size()-2]>K){
    depth.pop_back();
    cost++;
  }
  if(node==parent&&depth.size()>1) cost++;
  return depth.back();
}

int main(){
  int N;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
    deg[U]++,deg[V]++;
  }
  for(int i=0;i<N;i++){
    if(deg[i]>1){
      dfs(i,i);
      printf("%d\n",cost);
      return 0;
    }
  }
  return 0;
}