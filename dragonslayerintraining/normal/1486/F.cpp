#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

int N,M;

std::vector<int> edges[300005];

int pre[300005];
int post[300005];
int euler=0;

int anc[300005][19];
int depth[300005];

std::vector<std::pair<int,int>> at[300005];

int ft[300005];

int query(int i){
  int ans=0;
  for(i++;i>0;i-=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}

void update(int i,int v){
  for(i++;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

void dfs_init(int x){
  pre[x]=euler++;
  for(int k=1;k<19;k++){
    anc[x][k]=anc[anc[x][k-1]][k-1];
  }
  for(int y:edges[x]){
    edges[y].erase(std::find(edges[y].begin(),edges[y].end(),x));
    anc[y][0]=x;
    depth[y]=depth[x]+1;
    dfs_init(y);
  }
  post[x]=euler;
}

int la(int x,int d){
  for(int k=19-1;k>=0;k--){
    if(d&(1<<k)){
      x=anc[x][k];
    }
  }
  return x;
}

int lca(int x,int y){
  if(depth[x]<depth[y]) std::swap(x,y);
  x=la(x,depth[x]-depth[y]);
  if(x==y) return x;
  for(int k=19-1;k>=0;k--){
    if(anc[x][k]!=anc[y][k]){
      x=anc[x][k];
      y=anc[y][k];
    }
  }
  return anc[x][0];
}

long long total=0;

void dfs_solve(int x){
  for(int y:edges[x]){
    dfs_solve(y);
  }
  /*
  fprintf(stderr,"lca=%d\n",x+1);
  for(auto p:at[x]){
    fprintf(stderr," (%d,%d)\n",p.first+1,p.second+1);
  }
  */
  for(auto p:at[x]){
    int u=p.first,v=p.second;
    if(u!=x) total+=query(pre[u]);
    if(v!=x) total+=query(pre[v]);
  }
  for(auto p:at[x]){
    int u=p.first,v=p.second;
    update(pre[x],1);
    update(post[x],-1);
    if(u!=x){
      int y=la(u,depth[u]-depth[x]-1);
      update(pre[y],-1);
      update(post[y],1);
    }
    if(v!=x){
      int z=la(v,depth[v]-depth[x]-1);
      update(pre[z],-1);
      update(post[z],1);
    }
  }
  total+=at[x].size()*(at[x].size()-1LL)/2;
  std::map<int,int> one;
  std::map<std::pair<int,int>,int> two;
  for(auto p:at[x]){
    int u=p.first,v=p.second;
    int y=(u!=x)?la(u,depth[u]-depth[x]-1):-1;
    int z=(v!=x)?la(v,depth[v]-depth[x]-1):-1;
    if(y!=-1) one[y]++;
    if(z!=-1) one[z]++;
    if(y!=-1&&z!=-1) two[{y,z}]++;
  }
  for(auto it:one){
    total-=it.second*(it.second-1LL)/2;
  }
  for(auto it:two){
    total+=it.second*(it.second-1LL)/2;
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_init(0);
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    if(pre[U]>pre[V]) std::swap(U,V);
    at[lca(U,V)].push_back({U,V});
  }
  dfs_solve(0);
  printf("%lld\n",total);
}