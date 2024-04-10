#include <cstdio>
#include <vector>

std::vector<int> conn[100000];
int N;

double dfs(int node,int parent){
  int cnt=0;
  double total=0;
  for(int child:conn[node]){
    if(child!=parent){
      cnt++;
      total+=dfs(child,node);
    }
  }
  return 1+(cnt?(total/cnt):0);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<N;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    conn[U].push_back(V);
    conn[V].push_back(U);
  }
  printf("%.10f\n",dfs(0,0)-1);
  return 0;
}