#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct E {
	int a;
	int b;
	int c;
};	

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m;
		cin >> n >> m;
		vector<E> e(2 * m);
		for (int i = 0; i < m; i++) {
			cin >> e[i].a >> e[i].b >> e[i].c;
			e[i].a--, e[i].b--;
			e[i + m] = {e[i].b, e[i].a, e[i].c};	
		}
		m *= 2;
		vector<vector<int>> d(n, vector<int> (n, (int) 1e9 + 7));
		for (int i = 0; i < n; i++) {
			d[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			d[e[i].a][e[i].b] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		ll sol = (ll) 1e18 + 7;
		for (auto &x : e) {
			int a = x.a, b = x.b;
			ll c = x.c;
			sol = min(sol, c * (d[0][a] + 1 + d[b][n - 1]));
			for (int x = 0; x < n; x++) {
				sol = min(sol, c * (d[a][x] + 1 + d[0][x] + d[n - 1][x] + 1));
			}
		}
		cout << sol << "\n";
	}
  return 0;
}