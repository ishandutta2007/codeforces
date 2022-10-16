#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

std::vector<int> edges[100000];

std::vector<int> cycle;

int vis[100000];
int depth[100001];//depth[N]=0
int far[100000];

int bad[100000];

bool dfs_cycle(int node,int ign){
  if(node==ign) return false;
  if(vis[node]==2) return false;
  if(vis[node]==1){
    cycle.erase(cycle.begin(),
		std::find(cycle.begin(),cycle.end(),node));
    return true;
  }
  vis[node]=1;
  cycle.push_back(node);
  for(int child:edges[node]){
    if(dfs_cycle(child,ign)) return true;
  }
  cycle.pop_back();
  vis[node]=2;
  return false;
}

int dfs_far(int node){
  if(vis[node]) return far[node];
  vis[node]=1;
  for(int child:edges[node]){
    int x=depth[child]?child:dfs_far(child);
    if(depth[x]>depth[far[node]]){
      far[node]=x;
    }
  }
  return far[node];
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
  }
  for(int i=0;i<N;i++){
    if(dfs_cycle(i,-1)) break;
  }
  for(int i=0;i<cycle.size();i++){
    depth[cycle[i]]=i;
  }
  std::fill(vis,vis+N,0);
  std::fill(far,far+N,N);
  for(int node:cycle){
    depth[node]+=cycle.size();
    dfs_far(node);
  }
  for(int i=0;i<cycle.size();i++){
    assert(far[cycle[i]]!=N);
    int a=(i+1)%cycle.size(),b=depth[far[cycle[i]]]%cycle.size();
    bad[a]++;
    bad[b]--;
    if(a>b){
      bad[0]++;
    }
  }
  for(int i=1;i<cycle.size();i++){
    bad[i]+=bad[i-1];
  }
  for(int i=0;i<cycle.size();i++){
    if(!bad[i]){
      std::fill(vis,vis+N,0);
      for(int j=0;j<N;j++){
	if(dfs_cycle(j,cycle[i])){
	  printf("-1\n");
	  return 0;
	}
      }
      printf("%d\n",cycle[i]+1);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}