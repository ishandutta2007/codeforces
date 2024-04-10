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

const int INF = 1e9 + 7, N = 205;

int d[N][N], p[N * 2];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) d[i][j] = INF;
	iota(p + 1, p + 2 * n + 1, 1);
	function<int(int)> find = [&] (int u) {
		return p[u] == u ? p[u] : p[u] = find(p[u]);
	};
	auto unite = [&](int x, int y) {
		int rx = find(x), ry = find(y);
		p[rx] = ry;
	};
	while(m--) {
		int u, v, b;
		cin >> u >> v >> b;
		if(b == 0) {
			d[u][v] = d[v][u] = 1;
		} else {
			d[u][v] = 1, d[v][u] = -1;
		}
		unite(u, v + n);
		unite(u + n, v);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for(int i = 1; i <= n; i++) {
		if(d[i][i] < 0 || find(i) == find(i + n)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	int best = -1, best_s = -1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[i][j] > best) {
				best = d[i][j];
				best_s = i;
			}
		}
	}
	vi ans(n + 1);
	for(int i = 1; i <= n; i++) ans[i] = d[best_s][i];
	cout << "YES" << endl;
	cout << best << endl;
	int mn = *min_element(ALL(ans));
	for(int i = 1; i <= n; i++) cout << ans[i] - mn << " \n"[i == n];

}