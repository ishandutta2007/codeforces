#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1003;

V<pi> G[N];
int d[N][N], a[N], b[N];

void dijkstra(int s, int* d) {
	d[s] = 0;
	priority_queue<pi, V<pi>, greater<pi>> pq;
	pq.push({0, s});
	while(pq.size()) {
		pi p = pq.top(); pq.pop();
		int u = p.S, dd = p.F;
		if(dd > d[u]) continue;
		for(pi e:G[u]) {
			int v = e.F, w = e.S;
			if(d[u] + w < d[v]) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
}

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >> k;
	V<pi> es;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		es.EB(u, v);
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	memset(d, 0x3f, sizeof d);
	for(int i = 1; i <= n; i++) {
		dijkstra(i, d[i]);
	}
	int ans = 0;
	for(int i = 0; i < k; i++) cin >> a[i] >> b[i], ans += d[a[i]][b[i]];
	for(int i = 0; i < m; i++) {
		int x = es[i].F, y = es[i].S;
		int cans = 0;
		for(int i = 0; i < k; i++) {
			cans += min({d[a[i]][b[i]], d[a[i]][x] + d[b[i]][y], d[a[i]][y] + d[b[i]][x]});
		}
		ans = min(ans, cans);
	}	
	cout << ans << endl;
}