#include <cstdio>
#include <vector>

int ans=0;
std::vector<int> edges[100000];
int size[100000];

void dfs(int node,int parent){
  size[node]=1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    size[node]+=size[child];
  }
  if(size[node]%2==0){
    ans++;
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
  if(N%2==1){
    printf("-1\n");
    return 0;
  }
  dfs(0,0);
  printf("%d\n",ans-1);
  return 0;
}