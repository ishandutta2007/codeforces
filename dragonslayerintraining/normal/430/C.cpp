#include <cstdio>
#include <vector>

int delta[100000];

std::vector<int> edges[100000];
std::vector<int> moves;

void dfs(int node,int parent,int flip,int flipc){
  if(delta[node]^flip){
    flip^=1;
    moves.push_back(node);
  }
  for(int child:edges[node]){
    if(child!=parent){
      dfs(child,node,flipc,flip);
    }
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
  for(int i=0;i<N;i++){
    int init;
    scanf("%d",&init);
    delta[i]=init;
  }
  for(int i=0;i<N;i++){
    int goal;
    scanf("%d",&goal);
    delta[i]^=goal;
  }
  dfs(0,0,0,0);
  printf("%d\n",(int)moves.size());
  for(int move:moves){
    printf("%d\n",move+1);
  }
  return 0;
}