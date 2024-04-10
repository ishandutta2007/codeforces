#include <cstdio>
#include <vector>

int color[300000];
std::vector<int> edges[300000];

void dfs(int node,int parent,int c){
  if(color[node]!=0){
    return;
  }
  color[node]=c;
  int diff=0;
  for(int child:edges[node]){
    dfs(child,node,c^3);
    diff+=(color[child]==color[node]);
  }
  if(diff==2){
    color[node]^=3;
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    dfs(i,i,1);
  }
  for(int i=0;i<N;i++){
    printf("%c",'0'+(color[i]==2));
  }
  printf("\n");
  return 0;
}