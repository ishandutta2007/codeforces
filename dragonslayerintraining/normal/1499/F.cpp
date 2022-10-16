#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD=998244353;

int N,K;

std::vector<int> adj[100005];
int height[100005];

int mem[25000005];
int* dp[100005];
int* euler=mem;

int tmp[100005];

void addmod(int& x,long long y){
  x=(x+y)%MOD;
}

void dfs_height(int x){
  height[x]=1;
  for(int y:adj[x]){
    adj[y].erase(std::find(adj[y].begin(),adj[y].end(),x));
    dfs_height(y);
    height[x]=std::max(height[x],height[y]+1);
  }
  for(int& y:adj[x]){
    if(height[y]>height[adj[x][0]]){
      std::swap(y,adj[x][0]);
    }
  }
}

void dfs_pre(int x){
  dp[x]=euler++;
  for(int y:adj[x]){
    dfs_pre(y);
  }
}

void dfs_solve(int x){
  if(adj[x].empty()){
    dp[x][0]=1;
    return;
  }
  for(int y:adj[x]){
    dfs_solve(y);
    if(y==adj[x][0]){
      for(int j=0;j<std::min(K+1,height[y]);j++){
	addmod(dp[x][0],dp[y][j]);
      }
    }else{
      std::fill(tmp,tmp+height[x],0);
      for(int i=0;i<height[x];i++){
	int s=0;
	for(int j=0;j<std::min(height[y],std::min(K-i,i));j++){
	  addmod(s,dp[y][j]);
	}
	addmod(tmp[i],1LL*dp[x][i]*s);
      }
      for(int j=0;j<height[y];j++){
	int s=0;
	for(int i=0;i<std::min(height[x],std::min(K-j,j+1));i++){
	  addmod(s,dp[x][i]);
	}
	addmod(tmp[j+1],1LL*s*dp[y][j]);
      }
      int s=0;
      for(int j=0;j<std::min(K+1,height[y]);j++){
	addmod(s,dp[y][j]);
      }
      for(int i=0;i<std::min(K+1,height[x]);i++){
	addmod(tmp[i],1LL*dp[x][i]*s);
      }
      for(int i=0;i<height[x];i++){
	dp[x][i]=tmp[i];
      }
    }
  }
  /*
  printf("dp[%d]:",x+1);
  for(int i=0;i<height[x];i++){
    printf(" %d",dp[x][i]);
  }
  printf("\n");
  */
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  dfs_height(0);
  dfs_pre(0);
  dfs_solve(0);
  int ans=0;
  for(int i=0;i<std::min(K+1,height[0]);i++){
    addmod(ans,dp[0][i]);
  }
  printf("%d\n",ans);
}