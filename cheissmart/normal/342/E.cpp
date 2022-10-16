#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];

int sz[N];
bool vis[N];

void dfs_sz(int u, int p = 0) {
	sz[u] = 1;
	for(int v:G[u]) if(v != p && !vis[v]) {
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
}

void dfs_c(int u, int& c, int tot_sz, int p = 0) {
	int mx = tot_sz - sz[u];
	for(int v:G[u]) if(v != p && !vis[v]) {
		dfs_c(v, c, tot_sz, u);
		mx = max(mx, sz[v]);
	}
	if(mx * 2 <= tot_sz)
		c = u;
}

int p[N];

void CD(int u, int pc) {
	dfs_sz(u);
	int c = -1;
	dfs_c(u, c, sz[u]), assert(c != -1);
	p[c] = pc;
	vis[c] = true;
	for(int v:G[c]) if(!vis[v])
		CD(v, c);
}

int d[N], pa[N], jump[N];

void dfs(int u, int p) {
	jump[u] = pa[u] = p;
	if(d[p] - d[jump[p]] == d[jump[p]] - d[jump[jump[p]]])
		jump[u] = jump[jump[p]];
	for(int v:G[u]) if(v != p)
		d[v] = d[u] + 1, dfs(v, u);
}

int go_up(int u, int step) {
	while(step) {
		if(d[u] - d[jump[u]] <= step) {
			step -= d[u] - d[jump[u]];
			u = jump[u];
		} else {
			u = pa[u];
			step--;
		}
	}
	return u;
}

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	v = go_up(v, d[v] - d[u]);
	assert(d[u] == d[v]);
	while(u != v) {
		if(jump[u] != jump[v])
			u = jump[u], v = jump[v];
		else
			u = pa[u], v = pa[v];
	}
	return u;
}

int get_dist(int u, int v) {
	return d[u] + d[v] - 2 * d[lca(u, v)];
}

int dist[N];

void upd(int u) {
	int v = u;
	while(u != 0) {
		debug(u);
		dist[u] = min(dist[u], get_dist(u, v));
		u = p[u];
	}
}

int qry(int u) {
	int v = u, res = INF;
	while(u != 0) {
		debug(u);
		res = min(res, dist[u] + get_dist(u, v));
		u = p[u];
	}
	return res;
}

signed main()
{
	IO_OP;

	memset(dist, 0x3f, sizeof dist);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v), G[v].PB(u);
	}

	dfs(1, 1);
	CD(1, 0);

	upd(1);

	while(m--) {
		int op, u;
		cin >> op >> u;
		if(op == 1) {
			upd(u);
		} else {
			cout << qry(u) <<'\n';;
		}
	}

}