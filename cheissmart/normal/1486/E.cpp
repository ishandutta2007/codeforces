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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

V<pi> G[N];
int d[N][55];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	memset(d, 0x3f, sizeof d);
	d[1][0] = 0;
	priority_queue<array<int, 3>, V<array<int, 3>>, greater<array<int, 3>>> pq;
	pq.push({0, 1, 0});
	while(pq.size()) {
		auto p = pq.top(); pq.pop();
		int u = p[1], c = p[2];
		if(d[u][c] < p[0]) continue;
		for(pi e:G[u]) {
			int v = e.F, w = e.S;
			if(c == 0) {
				if(d[u][c] + w * w < d[v][w]) {
					d[v][w] = d[u][c] + w * w;
					pq.push({d[v][w], v, w});
				}
			} else {
				if(d[u][c] + w * w + 2 * w * c < d[v][0]) {
					d[v][0] = d[u][c] + w * w + 2 * w * c;
					pq.push({d[v][0], v, 0});
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(d[i][0] > 1e18) d[i][0] = -1;
		cout << d[i][0] << ' ';
	}
	cout << '\n';


}