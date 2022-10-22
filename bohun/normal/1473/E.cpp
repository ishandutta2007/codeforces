#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

int n, m;
vector<pair<int, int>> g[1 << 18];
ll d[1 << 18][2][2];

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	for (int i = 1; i <= n; ++i)
		d[i][0][0] = d[i][0][1] = d[i][1][0] = d[i][1][1] = 1e18;
	d[1][0][0] = 0;
	set<tuple<ll, int, int, int>> s; s.insert({0, 1, 0, 0});
	while (!s.empty()) {
		auto [c, v, a, b] = *s.begin();
		s.erase(s.begin());
		for (auto [u, w] : g[v]) {
			for (int i = 0; i <= (a == 0); ++i)
				for (int j = 0; j <= (b == 0); ++j) {
					ll nd = c + w + (i == 1 ? -w : 0) + (j == 1 ? w : 0);
					int na = (a | i), nb = (b | j);
					if (nd < d[u][na][nb]) {
						s.erase({d[u][na][nb], u, na, nb});
						d[u][na][nb] = nd;
						s.insert({nd, u, na, nb});
					}
				}
		}
	}
	for (int i = 2; i <= n; ++i)
		printf("%lld ", d[i][1][1]);
	return 0;
}