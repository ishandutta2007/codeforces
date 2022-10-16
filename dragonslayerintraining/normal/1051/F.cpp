#include <cstdio>
#include <stdint.h>
#include <vector>
#include <algorithm>

std::vector<std::pair<int64_t,int64_t> > edges[100005];

int64_t uf[100005];

std::vector<int64_t> special;
std::vector<int64_t> sdist;

int64_t dist[43][100005];
int64_t depth[100005];

int64_t hyper[42][42];

int64_t anc[100005][20];

int64_t find(int64_t a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void dfs_dist(int64_t node,int64_t parent,int64_t it){
  for(auto e:edges[node]){
    int64_t child=e.first;
    if(child==parent) continue;
    dist[it][child]=dist[it][node]+e.second;
    dfs_dist(child,node,it);
  }
}

void dfs_lca(int64_t node,int64_t parent){
  anc[node][0]=parent;
  for(int64_t k=1;k<20;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  for(auto e:edges[node]){
    int64_t child=e.first;
    if(child==parent) continue;
    depth[child]=depth[node]+1;
    dfs_lca(child,node);
  }
}

int64_t lca(int64_t a,int64_t b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int64_t diff=depth[a]-depth[b];
  for(int64_t k=20-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int64_t k=20-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  std::iota(uf,uf+N,0);
  for(int64_t i=0;i<M;i++){
    int64_t U,V,D;
    scanf("%I64d %I64d %I64d",&U,&V,&D);
    U--,V--;
    if(find(U)==find(V)){
      special.push_back(U);
      special.push_back(V);
      sdist.push_back(D);
    }else{
      edges[U].emplace_back(V,D);
      edges[V].emplace_back(U,D);
      uf[find(U)]=find(V);
    }
  }
  for(int64_t i=0;i<special.size();i++){
    dfs_dist(special[i],special[i],i);
  }
  dfs_dist(0,0,special.size());
  int64_t* tree_dist=dist[special.size()];
  dfs_lca(0,0);
  for(int64_t i=0;i<special.size();i++){
    for(int64_t j=0;j<special.size();j++){
      hyper[i][j]=dist[i][special[j]];
    }
  }
  for(int64_t i=0;i<special.size();i+=2){
    hyper[i][i+1]=hyper[i+1][i]=std::min(hyper[i][i+1],sdist[i>>1]);
  }
  for(int64_t k=0;k<special.size();k++){
    for(int64_t i=0;i<special.size();i++){
      for(int64_t j=0;j<special.size();j++){
	hyper[i][j]=std::min(hyper[i][j],hyper[i][k]+hyper[k][j]);
      }
    }
  }
  int64_t Q;
  scanf("%I64d",&Q);
  while(Q-->0){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    int64_t ans=tree_dist[U]+tree_dist[V]-2*tree_dist[lca(U,V)];
    for(int64_t i=0;i<special.size();i++){
      for(int64_t j=0;j<special.size();j++){
	ans=std::min(ans,dist[i][U]+hyper[i][j]+dist[j][V]);
      }
    }
    printf("%I64d\n",ans);
  }
  return 0;
}