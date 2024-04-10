#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cassert>

std::vector<int> dag[1000000];
int in[1000000];
int snk_id[1000000];

bool vis[1000000];

std::vector<int> adj[40];
int srcs=0,snks=0;
int match[40];

std::vector<int> mini[20];

void dfs_vis(int x){
  vis[x]=true;
  for(int y:dag[x]){
    if(!vis[y]){
      dfs_vis(y);
    }
  }
}

bool dfs_match(int x){
  if(vis[x]) return false;
  vis[x]=true;
  for(int y:adj[x]){
    if(match[y]==-1||dfs_match(match[y])){
      match[y]=x;
      match[x]=y;
      return true;
    }
  }
  return false;
}

void dfs_mini(int x){
  vis[x]=true;
  for(int y:mini[x]){
    if(!vis[y]){
      dfs_mini(y);
    }
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    dag[U].push_back(V);
    in[V]++;
  }
  std::fill(snk_id,snk_id+N,-1);
  for(int x=0;x<N;x++){
    if(dag[x].empty()){
      snk_id[x]=snks++;
    }
  }
  for(int x=0;x<N;x++){
    if(in[x]==0){
      std::fill(vis,vis+N,false);
      dfs_vis(x);
      for(int y=0;y<N;y++){
	if(vis[y]&&snk_id[y]!=-1){
	  adj[snk_id[y]].push_back(srcs+snks);
	  adj[srcs+snks].push_back(snk_id[y]);
	}
      }
      srcs++;
    }
  }
  if(srcs!=snks){
    printf("NO\n");
    return 0;
  }
  int matching=0;
  std::fill(match,match+srcs+snks,-1);
  for(int i=0;i<snks;i++){
    std::fill(vis,vis+srcs+snks,false);
    matching+=dfs_match(i);
  }
  if(matching!=srcs){
    printf("NO\n");
    return 0;
  }
  for(int i=0;i<snks;i++){
    for(int j:adj[i]){
      mini[i].push_back(match[j]);
    }
  }
  for(int i=0;i<snks;i++){
    std::fill(vis,vis+snks,false);
    dfs_mini(i);
    for(int j=0;j<snks;j++){
      if(!vis[j]){
	printf("NO\n");
	return 0;
      }
    }
  }
  printf("YES\n");
}