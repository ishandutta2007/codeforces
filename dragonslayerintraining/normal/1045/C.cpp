#include <cstdio>
#include <vector>

std::vector<int> edges[100005];
int pre[100005];
int low[100005];
std::vector<int> treee[100005];
std::vector<int> backe[100005];
int euler=0;

std::vector<int> bct[200005];
int bct_size;

void dfs_low(int node){
  low[node]=pre[node]=++euler;
  for(int child:edges[node]){
    if(!pre[child]){
      dfs_low(child);
      treee[node].push_back(child);
    }else if(pre[child]<pre[node]){
      backe[node].push_back(child);
    }
  }
  for(int child:treee[node]){
    low[node]=std::min(low[node],low[child]);
  }
  for(int child:backe[node]){
    low[node]=std::min(low[node],pre[child]);
  }
}

std::vector<int> stk;
void dfs_bct(int node){
  if(!stk.empty()){
    bct[node].push_back(stk.back());
    bct[stk.back()].push_back(node);
  }
  for(int child:treee[node]){
    if(low[child]==pre[node]){
      stk.push_back(bct_size++);
      bct[node].push_back(stk.back());
      bct[stk.back()].push_back(node);
    }
    dfs_bct(child);
    if(low[child]==pre[node]){
      stk.pop_back();
    }
  }
}

int anc[200005][18];
int depth[200005];

void dfs_lca(int node,int parent){
  anc[node][0]=parent;
  for(int k=1;k<18;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  depth[node]=depth[parent]+1;
  for(int child:bct[node]){
    if(child==parent) continue;
    dfs_lca(child,node);
  }
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=18-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=18-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

void dump(int node,int parent){
  for(int child:bct[node]){
    if(child==parent) continue;
    printf("%d=>%d\n",node,child);
    dump(child,node);
  }
}

int main(){
  int N,M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_low(0);
  bct_size=N;
  dfs_bct(0);
  //dump(0,0);
  dfs_lca(0,0);
  for(int i=0;i<Q;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    int C=lca(A,B);
    printf("%d\n",(depth[A]+depth[B]-2*depth[C])/2);
  }
  return 0;
}