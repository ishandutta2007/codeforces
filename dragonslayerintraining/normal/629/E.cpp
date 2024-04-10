#include <cstdio>
#include <vector>
#include <stdint.h>

std::vector<int> edges[100005];

int pre[100005];
int post[100005];
int anc[100005][17];
int depth[100005];
int euler=0;

void dfs_init(int node){
  pre[node]=euler++;
  for(int child:edges[node]){
    if(child==anc[node][0]) continue;
    depth[child]=depth[node]+1;
    anc[child][0]=node;
    for(int k=1;k<17;k++){
      anc[child][k]=anc[anc[child][k-1]][k-1];
    }
    dfs_init(child);
  }
  post[node]=euler;
}

int la(int a,int d){
  for(int k=0;k<17;k++){
    if(d&(1<<k)){
      a=anc[a][k];
    }
  }
  return a;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  a=la(a,depth[a]-depth[b]);
  if(a==b) return a;
  for(int k=17-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int64_t down_sum[100005];
int down_cnt[100005];
int64_t up_sum[100005];
int up_cnt[100005];

void dfs1(int node){
  down_sum[node]=0;
  down_cnt[node]=1;
  for(int child:edges[node]){
    if(child==anc[node][0]) continue;
    dfs1(child);
    down_sum[node]+=down_sum[child]+down_cnt[child];
    down_cnt[node]+=down_cnt[child];
  }
}

void dfs2(int node){
  for(int child:edges[node]){
    if(child==anc[node][0]) continue;
    up_cnt[child]=up_cnt[node]+down_cnt[node]-down_cnt[child];
    up_sum[child]=up_sum[node]+down_sum[node]-(down_sum[child]+down_cnt[child])+up_cnt[child];
    dfs2(child);
  }
}

double query(int a,int b){
  if(pre[a]>pre[b]) std::swap(a,b);
  //pre[a]<=pre[b]
  if(post[a]>=post[b]){
    //a is ancestor of b
    int c=la(b,depth[b]-depth[a]-1);
    //printf("A: 1+%d/%d+%d/%d=",(up_sum[a]+down_sum[a]-(down_sum[c]+down_cnt[c])),(up_cnt[a]+down_cnt[a]-down_cnt[c]),down_sum[b],down_cnt[b]);
    return 1+double(down_sum[b])/(down_cnt[b])+
      double(up_sum[a]+down_sum[a]-(down_sum[c]+down_cnt[c]))/(up_cnt[a]+down_cnt[a]-down_cnt[c]);
  }else{
    //printf("B: 1+%d/%d+%d/%d=",down_sum[a],down_cnt[a],down_sum[b],down_cnt[b]);
    return 1+double(down_sum[a])/(down_cnt[a])+double(down_sum[b])/(down_cnt[b]);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_init(0);
  dfs1(0);
  dfs2(0);
  /*
  for(int i=0;i<N;i++){
    printf("%d: %d,%d\n",i,up_cnt[i]+down_cnt[i],up_sum[i]+down_sum[i]);
  }
  */
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    printf("%.10f\n",query(U,V)+depth[U]+depth[V]-2*depth[lca(U,V)]);
  }
  return 0;
}