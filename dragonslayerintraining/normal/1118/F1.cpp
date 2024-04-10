#include <cstdio>
#include <vector>

const int MOD=998244353;

int color[300005];
std::vector<int> bycolor[300005];

std::vector<int> edges[300005];
int anc[20][300005];
int depth[300005];
int dp[300005][2];

void dfs_init(int node){
  for(int k=1;k<20;k++){
    anc[k][node]=anc[k-1][anc[k-1][node]];
  }
  for(int child:edges[node]){
    if(child==anc[0][node]) continue;
    anc[0][child]=node;
    depth[child]=depth[node]+1;
    dfs_init(child);
  }
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=20-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[k][a];
    }
  }
  if(a==b) return a;
  for(int k=20-1;k>=0;k--){
    if(anc[k][a]!=anc[k][b]){
      a=anc[k][a];
      b=anc[k][b];
    }
  }
  return anc[0][a];
}

void dfs_calc(int node){
  if(color[node]){
    dp[node][0]=0;
    dp[node][1]=1;
    return;
  }
  color[node]=-1;
  dp[node][0]=1;
  dp[node][1]=0;
  //printf("dp[%d]={%d,%d}\n",node+1,dp[node][0],dp[node][1]);
  for(int child:edges[node]){
    if(color[child]==-1) continue;
    dfs_calc(child);
    int psum=dp[node][0]+dp[node][1];
    //printf("absorb %d\n",child+1);
    int csum=dp[child][0]+dp[child][1];
    dp[node][1]=(1LL*psum*csum+1LL*(MOD-dp[node][0])*dp[child][0])%MOD;
    dp[node][0]=1LL*dp[node][0]*csum%MOD;
    //printf("dp[%d]={%d,%d}\n",node+1,dp[node][0],dp[node][1]);
  }
}

int main(){
  int N,K=2;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&color[i]);
    bycolor[color[i]].push_back(i);
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_init(0);
  for(int c=1;c<=K;c++){
    int root=bycolor[c][0];
    for(int i:bycolor[c]){
      root=lca(root,i);
    }
    //printf("color %d LCA %d\n",c,root+1);
    if(color[root]!=0&&color[root]!=c){
      printf("0\n");
      return 0;
    }
    color[root]=c;
    for(int i:bycolor[c]){
      if(i==root) continue;
      int x=anc[0][i];
      while(color[x]!=c){
	if(color[x]!=0){
	  printf("0\n");
	  return 0;
	}
	color[x]=c;
	x=anc[0][x];
      }
    }
  }
  /*
  for(int i=0;i<N;i++){
    printf("%d ",color[i]);
  }
  printf("\n");
  */
  int ans=1;
  for(int i=0;i<N;i++){
    if(color[i]) continue;
    dfs_calc(i);
    //printf("component of %d: x%d\n",i+1,dp[i][1]);
    ans=1LL*ans*dp[i][1]%MOD;
  }
  printf("%d\n",ans);
  return 0;
}