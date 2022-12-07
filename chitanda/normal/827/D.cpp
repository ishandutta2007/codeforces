#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200100;
int n, m;
int u[maxn], v[maxn], c[maxn], w[maxn];
int fat[maxn];
int fa[maxn][20], tmax[maxn][20];
int dep[maxn], fa_e[maxn];
bool flag[maxn];
vector<pair<int, int> > g[maxn];
int ans[maxn];

void dfs(int t){
	for(int i = 1; fa[t][i - 1]; ++i){
		fa[t][i] = fa[fa[t][i - 1]][i - 1];
		tmax[t][i] = max(tmax[t][i - 1], tmax[fa[t][i - 1]][i - 1]);
	}
	for(auto e : g[t]){
		if(e.fi == fa[t][0]) continue;
		fa[e.fi][0] = t;
		fa_e[e.fi] = e.se;
		tmax[e.fi][0] = c[e.se];
		dep[e.fi] = dep[t] + 1;
		dfs(e.fi);
	}
}

int find(int x) { return fat[x] == x ? x : fat[x] = find(fat[x]); }

pair<int, int> get(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	int res = 0;
	for(int i = 18; i >= 0; --i)
		if(dep[fa[v][i]] >= dep[u]) res = max(res, tmax[v][i]), v = fa[v][i];
	if(u == v) return mkp(v, res);
	for(int i = 18; i >= 0; --i)
		if(fa[u][i] != fa[v][i]) res = max(res, max(tmax[u][i], tmax[v][i])), u = fa[u][i], v = fa[v][i];
	res = max(res, max(tmax[u][0], tmax[v][0]));
	return mkp(fa[u][0], res);
}

int main(){
	//freopen("tree.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", u + i, v + i, c + i);
		w[i] = i;
	}
	sort(w + 1, w + m + 1, [](int x, int y) { return c[x] < c[y]; });
	
	for(int i = 1; i <= n; ++i) fat[i] = i;
	for(int i = 1; i <= m; ++i){
		int x = u[w[i]], y = v[w[i]];
		if(find(x) == find(y)) continue;
		flag[w[i]] = 1;
		//printf("%d %d %d\n", x, y, c[w[i]]);
		g[x].pb(mkp(y, w[i]));
		g[y].pb(mkp(x, w[i]));
		fat[find(x)] = find(y);
	}
	
	dep[1] = 1;
	dfs(1);
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= m; ++i){
		if(flag[i]) continue;
		auto t = get(u[i], v[i]);
		ans[i] = t.se - 1;
	}
	for(int i = 1; i <= n; ++i) fat[i] = i;
	for(int i = 1; i <= m; ++i){
		if(flag[w[i]]) continue;
		int x = u[w[i]], y = v[w[i]];
		auto t = get(x, y);
		x = find(x), y = find(y);
		while(dep[x] > dep[t.fi]){
			ans[fa_e[x]] = c[w[i]] - 1;
			fat[x] = fa[x][0];
			x = find(fa[x][0]);
		}
		while(dep[y] > dep[t.fi]){
			ans[fa_e[y]] = c[w[i]] - 1;
			fat[y] = fa[y][0];
			y = find(fa[y][0]);
		}
	}
	for(int i = 1; i <= m; ++i) printf("%d ", ans[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}