#include <cstdio>
#include <vector>

std::vector<int> adj[100005];
int last[100005];

int color[100005];
int min=1;

void dfs(int node,int parent){
  for(int child:adj[node]){
    if(child==parent) continue;
    color[child]=color[node]^1;
    dfs(child,node);
  }
  if(adj[node].size()==1&&color[node]){
    min=3;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<N;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  for(int i=1;i<=N;i++){
    if(adj[i].size()==1){
      last[adj[i][0]]=i;
    }
  }
  int max=N-1;
  for(int i=1;i<=N;i++){
    if(adj[i].size()==1&&last[adj[i][0]]!=i){
      max--;
    }
  }
  for(int i=1;i<=N;i++){
    if(adj[i].size()==1){
      dfs(i,-1);
      break;
    }
  }
  printf("%d %d\n",min,max);
}