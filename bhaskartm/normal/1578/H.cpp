#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
 
const int inf=1000000010;
const ll INF=100000000000000100LL;
const int mod=1000000007;
const int MAXN=300010, LOG=19;
 
int n, m, mm, k, u, v, x, y, t, a, b;
int U[MAXN], V[MAXN], W[MAXN], ans[MAXN];
int deg[MAXN], parr[MAXN][3], mark[MAXN];
vector<int> G[MAXN][3], E[MAXN];
vector<pii> G2[MAXN];
 
inline void orient(int i, int u){
	if (u==U[i]){
		ans[i]=1;
		deg[U[i]]-=W[i];
		deg[V[i]]+=W[i];
	}
	else{
		ans[i]=2;
		deg[U[i]]+=W[i];
		deg[V[i]]-=W[i];
	}
}
 
void MergePath(int i, int w){
	mm++;
	int v=i;
	while (1){
		while (SZ(G[v][w]) && mark[G[v][w].back()]) G[v][w].pop_back();
		if (G[v][w].empty()) break ;
		int i=G[v][w].back();
		assert(!mark[i]);
		mark[i]=1;
		E[mm].pb(i);
		int u=(U[i]^V[i]^v);
		parr[u][w]^=1;
		parr[v][w]^=1;
		v=u;
	}
	if (E[mm].empty()){
		mm--;
		return ;
	}
	G2[i].pb({v, mm});
	G2[v].pb({i, -mm});
}
void dfs(int v){
	while (SZ(G2[v]) && mark[abs(G2[v].back().second)]) G2[v].pop_back();
	if (G2[v].empty()) return ;
	int u=G2[v].back().first, id=G2[v].back().second;
	if (id<0){
		id*=-1;
		reverse(all(E[id]));
	}
	mark[id]=1;
	for (int i:E[id]){
		orient(i, v);
		v^=V[i]^U[i];
	}
	assert(v==u);
	dfs(u);
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>U[i]>>V[i]>>W[i];
		parr[U[i]][W[i]]^=1;
		parr[V[i]][W[i]]^=1;
		G[U[i]][W[i]].pb(i);
		G[V[i]][W[i]].pb(i);
	}
	int sum=0;
	for (int i=1; i<=n; i++) sum+=parr[i][1];
	for (int i=1; i<=n; i++) for (int w:{1, 2}) if (parr[i][w]) MergePath(i, w);
	for (int i=1; i<=n; i++) for (int w:{1, 2}) MergePath(i, w);
 
	for (int i=0; i<m; i++){
		assert(mark[i]);
		mark[i]=0;
	}
	for (int i=1; i<=n; i++) if (SZ(G2[i])&1) dfs(i);
	for (int i=1; i<=n; i++) dfs(i);
 
	cout<<sum<<"\n";
	for (int i=0; i<m; i++) cout<<ans[i]; cout<<"\n";
 
	return 0;
}