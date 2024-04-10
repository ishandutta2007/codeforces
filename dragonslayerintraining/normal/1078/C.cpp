#include <cstdio>
#include <stdint.h>
#include <vector>

const int64_t MOD=998244353;
const int64_t INV2=(MOD+1)/2;

std::vector<int64_t> edges[300005];

//0: single
//1: unmatched
//2: matched
//parent, child, result
int merge[3][3][3]={{{1,0,0},{0,0,0},{1,0,0}},
		    {{0,1,0},{0,0,1},{0,2,0}},
		    {{0,0,1},{0,0,0},{0,0,2}}};


int64_t dp[300005][3];
int64_t tmp[3];

void dfs(int64_t node,int64_t parent){
  dp[node][0]=1;
  dp[node][1]=1;
  for(int64_t child:edges[node]){
    if(parent==child) continue;
    dfs(child,node);
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	for(int k=0;k<3;k++){
	  tmp[k]=(tmp[k]+merge[i][j][k]*dp[node][i]*dp[child][j])%MOD;
	}
      }
    }
    for(int k=0;k<3;k++){
      dp[node][k]=tmp[k];
      tmp[k]=0;
    }
  }
  //printf("dp[%I64d]={%I64d,%I64d}\n",node,dp[node][0],dp[node][1]);
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs(0,-1);
  printf("%I64d\n",(dp[0][0]+dp[0][2])%MOD);
  return 0;
}