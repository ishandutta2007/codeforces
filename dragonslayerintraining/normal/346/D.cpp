#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> edges[1000000];
int out[1000000];
bool vis[1000000];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[V].push_back(U);
    out[U]++;
  }
  int S,T;
  scanf("%d %d",&S,&T);
  S--,T--;
  std::queue<int> curr,next;
  curr.push(T);
  for(int dist=0;!curr.empty();std::swap(curr,next),dist++){
    while(!curr.empty()){
      int node=curr.front();
      curr.pop();
      if(node==S){
	printf("%d\n",dist);
	return 0;
      }
      if(vis[node]) continue;
      vis[node]=true;
      for(int other:edges[node]){
	if(--out[other]==0){
	  curr.push(other);
	}else{
	  next.push(other);
	}
      }
    }
  }
  printf("-1\n");
  return 0;
}