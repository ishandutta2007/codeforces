#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> T[101010];
ll L[101010], R[101010], D[101010][2];
int n;

void dfs(int u, int p) {
	D[u][0] = D[u][1] = 0;
	for (int &v: T[u]) {
		if (v != p) {
			dfs(v, u);
			D[u][0] += max(D[v][0] + abs(L[u] - L[v]), D[v][1] + abs(L[u] - R[v]));
			D[u][1] += max(D[v][0] + abs(R[u] - L[v]), D[v][1] + abs(R[u] - R[v]));
		}
	}
}

void tc() {
	int i, u, v;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> L[i] >> R[i];
		T[i].clear();
	}
	for (i = 1; i < n; i++) {
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	
	dfs(1, 0);

	cout << max(D[1][0], D[1][1]) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}