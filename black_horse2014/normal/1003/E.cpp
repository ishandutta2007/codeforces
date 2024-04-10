#include <bits/stdc++.h>
using namespace std;

const int N = 440000;

int cur, n, k;
vector<pair<int, int> > ans;

inline void add_edge(int u, int v) {
	ans.push_back({u, v});
}

void build_tree(int root, int dep) {
	if (!dep || cur == n) return;
	for (int i = 1; i <= k - 1 && cur != n; i++) {
		add_edge(root, ++cur);
		build_tree(cur, dep - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	int d; cin >> n >> d >> k;
	if (n <= d || (k == 1 && d >= 2)) return puts("NO"), 0;
	for (int i = 1; i <= d; i++) add_edge(i, i + 1);
	cur = d + 1;
	for (int i = 2; i <= d; i++) {
		int dep = min(i - 1, d + 1 - i);
		for (int j = 1; j <= k - 2 && cur != n; j++) {
			add_edge(i, ++cur);
			build_tree(cur, dep - 1);
		}
	}
	if (cur != n) return puts("NO"), 0;
	cout << "YES\n";
	for (auto e : ans) cout << e.first << " " << e.second << endl;
	return 0;
}