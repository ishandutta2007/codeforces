#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7, M = 998244353;
const ll oo = 1e18;

int d[N];

int n, m;

vi G[N], rG[N];

V<pi> g[N];
pi dd[N];

void solve() {
	priority_queue<pair<pi, int>, V<pair<pi, int>>, greater<pair<pi, int>>>	pq;
	for(int i = 1; i <= n * 2; i++) dd[i] = {INF, INF};
	dd[1] = {0, 0};
	pq.push({dd[1], 1});
	while(pq.size()) {
		auto p = pq.top(); pq.pop();
		pi dist = p.F;
		int u = p.S;
		if(dist > dd[u]) continue;
		for(pi e:g[u]) {
			int v = e.F, w = e.S;
			pi nw = {dd[u].F + w, dd[u].S + 1};
			if(nw < dd[v]) {
				dd[v] = nw;
				pq.push({nw, v});
			}
		}
	}
	pi mn = min(dd[n], dd[n + n]);
	ll cost = 1;
	for(int i = 0; i < mn.F; i++) cost = cost * 2 % M;
	cost = (cost + M - 1) % M;
	cost = (cost + mn.S) % M;
	cout << cost << endl;
}

signed main()
{
	IO_OP;

	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		rG[v].PB(u);
		g[u].EB(v, 0);
		g[v].EB(u + n, 1);
		g[v + n].EB(u + n, 0);
		g[u + n].EB(v, 1);
	}
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	ll ans = oo;
	ll cost = 0;
	for(int _ = 0; _ < 30; _++) {
		priority_queue<pi, V<pi>, greater<pi>> pq;
		for(int i = 1; i <= n; i++) if(d[i] != INF) {
			pq.push({d[i], i});
		}
		while(pq.size()) {
			pi p = pq.top(); pq.pop();
			int dist = p.F, u = p.S;
			if(dist > d[u]) continue;
			if(_ % 2 == 0) {
				for(int v:G[u]) {
					if(d[u] + 1 < d[v]) {
						d[v] = d[u] + 1;
						pq.push({d[v], v});
					}
				}
			} else {
				for(int v:rG[u]) {
					if(d[u] + 1 < d[v]) {
						d[v] = d[u] + 1;
						pq.push({d[v], v});
					}
				}
			}
		}
		if(d[n] != INF) {
			ans = min(ans, cost + d[n]);
		}
		cost += 1LL << _;
	}
	if(ans != oo) {
		ans %= M;
		cout << ans << endl;
		return 0;
	}
	solve();

}