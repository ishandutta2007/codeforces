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

const int INF = 1e9 + 7, N = 2e5 + 7;

V<pi> G[N];
vi rG[N], order;
int scc[N], vis[N];

void dfs(int u) {
	vis[u] = 1;
	for(int v:rG[u]) if(!vis[v])
		dfs(v);
	order.PB(u);
}

ll d[N], g[N];

void dfs2(int u, int cnt, ll dis = 0) {
	scc[u] = cnt;
	d[u] = dis;
	for(pi e:G[u]) {
		int v = e.F, w = e.S;
		if(!scc[v]) dfs2(v, cnt, dis + w);
		else if(scc[v] == cnt) {
			g[cnt] = __gcd(g[cnt], d[u] - d[v] + w);
		}
	}
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		rG[v].EB(u);
	}
	for(int i = 1; i <= n; i++) if(!vis[i])
		dfs(i);
	reverse(ALL(order));
	int cnt = 0;
	for(int i:order) if(!scc[i]) {
		dfs2(i, ++cnt);
	}

	int q;
	cin >> q;
	while(q--) {
		int u, s, t;
		cin >> u >> s >> t;
		s = (t - s) % t;
		cout << (s % __gcd(ll(t), g[scc[u]]) == 0 ? "YES" : "NO") << '\n';
	}


}