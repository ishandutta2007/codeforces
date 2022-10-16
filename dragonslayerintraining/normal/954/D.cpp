#include <cstdio>
#include <queue>
#include <vector>

std::vector<int> edges[1000];

int adj[1000][1000];

int from[1000];
int to[1000];
int N;

void bfs(int* dist,int start){
  std::fill(dist,dist+N,-1);
  std::queue<int> curr,next;
  int layer=0;
  curr.push(start);
  while(!curr.empty()){
    while(!curr.empty()){
      int node=curr.front();
      curr.pop();
      if(dist[node]!=-1) continue;
      dist[node]=layer;
      for(int other:edges[node]){
	next.push(other);
      }
    }
    std::swap(curr,next);
    layer++;
  }
}

int main(){
  int M,S,T;
  scanf("%d %d %d %d",&N,&M,&S,&T);
  S--,T--;
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U][V]=adj[V][U]=1;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  bfs(from,S);
  bfs(to,T);
  /*
  for(int i=0;i<N;i++){
    printf("%d: %d %d\n",i,from[i],to[i]);
  }
  */
  int old=from[T];
  int cnt=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(!adj[i][j]){
	if(std::min(from[i]+to[j]+1,from[j]+to[i]+1)>=old){
	  cnt++;
	}
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}