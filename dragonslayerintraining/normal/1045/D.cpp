#include <cstdio>
#include <vector>

std::vector<int> edges[100005];
int par[100005];
double sum_children[100005];
double survive[100005];
double ev,ee;

void dfs(int node){
  for(int child:edges[node]){
    if(child==par[node]) continue;
    par[child]=node;
    dfs(child);
  }
}
  

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    double P;
    scanf("%lf",&P);
    survive[i]=1-P;
  }
  for(int i=1;i<N;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A++,B++;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  edges[0].push_back(1);
  dfs(0);
  for(int i=1;i<=N;i++){
    ev+=survive[i];
  }
  for(int i=2;i<=N;i++){
    ee+=survive[i]*survive[par[i]];
    sum_children[par[i]]+=survive[i];
  }
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int i;
    double P;
    scanf("%d %lf",&i,&P);
    i++;
    ev-=survive[i];
    ee-=survive[i]*(survive[par[i]]+sum_children[i]);
    sum_children[par[i]]-=survive[i];
    survive[i]=1-P;
    sum_children[par[i]]+=survive[i];
    ee+=survive[i]*(survive[par[i]]+sum_children[i]);
    ev+=survive[i];
    printf("%.10lf\n",ev-ee);
  }
  return 0;
}