#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 3e5 + 7;

int sz[N], vis[N], x;
vi G[N], edge[N];

int dfs_sz(int u, int p = -1) {
	sz[u] = 1;
	for(int v:G[u]) if(v != p && !vis[v])
		sz[u] += dfs_sz(v, u);
	return sz[u];
}

void get_c(int u, int tot, int& c, int p = -1) {
	int mx = tot - sz[u];
	for(int v:G[u]) if(v != p && !vis[v]) {
		get_c(v, tot, c, u);
		mx = max(mx, sz[v]);
	}
	if(mx * 2 <= tot)
		c = u;
}

ll sum[N], a[N];

void dfs(int u, int p = -1) {
	sum[u] = a[u];
	for(int v:G[u]) if(v != p && !vis[v]) {
		dfs(v, u);
		sum[u] += sum[v] - x;
	}
}

void centroid_decomposition(int u) {
	int tot = dfs_sz(u), c;
	get_c(u, tot, c);
	dfs(c);
	assert(sum[c] >= 0);
	V<pi> ch;
	for(int i = 0; i < int(G[c].size()); i++) if(!vis[G[c][i]])
		ch.EB(G[c][i], edge[c][i]);
	sort(ALL(ch), [&] (pi x, pi y) {
		return sum[x.F] > sum[y.F];
	});
	vis[c] = 1;
	for(pi p:ch) {
		int v = p.F;
		if(sum[v] >= 0) {
			ll tt = sum[v];
			a[v] -= tt;
			centroid_decomposition(v);
			cout << p.S + 1 << '\n';
		} else {
			cout << p.S + 1 << '\n';
			ll tt = -sum[v];
			a[v] += tt;
			centroid_decomposition(v);
		}
	}
}

int p[N];
int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	p[x] = y;
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m >> x;
	ll sum = (ll) (n - 1) * -x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		p[i] = i;
	}
	if(sum < 0)
		return cout << "NO\n", 0;

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if(find(u) == find(v)) continue;
		unite(u, v);
		G[u].PB(v), edge[u].PB(i);
		G[v].PB(u), edge[v].PB(i);
	}
	cout << "YES\n";
	centroid_decomposition(1);

}