#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=3005;
//i_am_noob
int n,u,v,Size[maxn],fa[maxn],Next[maxn][maxn];
ll dp[maxn][maxn],p,x,y,cnt,ans=0;
vector<int> adj[maxn];
vector<pii> vec[maxn];

void dfs(int u, int x, int y, int z){
	if(u!=y&&x==y) Next[y][u]=u;
	else Next[y][u]=Next[y][x];
	if(z>0) vec[z].pb(mp(y,u));
	rep(sz(adj[u])){
		int v=adj[u][i];
		if(v!=x) dfs(v,u,y,z+1);
	}
}

void dfs2(int u, int x){
	Size[u]=1;
	fa[u]=x;
	rep(sz(adj[u])){
		int v=adj[u][i];
		if(v!=x){
			dfs2(v,u);
			Size[u]+=Size[v];
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n-1){
		cin >> u >> v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(n) dfs(i,-1,i,0);
	dfs2(0,-1);
	rep3(i,n,1) rep1(j,sz(vec[i])){
		u=vec[i][j].first,v=vec[i][j].second;
		dp[u][v]=0;
		if(sz(adj[u])==1&&sz(adj[v])==1) continue;
		if(fa[u]==Next[u][v]) x=Size[u];
		else x=n-Size[Next[u][v]];
		if(fa[v]==Next[v][u]) y=Size[v];
		else y=n-Size[Next[v][u]];
		rep1(k,sz(adj[u])) if(adj[u][k]!=Next[u][v]){
			p=adj[u][k];
			if(fa[p]==u) cnt=Size[p];
			else cnt=n-Size[u];
			dp[u][v]=max(dp[u][v],dp[p][v]+cnt*y);
		}
		rep1(k,sz(adj[v])) if(adj[v][k]!=Next[v][u]){
			p=adj[v][k];
			if(fa[p]==v) cnt=Size[p];
			else cnt=n-Size[v];
			dp[u][v]=max(dp[u][v],dp[u][p]+x*cnt);
		}
	}
	rep2(i,1,n) ans=max(ans,dp[i][fa[i]]+Size[i]*(n-Size[i]));
	//rep(n) rep2(j,i+1,n) print3(i,j,dp[i][j]);
	print1(ans);
	return 0;
}