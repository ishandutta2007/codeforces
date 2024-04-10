#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6;
int l[N],r[N]; ll dp[N][2]; vector<int> G[N];
ll aabs(ll x){ return x>=0?x:-x; }
void dfs(int u,int f){
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f){
			dfs(v,u);
			dp[u][0]+=max(dp[v][0]+aabs(l[u]-l[v]),dp[v][1]+aabs(l[u]-r[v]));
			dp[u][1]+=max(dp[v][0]+aabs(r[u]-l[v]),dp[v][1]+aabs(r[u]-r[v]));
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
		rep(i,1,n) G[i].clear(),dp[i][0]=dp[i][1]=0;
		rep(i,1,n-1){
			int u,v; scanf("%d%d",&u,&v);
			G[u].pb(v),G[v].pb(u);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}