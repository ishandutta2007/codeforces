#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int LOG = 19;

int n, m, w[MAXN], c[MAXN], from[MAXN], to[MAXN];
int sec[MAXN], pp[MAXN], bud;
bool used[MAXN];
ll tot;
int par[LOG][MAXN], depth[MAXN];
pair<int, int>	mn[LOG][MAXN];
vector<int>	adj[MAXN];

bool cmp(int e1, int e2){return w[e1] < w[e2];}

int getPar(int v){return pp[v]==v?v:pp[v]=getPar(pp[v]);}

void plant(int v, int p = -1){
	par[0][v] = p;
	for (int e:adj[v])
		if (used[e]){
			int u = from[e]^to[e]^v;
			if (u == p)	continue;
			depth[u] = depth[v] + 1;
			mn[0][u] = {w[e], e};
			plant(u, v);
		}
}

void init(){
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++)
			if (~par[w - 1][v])
				par[w][v] = par[w - 1][par[w - 1][v]]
					, mn[w][v] = max(mn[w-1][v], mn[w - 1][par[w - 1][v]]);
			else
				par[w][v] = -1
					, mn[w][v] = mn[w - 1][v];
}

pair<int, int> lca(int u, int v){
	pair<int, int>	ret(-1e9, 1);
	if (depth[u] < depth[v])	swap(u, v);
	for (int w = LOG - 1; ~w; w--)
		if (depth[u] - (1<<w) >= depth[v])
			ret = max(ret, mn[w][u]), u = par[w][u];
	if (u == v)	return ret;
	for (int w = LOG - 1; ~w; w--)
		if (par[w][v] ^ par[w][u])
			ret = max({ret, mn[w][u], mn[w][v]}), v = par[w][v], u = par[w][u];
	return max({ret, mn[0][u], mn[0][v]});
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)	cin >> w[i];
	for (int i = 0; i < m; i++)	cin >> c[i];
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i], from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);
	iota(sec, sec + m, 0);
	sort(sec, sec + m, cmp);
	iota(pp, pp + n, 0);
	for (int i = 0; i < m; i++){
		int u = from[sec[i]], v = to[sec[i]];
		int pu = getPar(u), pv = getPar(v);
		if (pu == pv)	continue;
		tot += w[sec[i]];
		used[sec[i]] = 1;
		pp[pu] = pv;
	}
	cin >> bud;
	plant(0);
	init();
	
	pair<ll, int>	ans(1e18, -1);
	for (int e = 0; e < m; e++)
		if (!used[e]){
			auto x = lca(from[e], to[e]);
			ll ret = tot - x.first + w[e];
			ret -= bud/c[e];
			ans = min(ans, {ret, e});
		}

	{
		pair<int, int>	mn(1e9, 1e9);
		for (int e = 0; e < m; e++)
			if (used[e])	mn = min(mn, {c[e], e});
		if (ans.F > tot - bud/mn.F){
			ans.F = tot - bud/mn.F;
			w[mn.S] -= bud/mn.F;
		}
		else{
			int e = ans.S;	
			auto x = lca(from[e], to[e]);
			used[x.S] = 0;
			used[e] = 1;
			w[e] -= bud/c[e];
		}
	}

	cout << ans.F << "\n";
	for (int e = 0; e < m; e++)
		if (used[e])
			cout << e + 1 << " " << w[e] << "\n";
	return 0;
}