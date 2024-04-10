#include <cstdio>
#include <vector>
#include <cstdlib>

std::vector<int> edges[200000];

int vis[200000];

bool tie=false;
std::vector<int> stk;

//even -> Petya
//odd -> Vasya
void dfs(int node){
  if(vis[node]==2){
    return;
  }else if(vis[node]==1){
    tie=true;
    return;
  }
  vis[node]=1;
  stk.push_back(node);
  if(edges[node].empty()){
    //dead end
    if(node%2){
      printf("Win\n");
      for(int i=0;i<stk.size();i++){
	if(i>0) printf(" ");
	printf("%d",stk[i]/2+1);
      }
      printf("\n");
      exit(0);
    }
  }else{ 
    for(int child:edges[node]){
      dfs(child);
    }
  }
  stk.pop_back();
  vis[node]=2;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);  
  for(int i=0;i<N;i++){
    int C;
    scanf("%d",&C);
    while(C-->0){
      int A;
      scanf("%d",&A);
      A--;
      edges[i*2].push_back(A*2+1);
      edges[i*2+1].push_back(A*2);
    }
  }
  int S;
  scanf("%d",&S);
  S--;
  dfs(S*2);
  if(tie){
    printf("Draw\n");
  }else{
    printf("Lose\n");
  }
  return 0;
}