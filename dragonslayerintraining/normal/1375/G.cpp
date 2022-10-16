#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[200005];

int color[200005];

void dfs(int x,int par){
  for(int y:edges[x]){
    if(y==par) continue;
    color[y]=color[x]^1;
    dfs(y,x);
  }
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
  dfs(0,0);
  int red=std::count(color,color+N,1);
  printf("%d\n",std::min(red-1,N-1-red));
}