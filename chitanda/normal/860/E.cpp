#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 500005;
int n;
int p[maxn];
vector<int> g[maxn];
vector<int> f[maxn];
int dep[maxn];
int fa[maxn][20];
ll L[maxn], R[maxn], ans[maxn];
int vis[maxn], ed[maxn], tot, ce[maxn];

void dfs(int t){
	vis[t] = ++tot;
	dep[t] = dep[p[t]] + 1;
	fa[t][0] = p[t];
	for(int i = 1; fa[t][i - 1]; ++i)
		fa[t][i] = fa[fa[t][i - 1]][i - 1];
	f[dep[t]].pb(t);
	for(int v : g[t]) dfs(v);
	ed[t] = tot;
}

inline int lca(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	int dis = dep[v] - dep[u];
	for(int i = 18; i >= 0; --i)
		(dis >> i & 1) && (v = fa[v][i]);
	if(u == v) return u;
	for(int i = 18; i >= 0; --i)
		(fa[u][i] != fa[v][i]) && (u = fa[u][i], v = fa[v][i]);
	return fa[u][0];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", p + i);
		g[p[i]].pb(i);
	}
	dfs(g[0][0]);
	for(int i = 1; f[i].size(); ++i){
		for(int j = 1; j < f[i].size(); ++j){
			int v = f[i][j], g = lca(f[i][j - 1], v);
			ce[f[i][j - 1]] = g;
			int l = -1, r = j - 1;
			while(l + 1 < r){
				int d = (l + r) >> 1;
				if(vis[ce[f[i][d]]] >= vis[g] && vis[ce[f[i][d]]] <= ed[g]) r = d;
				else l = d;
			}
			L[v] = L[f[i][r]] + (ll)(j - r) * dep[g];
		}
		for(int j = f[i].size() - 2; j >= 0; --j){
			int v = f[i][j], g = lca(f[i][j + 1], v);
			ce[f[i][j + 1]] = g;
			int l = j + 1, r = f[i].size();
			while(l + 1 < r){
				int d = (l + r) >> 1;
				if(vis[ce[f[i][d]]] >= vis[g] && vis[ce[f[i][d]]] <= ed[g]) l = d;
				else r = d;
			}
			R[v] = R[f[i][l]] + (ll)(l - j) * dep[g];
		}
		
		for(int v : f[i])
			ans[v] = ans[p[v]] + L[v] + R[v] + dep[v] - 1;
	}
	
	for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}