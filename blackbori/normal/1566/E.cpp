#include <bits/stdc++.h>

using namespace std;

vector<int> T[202020];
int s;

bool dfs(int u, int p) {
	int c = 0;
	for (int &v: T[u]) if (v != p) {
		if (dfs(v, u)) c++;
	}
	if (c) s += c - 1;
	return !c;
}

void solve() {
	int n, i, u, v;
	cin >> n;
	for (i = 1; i <= n; i++) {
		T[i].clear();
	}
	for (i = 1; i < n; i++) {
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	s = 1; dfs(1, 0);
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}