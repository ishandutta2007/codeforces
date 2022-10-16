#include <cstdio>
#include <vector>
#include <stdint.h>

const int MOD=1e9+7;

void addmod(int& x,int64_t y){x=(x+y)%MOD;}

std::vector<int> edges[100005];

int dp[100005][205];
int size[100005];
int tmp[205];

int cs[205][205];
int N,K;
int rem[205];

void dfs(int node,int parent){
  size[node]=1;
  dp[node][0]=2;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    for(int psize=0;psize<=std::min(K,size[node]);psize++){
      for(int csize=0;csize<=std::min(K,size[child]);csize++){
	if(psize+csize<=K){
	  addmod(tmp[psize+csize],1LL*dp[node][psize]*dp[child][csize]);
	}
	if(psize+csize+1<=K){
	  addmod(tmp[psize+csize+1],1LL*dp[node][psize]*(dp[child][csize]+MOD-(csize==0)));
	}
      }
    }
    for(int csize=0;csize<=std::min(K,size[child]);csize++){
      addmod(rem[csize+1],dp[child][csize]+MOD-(csize==0));
    }
    size[node]+=size[child];
    for(int k=0;k<=K;k++){
      dp[node][k]=tmp[k];
      tmp[k]=0;
    }
  }
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  cs[0][0]=1;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      cs[i][j]=1LL*j*(cs[i-1][j]+cs[i-1][j-1])%MOD;
      //printf("cs[%d][%d]=%d\n",i,j,cs[i][j]);
    }
  }
  dfs(0,0);
  /*
  for(int i=0;i<N;i++){
    for(int s=0;s<=K;s++){
      printf("dp[%d][%d]=%d\n",i+1,s,dp[i][s]);
    }
  }
  */
  int ans=0;
  for(int s=0;s<=K;s++){
    addmod(ans,1LL*(dp[0][s]+MOD-rem[s])*cs[K][s]);
  }
  printf("%d\n",ans);
  return 0;
}