#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<pii> T[202020];
int U[202020], V[202020], P[202020], B[202020];
int n, m;

int find(int u) { return u == P[u] ? u : P[u] = find(P[u]); }

int dfs(int u, int p, int y) {
	for (auto &[v, i]: T[u]) {
		if (v == y) {
			B[i] = 1;
			return 1;
		}
		else if (v != p) {
			if (dfs(v, u, y)) return 1;
		}
	}
	return 0;
}

void tc() {
	set<int> S;
	int i, u, v, x, y, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		T[i].clear();
	}
	iota(P, P + n + 1, 0);
	fill(B, B + m + 1, 0);
	for (i = 1; i <= m; i++) {
		cin >> U[i] >> V[i];
		if (U[i] > V[i]) swap(U[i], V[i]);
		u = find(U[i]); v = find(V[i]);
		if (u != v) {
			T[U[i]].emplace_back(V[i], i);
			T[V[i]].emplace_back(U[i], i);
			P[u] = v;
		}
		else {
			B[i] = 1;
			S.insert(U[i]);
			S.insert(V[i]);
			x = U[i]; y = V[i]; t = i;
		}
	}

	if (m == n + 2 && S.size() == 3) {
		B[t] = 0; dfs(x, 0, y);
	}

	for (i = 1; i <= m; i++) {
		cout << B[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}