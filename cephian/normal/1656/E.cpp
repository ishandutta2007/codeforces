#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> T[N];
int ans[N];

void dfs(int p, int u, int subtree_sum, int above) {
	ans[u] = subtree_sum - above*(T[u].size() - 1);
	for(int v : T[u]) {
		if(p == v) continue;
		dfs(u, v, above, subtree_sum);
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		T[i].clear();
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(-1, 0, -1, 1);
	for(int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}