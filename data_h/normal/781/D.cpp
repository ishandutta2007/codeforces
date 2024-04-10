#include <bits/stdc++.h>

using namespace std;

const int N = 503;
const int LOG = 61;

long long go[LOG][2][N];
bitset<N> f[LOG][2][N];

int n, m;

void update(long long &a, long long b) {
	if (a < b) a = b;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		--u, --v;
		go[0][t][u] = 1;
		f[0][t][u][v] = 1;
	}
	long long ans = 0;
	for (int i = 0; i + 1 < LOG; i++) {
		for (int t = 0; t < 2; t++) {
			for (int u = 0; u < n; u++) {
				go[i + 1][t][u] = go[i][t][u];
				for (int v = 0; v < n; v++) {
					if (f[i][t][u][v]) {
						update(go[i + 1][t][u], (1LL << i) + go[i][t ^ 1][v]);
						f[i + 1][t][u] |= f[i][t ^ 1][v];
					}
				}
			}
		}
	}
	ans = go[LOG - 1][0][0];
	const long long INF = 1e18;
	if (ans > INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}