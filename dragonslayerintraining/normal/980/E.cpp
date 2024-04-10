#include <cstdio>
#include <vector>

std::vector<int> edges[1000000];

int anc[20][1000000];

bool have[1000000];

void dfs(int node,int parent){
  anc[0][node]=parent;
  for(int k=1;k<20;k++){
    anc[k][node]=anc[k-1][anc[k-1][node]];
  }
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
  }
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B); 
    edges[B].push_back(A);
  }
  dfs(N-1,N-1);
  have[N-1]=true;
  int keep=N-K-1;
  for(int i=N-2;i>=0;i--){
    if(have[i]) continue;
    int node=i;
    int cost=1;
    for(int k=20-1;k>=0;k--){
      if(!have[anc[k][node]]){
	cost+=(1<<k);
	node=anc[k][node];
      }
    }
    if(cost<=keep){
      keep-=cost;
      for(int node=i;!have[node];node=anc[0][node]){
	have[node]=true;
      }
    }
  }
  std::vector<int> vs;
  for(int i=0;i<N;i++){
    if(!have[i]){
      vs.push_back(i+1);
    }
  }
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%d",vs[i]);
  }
  printf("\n");
  return 0;
}