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

const int INF = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	V<pi> edges;
	V<V<pi>> G(n);
	vi aux(n), top(n), val(n);
	for(int i = 0; i < n - 1; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		x--, y--;
		edges.EB(x, y);
		G[x].EB(y, v);
		G[y].EB(x, v);
	}

	function<void(int, int)> dfs = [&] (int u, int p) {
		for(auto[v, w] : G[u]) if(v != p) {
			if(w != -1) {
				top[v] = top[u];
				val[v] = val[u] ^ w;
			} else {
				top[v] = v;
			}
			dfs(v, u);
		}
	};

	top[0] = 0;
	dfs(0, -1);

	vi p(n);
	iota(ALL(p), 0);
	function<int(int)> find = [&] (int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	};
	auto unite = [&] (int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		p[x] = y;
	};

	V<pi> diff;

	while(m--) {
		int a, b, p;
		cin >> a >> b >> p;
		a--, b--;
		int ta = top[a], tb = top[b];
		int tt = (__builtin_popcount(val[a] ^ val[b]) % 2) ^ p;
		if(tt == 0) {
			unite(ta, tb);
		} else {
			diff.EB(ta, tb);
		}
	}

	V<vi> g(n);
	for(auto[ta, tb] : diff) {
		int u = find(ta), v = find(tb);
		if(u == v) {
			cout << "NO\n";
			return;
		}
		g[u].PB(v);
		g[v].PB(u);
	}

	vi vis(n);

	function<bool(int, int)> dfs2 = [&] (int u, int c) {
		vis[u] = c;
		for(int v:g[u]) {
			if(!vis[v]) {
				if(!dfs2(v, c ^ 3))
					return false;
			} else if(vis[v] == vis[u])
				return false;
		}
		return true;
	};

	for(int i = 0; i < n; i++) if(top[i] == i && find(i) == i) {
		if(!vis[i]) {
			if(!dfs2(i, 1)) {
				cout << "NO" << '\n';
				return;
			}
		}
	}

	for(int i = 0; i < n; i++) if(top[i] == i) {
		assert(vis[find(i)]);
		aux[i] = vis[find(i)] % 2;
	}

	for(int i = 0; i < n; i++)
		aux[i] = aux[top[i]] ^ val[i];

	cout << "YES\n";
	for(auto[x, y] : edges) {
		cout << x + 1 << ' ' << y + 1 << ' ' << (aux[x] ^ aux[y]) << '\n';
	}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}