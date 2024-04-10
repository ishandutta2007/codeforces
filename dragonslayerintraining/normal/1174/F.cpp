#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

std::vector<int> edges[200005];

int size[200005];
int pre[200005];
int euler=0;
int head[200005];
int tail[200005];
int who[200005];

void dfs_size(int node){
  size[node]=1;
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    dfs_size(child);
    size[node]+=size[child];
  }
}

void dfs_hld(int node){
  for(int& child:edges[node]){
    if(size[child]>size[edges[node][0]]){
      std::swap(child,edges[node][0]);
    }
  }
  tail[head[node]]=node;
  pre[node]=euler;
  who[euler]=node;
  euler++;
  for(int child:edges[node]){
    head[child]=(child==edges[node][0])?head[node]:child;
    dfs_hld(child);
  }
}

int query_dist(int x){
  printf("d %d\n",x+1);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

int query_second(int x){
  printf("s %d\n",x+1);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res-1;
}

void answer(int x){
  printf("! %d\n",x+1);
  exit(0);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_size(0);
  dfs_hld(0);
  int curr=0;
  int head_dist=query_dist(curr);
  while(head_dist>0){
    int len=pre[tail[curr]]-pre[curr];
    int tail_dist=query_dist(tail[curr]);
    int mid=who[pre[curr]+(len+head_dist-tail_dist)/2];
    int excess=(head_dist+tail_dist-len)/2;
    if(excess==0){
      answer(mid);
    }
    curr=query_second(mid);
    head_dist=excess-1;
  }
  answer(curr);
  return 0;
}