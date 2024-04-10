#include<bits/stdc++.h>
using namespace std;
const int N=300+5;
const int mod=998244353;
int dp0[N][N],dp1[N][N],dep[N];
int t0[N],t1[N];
int n,r;
vector<int> g[N];
void dfs(int u,int fa){
	dep[u]=0;
	dp0[u][0]=1;
	dp1[u][0]=1;
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
		memset(t0,0,sizeof(t0));
		memset(t1,0,sizeof(t1));
		for(int i=0;i<=dep[u];i++){
			for(int j=0;j<=dep[v];j++){
				t0[max(i,j+1)]=(t0[max(i,j+1)]+1ll*dp0[u][i]*dp0[v][j])%mod;
				if(i+j+1<=r) t1[j+1]=(t1[j+1]+1ll*dp0[u][i]*dp1[v][j])%mod;
				else t0[i]=(t0[i]+1ll*dp0[u][i]*dp1[v][j])%mod;
				t1[min(i,j+1)]=(t1[min(i,j+1)]+1ll*dp1[u][i]*dp1[v][j])%mod;
				if(i+j+1<=r) t1[i]=(t1[i]+1ll*dp1[u][i]*dp0[v][j])%mod;
				else t0[j+1]=(t0[j+1]+1ll*dp1[u][i]*dp0[v][j])%mod;
			}
		}
		dep[u]=max(dep[u],dep[v]+1);
		memcpy(dp0[u],t0,sizeof(t0));
		memcpy(dp1[u],t1,sizeof(t1));
	}
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=0;
	for(r=1;r<n;r++){
		memset(dp0,0,sizeof(dp0));
		memset(dp1,0,sizeof(dp1));
		dfs(1,0);
		for(j=0;j<=n;j++) ans=(ans+dp0[1][j])%mod;
	}
	for(i=1;i<=n;i++) ans=1ll*ans*(mod+1>>1)%mod;
	cout<<ans;
	return 0;
}