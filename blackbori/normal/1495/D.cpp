#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

vector<int> G[444];
int D[444][444], L[444], C[444], K[444];
int n, m;

void tc() {
	int u, v, i, j, k, d;
	ll a, c;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) D[i][j] = 1e9;
		}
	}
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		D[u][v] = 1; D[v][u] = 1;
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (u = 1; u <= n; u++) {
		for (v = 1; v <= n; v++) {
			d = D[u][v];
			for (i = 0; i <= d; i++) K[i] = 0;

			a = 1;
			for (i = 1; i <= n; i++) {
				L[i] = D[u][i] + D[v][i] - d;
				if (L[i] & 1) { a = 0; break; }
				L[i] >>= 1;
				C[i] = D[u][i] - L[i];
				if (L[i] == 0) {
					if (K[C[i]]) { a = 0; break; }
					K[C[i]] = i;
				}
			}

			for (i = 1; i <= n; i++) {
				c = 0;
				for (int &x: G[i]) {
					if (C[i] + L[i] + 1 < C[x] + L[x]) { a = 0; break; }
					if (d - C[i] + L[i] + 1 < d - C[x] + L[x]) { a = 0; break; }
					if (C[x] == C[i] && L[x] < L[i]) c++;
				}
				if (L[i]) a = a * c % mod;
			}

			cout << a << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
/*
	cin >> t;
/*/
	t = 1;
//*/
	for (; t--; tc());

	return 0;
}