#include <cstdio>
#include <vector>
#include <tuple>
#include <cassert>
#include <stdint.h>

std::vector<std::tuple<int,int,int64_t> > edges;

std::vector<std::pair<int,int64_t> > conn[1000000];

int64_t low[1000000];
int pre[1000000];
int pre_max=1;
int cmpt[1000000];
int64_t cmpt_score[1000000];
int cmpt_max=0;

std::vector<int> stk;

void dfs_scc(int node,int parent){
  if(pre[node]!=0){
    return;
  }
  pre[node]=pre_max++;
  low[node]=pre[node];
  stk.push_back(node);
  for(std::pair<int,int> edge:conn[node]){
    dfs_scc(edge.first,node);
    low[node]=std::min(low[node],low[edge.first]);
  }
  if(low[node]==pre[node]){
    while(stk.back()!=node){
      cmpt[stk.back()]=cmpt_max;
      low[stk.back()]=1e9;
      stk.pop_back();
    }
    cmpt[stk.back()]=cmpt_max;
    low[stk.back()]=1e9;
    stk.pop_back();
    cmpt_max++;
  }
}

int64_t edge_score(int W){
  int64_t low=0,high=20000;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*(mid+1)/2>W){
      high=mid;
    }else{
      low=mid;
    }
  }
  return (low+1)*W-low*(low+1)*(low+2)/6;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,W;
    scanf("%d %d %d",&A,&B,&W);
    A--,B--;
    conn[A].emplace_back(B,W);
    edges.emplace_back(A,B,W);
  }
  int S;
  scanf("%d",&S);
  S--;
  for(int i=0;i<N;i++){
    dfs_scc(i,i);
    assert(stk.empty());
  }
  /*
  for(int i=0;i<N;i++){
    printf("cmpt[%d] %d\n",i,cmpt[i]);
  }
  */
  //Compress SCCs
  for(int i=0;i<N;i++){
    conn[i].clear();
  }
  for(std::tuple<int,int,int> e:edges){
    int A=cmpt[std::get<0>(e)];
    int B=cmpt[std::get<1>(e)];
    int W=std::get<2>(e);
    if(A!=B){
      //printf("%d --> %d\n",A,B);
      conn[A].emplace_back(B,W);
    }else{
      //printf("%d -^> %d\n",A,B);
      cmpt_score[A]+=edge_score(W);
    }
  }
  /*
  for(int i=0;i<cmpt_max;i++){
    printf("cmpt_score[%d] %d\n",i,cmpt_score[i]);
  }
  */
  //SCCs are in reverse topological order
  int64_t* max=low;
  for(int i=0;i<cmpt_max;i++){
    max[i]=cmpt_score[i];
  }
  for(int i=0;i<cmpt_max;i++){
    for(std::pair<int,int> e:conn[i]){
      assert(e.first<i);
      max[i]=std::max(max[i],max[e.first]+e.second+cmpt_score[i]);
    }
  }
  printf("%I64d\n",max[cmpt[S]]);
  return 0;
}