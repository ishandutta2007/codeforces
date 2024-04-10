#include <cstdio>
#include <vector>
#include <stdint.h>

int N;
std::vector<int> edges[200005];

int64_t color[2];
int64_t size[200005];
int64_t len[200005];

int64_t total=0;

void dfs(int node,int parent,int c){
  size[node]=1;
  len[node]=0;
  color[c]++;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node,c^1);
    total+=size[node]*len[child]+size[child]*len[node];
    size[node]+=size[child];
    len[node]+=len[child];
  }
  len[node]+=size[node];
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
  dfs(0,0,0);
  printf("%I64d\n",(total+color[0]*color[1])/2);
  return 0;
}