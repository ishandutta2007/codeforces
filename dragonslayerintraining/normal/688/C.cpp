#include <cstdio>
#include <vector>
#include <cstdlib>

std::vector<int> adj[100000];

int color[100000];
int cnt[3];

void dfs(int node,int c){
  if(color[node]){
    if(color[node]!=c){
      printf("-1\n");
      exit(0);
    }
    return;
  }
  color[node]=c;
  cnt[c]++;
  for(int other:adj[node]){
    dfs(other,c^3);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    if(!color[i]){
      dfs(i,1);
    }
  }
  printf("%d\n",cnt[1]);
  bool first=true;
  for(int i=0;i<N;i++){
    if(color[i]==1){
      if(first){
	first=false;
      }else{
	printf(" ");
      }
      printf("%d",i+1);
    }
  }
  printf("\n");
  printf("%d\n",cnt[2]);
  first=true;
  for(int i=0;i<N;i++){
    if(color[i]==2){
      if(first){
	first=false;
      }else{
	printf(" ");
      }
      printf("%d",i+1);
    }
  }
  printf("\n");
  return 0;
}