#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <stdint.h>

const int BLOCK=400;

int fs[100005];
int gs[100005];

std::vector<int> edges[100005];
int pre[100005];
int post[100005];
int euler=0;
int who[200005];
bool has[100005];

int depth[100005];
int anc[100005][20];

void dfs_init(int node,int parent){
  who[euler]=node;
  pre[node]=euler++;
  anc[node][0]=parent;
  for(int k=1;k<20;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  depth[node]=depth[parent]+1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs_init(child,node);
  }
  who[euler]=node;
  post[node]=euler++;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=20-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=20-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int freq[2][100005];
int64_t total=0;
int64_t ans[100005];

void toggle(int node){
  //printf("toggle(%d)\n",node+1);
  if(has[node]){
    total-=freq[gs[node]^1][fs[node]];
    freq[gs[node]][fs[node]]--;
  }else{
    freq[gs[node]][fs[node]]++;
    total+=freq[gs[node]^1][fs[node]];
  }
  has[node]^=1;
}

struct Query{
  int l,r,x,id;
  Query(int l,int r,int x,int id):l(l),r(r),x(x),id(id){
  }
  bool operator<(Query q)const{
    if(l/BLOCK!=q.l/BLOCK) return l/BLOCK<q.l/BLOCK;
    return (r<q.r)^((l/BLOCK)&1);
  }
};

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&gs[i]);
  }
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    scanf("%d",&fs[i]);
    cps[fs[i]];
  }
  int last=0;
  for(auto& it:cps){
    it.second=last++;
  }
  for(int i=0;i<N;i++){
    fs[i]=cps[fs[i]];
  }
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs_init(0,0);
  int Q;
  scanf("%d",&Q);
  std::vector<Query> qs;
  for(int i=0;i<Q;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    if(pre[A]>pre[B]) std::swap(A,B);
    int C=lca(A,B);
    if(post[A]>=post[B]){
      qs.emplace_back(pre[A],pre[B],-1,i);
    }else{
      qs.emplace_back(post[A],pre[B],C,i);
    }
  }
  std::sort(qs.begin(),qs.end());
  int l=0,r=-1;
  for(int i=0;i<Q;i++){
    while(r<qs[i].r) toggle(who[++r]);
    while(l>qs[i].l) toggle(who[--l]);
    while(r>qs[i].r) toggle(who[r--]);
    while(l<qs[i].l) toggle(who[l++]);
    
    if(qs[i].x!=-1) toggle(qs[i].x);
    ans[qs[i].id]=total;
    if(qs[i].x!=-1) toggle(qs[i].x);
  }
  for(int i=0;i<Q;i++){
    printf("%I64d\n",ans[i]);
  }
  return 0;
}