#include <cstdio>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <array>
#include <stdint.h>

std::mt19937 rng(std::chrono::steady_clock().now().time_since_epoch().count());

uint64_t hsh[300005];

struct Node{
  int left,right;
  uint64_t sum;
}st[300005*30];
int st_size=1;

int new_node(int l,int r){
  st[st_size]=Node{l,r,st[l].sum^st[r].sum};
  return st_size++;
}

//lvl = log_2 size
int update(int rt,int lvl,int i,uint64_t v){
  if(i<0||i>=(1<<lvl)) return rt;
  if(lvl==0){
    st[st_size]=Node{-1,-1,st[rt].sum^v};
    return st_size++;
  }else{
    return new_node(update(st[rt].left,lvl-1,i,v),update(st[rt].right,lvl-1,i-(1<<(lvl-1)),v));
  }
}

std::vector<int> adj[300005];
int as[300005];
int root[300005];

int anc[300005][19];
int depth[300005];

void dfs(int node){
  for(int child:adj[node]){
    adj[child].erase(std::find(adj[child].begin(),adj[child].end(),node));
    anc[child][0]=node;
    for(int k=1;k<19;k++){
      anc[child][k]=anc[anc[child][k-1]][k-1];
    }
    depth[child]=depth[node]+1;
    root[child]=update(root[node],19,as[child],hsh[as[child]]);
    
    dfs(child);
  }
}

int la(int node,int d){
  for(int k=19-1;k>=0;k--){
    if((d>>k)&1){
      node=anc[node][k];
    }
  }
  return node;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  a=la(a,depth[a]-depth[b]);
  if(a==b) return a;
  for(int k=19-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int solve(std::array<int,4> rts,int L,int R,int a,int b){
  if(a>=R||b<=L) return -1;
  if(a<=L&&b>=R){
    uint64_t sum=0;
    for(int i=0;i<4;i++){
      sum^=st[rts[i]].sum;
    }
    if(sum==0) return -1;
    if(R-L==1){
      return L;
    }
  }
  int M=(L+R)/2;
  std::array<int,4> lrts,rrts;
  for(int i=0;i<4;i++){
    lrts[i]=st[rts[i]].left;
    rrts[i]=st[rts[i]].right;
  }
  int res=solve(lrts,L,M,a,b);
  if(res==-1){
    res=solve(rrts,M,R,a,b);
  }
  return res;
}

int main(){
  std::uniform_int_distribution<uint64_t> distr;
  for(int i=0;i<300005;i++){
    hsh[i]=distr(rng);
  }
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  adj[0].push_back(1);
  adj[1].push_back(0);
  dfs(0);
  for(int i=0;i<Q;i++){
    int U,V,L,R;
    scanf("%d %d %d %d",&U,&V,&L,&R);
    L--;
    int W=lca(U,V);
    int res=solve({root[U],root[V],root[W],root[anc[W][0]]},0,1<<19,L,R);
    printf("%d\n",(res==-1)?-1:res+1);
  }
}