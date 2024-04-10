#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> fwd[6000];
std::vector<int> rev[6000];

int vis[6000];
int scc[6000];
int nsccs=0;
int indeg[6000];

std::vector<int> post;

void dfs0(int node){
  if(vis[node]>=1) return;
  vis[node]=1;
  for(int child:fwd[node]){
    dfs0(child);
  }
  post.push_back(node);
}

void dfs1(int node){
  if(vis[node]>=2) return;
  vis[node]=2;
  scc[node]=nsccs;
  for(int child:rev[node]){
    dfs1(child);
  }
}

int main(){
  int N,M,S;
  scanf("%d %d %d",&N,&M,&S);
  S--;
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    fwd[U].push_back(V);
    rev[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    dfs0(i);
  }
  std::reverse(post.begin(),post.end());
  for(int i:post){
    if(vis[i]<2){
      dfs1(i);
      nsccs++;
    }
  }
  for(int i=0;i<N;i++){
    for(int j:fwd[i]){
      if(scc[i]!=scc[j]){
	indeg[scc[j]]++;
      }
    }
  }
  int cost=0;
  for(int i=0;i<nsccs;i++){
    if(i!=scc[S]&&indeg[i]==0){
      cost++;
    }
  }
  printf("%d\n",cost);
  return 0;
}