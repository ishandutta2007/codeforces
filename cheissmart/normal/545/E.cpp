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

const int INF = 1e9 + 7, N = 3e5 + 7;
const ll oo = 1e18;

V<pi> G[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	vi w(m);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v >> w[i];
		u--, v--;
		G[u].EB(v, i);
		G[v].EB(u, i);
	}
	int s;
	cin >> s, s--;

	ll ans = 0;
	V<ll> d(n, oo);
	V<bool> vis(n);
	priority_queue<array<ll, 3>, V<array<ll, 3>>, greater<array<ll, 3>>> pq;

	d[s] = 0;
	pq.push({d[s], 0, ll(s) << 32});

	vi edges;
	while(pq.size()) {
		auto[dist, ww, u] = pq.top(); pq.pop();
		int edge = int(u & ((1LL << 32) - 1));
		u = u >> 32;
		if(vis[u]) continue;
		edges.PB(edge);
		vis[u] = true;
		ans += ww;
		debug(u, ww);
		for(auto[v, i] : G[u]) {
			if(d[u] + w[i] <= d[v]) {
				d[v] = d[u] + w[i];
				pq.push({d[v], w[i], ll(v) << 32 | i});
			}
		}
	}
	cout << ans << '\n';
	edges.erase(edges.begin());
	sort(ALL(edges));
	for(int i:edges)
		cout << i + 1 << ' ';
	cout << '\n';
}