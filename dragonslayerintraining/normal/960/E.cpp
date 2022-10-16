#include <cstdio>
#include <vector>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t vs[200000];

std::vector<int64_t> edges[200000];

int64_t size[2][200000];
int64_t depth[200000];

void dfs_size(int64_t node,int64_t parent,int64_t d){
  size[0][node]=1;
  size[1][node]=0;
  depth[node]=d;
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dfs_size(child,node,d+1);
    size[0][node]=(size[0][node]+size[1][child])%MOD;
    size[1][node]=(size[1][node]+size[0][child])%MOD;
  }
  //printf("size[%I64d]=%I64d,%I64d\n",node+1,size[0][node],size[1][node]);
}

int64_t total=0;

void dfs_calc(int64_t node,int64_t parent){
  int64_t sumsq[2]={1,0};
  int64_t sum[2]={1,0};
  sumsq[0]=1;
  sum[0]=1;
  sumsq[1]=0;
  sum[1]=0;
  
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dfs_calc(child,node);
    sum[0]=(sum[0]+size[1][child])%MOD;
    sum[1]=(sum[1]+size[0][child])%MOD;
    sumsq[0]=(sumsq[0]+size[1][child]*size[1][child])%MOD;
    sumsq[1]=(sumsq[1]+size[0][child]*size[0][child])%MOD;
  }
  if(parent!=node){
    int64_t up[2]={(size[(depth[node]+1)%2][0]-size[1][node]),(size[depth[node]%2][0]-size[0][node])};
    //printf("up[%I64d]=%I64d,%I64d\n",node,up[0],up[1]);
    sum[0]=(sum[0]+up[1])%MOD;
    sum[1]=(sum[1]+up[0])%MOD;
    sumsq[0]=(sumsq[0]+up[1]*up[1])%MOD;
    sumsq[1]=(sumsq[1]+up[0]*up[0])%MOD;
  }
  //printf("+[%I64d]=SUM%I64d SUMSQ%I64d CNT%I64d VAL%I64d COST%I64d\n",node+1,sum[0],sumsq[0],(sum[0]*sum[0]-sumsq[0]+MOD)%MOD,vs[node],(sum[0]*sum[0]-sumsq[0]+MOD)%MOD*vs[node]%MOD);
  //printf("-[%I64d]=SUM%I64d SUMSQ%I64d CNT%I64d VAL%I64d COST%I64d\n",node+1,sum[1],sumsq[1],(sum[1]*sum[1]-sumsq[1]+MOD)%MOD,vs[node],(sum[1]*sum[1]-sumsq[1]+MOD)%MOD*vs[node]%MOD);
  total=(total+(sum[0]*sum[0]-sumsq[0]+MOD)%MOD*vs[node]%MOD+MOD)%MOD;
  total=(total-(sum[1]*sum[1]-sumsq[1]+MOD)%MOD*vs[node]%MOD+MOD)%MOD;
}



int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&vs[i]);
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_size(0,0,0);
  dfs_calc(0,0);
  for(int64_t i=0;i<N;i++){
    int64_t val=(vs[i]>0)?vs[i]:((MOD-((-vs[i])%MOD))%MOD);
    total=(total+val)%MOD;
  }
  printf("%I64d\n",total);
  return 0;
}