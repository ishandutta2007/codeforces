#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[200005];

bool good[200005];
int memo[200005];

void connect(int node,int s){
  if(memo[node]>=s) return;
  memo[node]=s;
  //printf("CONNECT %d (level %d)\n",node+1,s);
  if(s>0){
    for(int adj:edges[node]){
      connect(adj,s-1);
    }
  }
  good[node]=true;
}

int ans=0;

void dfs(int node,int parent){
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
  }
  if(!good[node]){
    connect(parent,1);
    ans++;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  std::fill(memo,memo+N,-1);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  connect(0,2);
  dfs(0,0);
  printf("%d\n",ans);
  return 0;
}