#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

const int INF=1e9+7;

std::vector<int> adj[100000];
std::vector<int> has[100000];
std::set<int> junct[100000];

int anc[100000][17];
int depth[100000];
int pre[100000];
int post[100000];
int t=0;
int cost[100000];

void dfs_lca(int node,int parent){
  depth[node]=depth[parent]+1;
  anc[node][0]=parent;
  pre[node]=t++;
  for(int k=1;k<17;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  for(int child:adj[node]){
    if(child==parent) continue;
    dfs_lca(child,node);
  }
  post[node]=t++;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=17-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=17-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

std::vector<int> stk[100000];

void dfs_solve(int node){
  for(int child:adj[node]){
    if(child==anc[node][0]) continue;
    dfs_solve(child);
  }
  for(int p:has[node]){
    while(stk[p].size()&&pre[stk[p].back()]>=pre[node]){
      assert(stk[p].back()!=node);
      if(anc[stk[p].back()][0]==node){
	cost[p]=INF;
      }
      stk[p].pop_back();
      cost[p]++;
    }
    if(stk[p].size()){
      junct[lca(stk[p].back(),node)].insert(p);
    }
    stk[p].push_back(node);
  }
  for(int p:has[node]){
    junct[node].erase(p);
  }
  for(int p:junct[node]){
    if(stk[p].size()>=2&&pre[stk[p][stk[p].size()-2]]>=pre[node]){
      while(stk[p].size()&&pre[stk[p].back()]>=pre[node]){
	stk[p].pop_back();
      }
      cost[p]++;
    }
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int K;
    scanf("%d",&K);
    while(K-->0){
      int X;
      scanf("%d",&X);
      X--;
      has[X].push_back(i);
    }
  }
  dfs_lca(0,0);
  dfs_solve(0);
  for(int i=0;i<Q;i++){
    if(cost[i]>=INF){
      printf("-1\n");
    }else{
      printf("%d\n",cost[i]);
    }
  }
  return 0;
}