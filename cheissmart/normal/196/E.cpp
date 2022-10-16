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
const ll oo = 1e18;

V<pi> G[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	
	V<ll> d(n, oo), who(n);
	priority_queue<pair<ll, int>, V<pair<ll, int>>, greater<pair<ll, int>>> pq;

	int k; cin >> k;
	vi p(k); for(int &i:p) cin >> i, d[--i] = 0, pq.push({d[i], i}), who[i] = i;

	while(pq.size()) {
		auto [dist, u] = pq.top(); pq.pop();
		if(dist > d[u]) continue;
		for(auto [v, w] : G[u]) {
			if(d[u] + w < d[v] || (d[u] + w == d[v] && who[u] < who[v])) {
				d[v] = d[u] + w;
				who[v] = who[u];
				pq.push({d[v], v});
			}
		}
	}

	V<pair<ll, pi>> edges;
	for(int u = 0; u < n; u++)
		for(auto[v, w]:G[u]) {
			debug(who[u], who[v], d[u] + d[v] + w);
			edges.EB(d[u] + d[v] + w, pi(who[u], who[v]));
		}
	sort(ALL(edges));

	vi g(n); iota(ALL(g), 0);
	function<int(int)> find = [&] (int u) {
		return g[u] == u ? u : g[u] = find(g[u]);
	};
	auto unite = [&] (int x, int y) {
		x = find(x), y = find(y);
		g[x] = y;
	};

	ll ans = d[0];
	for(auto[w, e] : edges) {
		if(find(e.F) != find(e.S)) {
			debug(e.F, e.S, w);
			unite(e.F, e.S);
			ans += w;
		}
	}
	cout << ans << '\n';

}