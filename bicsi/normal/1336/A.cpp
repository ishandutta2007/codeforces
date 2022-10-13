#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<vector<int>> graph;

int DFS(int node, int par, int dep) {
	int ret = 1;
	for (auto vec : graph[node]) {
		if (vec == par) continue;
		ret += DFS(vec, node, dep + 1);
	}
	v.push_back(dep - ret + 1);
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	graph.resize(n);
	for (int i = 1; i  < n; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	DFS(0, -1, 0);
	sort(v.rbegin(), v.rend());
	// for (auto x : v) cerr << x << " "; cerr << endl;
	long long ans = 0;
	for (int i = 0; i < k; ++i)
		ans += v[i];
	cout << ans << endl;

	return 0;
}