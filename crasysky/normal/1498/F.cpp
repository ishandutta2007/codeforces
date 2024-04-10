#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pb push_back
#define ll long long
using namespace std;
const int N=1e5+5,K=30; 
int d,a[N],dp[N][K][2],dp2[N][K][2]; vector<int> G[N];
void dfs1(int u,int f){
	dp[u][0][0]=a[u];
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v==f) continue;
		dfs1(v,u); 
		rep(j,0,d-2)
			dp[u][j+1][0]^=dp[v][j][0],dp[u][j+1][1]^=dp[v][j][1];
		dp[u][0][1]^=dp[v][d-1][0],dp[u][0][0]^=dp[v][d-1][1];
	}
}
void dfs2(int u,int f){
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v==f) continue;
		if (d>1){
			rep(j,1,d-2)
				rep(t,0,1)
					dp2[v][j+1][t]=dp2[u][j][t]^dp[u][j][t]^dp[v][j-1][t];
			rep(t,0,1){
				dp2[v][1][t]=dp2[u][0][t]^dp[u][0][t]^dp[v][d-1][t^1];
				dp2[v][0][t]=dp2[u][d-1][t^1]^dp[u][d-1][t^1]^dp[v][d-2][t^1];
			}
		}
		else{
			rep(t,0,1) dp2[v][0][t]=dp2[u][0][t^1]^dp[u][0][t^1]^dp[v][0][t];
		}
		dfs2(v,u);
	}
}
int main(){
	int n; scanf("%d%d",&n,&d);
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	rep(i,1,n) scanf("%d",&a[i]);
	dfs1(1,0),dfs2(1,0);
	rep(i,1,n){
		int s=0; rep(j,0,d-1) s^=dp[i][j][1]^dp2[i][j][1];
		printf("%d ",s?1:0);
	}
	return 0;
}