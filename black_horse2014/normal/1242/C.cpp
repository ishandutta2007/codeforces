#include <bits/stdc++.h>
using namespace std;
 
const int N = 15;
const int M = 110000;
 
vector<int> a[15];
vector<int> b[15];
int c[M];
int p[M];
vector<int> adj[M], radj[M];
int vis[M], q[M];
vector<int> cycle[M];
vector<tuple<int, int, int>> ans[1<<N];
int dp[1<<N];
int pr[1<<N];
map<long long, pair<int, int>> H;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long sum = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int sz; cin >> sz;
		a[i].resize(sz);
		b[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			cin >> a[i][j];
			sum += a[i][j];
			H[a[i][j]] = {i, j};
			b[i][j] = m;
			c[m] = i;
			p[m++] = j;
		}
	}
	if (sum % n != 0) {
		cout << "No" << "\n";
		return 0;
	}
	sum /= n;
	for (int i = 0; i < n; i++) {
		long long s = accumulate(a[i].begin(), a[i].end(), 0LL);
		if (s != sum) {
			for (int j = 0; j < a[i].size(); j++) {
				long long cur = sum - (s - a[i][j]);
				if (H.count(cur)) {
					auto it = H[cur];
					if (it.first == i) continue;
					adj[b[i][j]].push_back(b[it.first][it.second]);
					radj[b[it.first][it.second]].push_back(b[i][j]);
				}
			}
		} else {
			dp[1<<i] = 1;
			ans[1<<i].emplace_back(i, a[i][0], i);
		}
	}
	int qn = 0;
	function<void(int)> dfs= [&](int u) {
		vis[u] = 1;
		for (int v : adj[u]) if (!vis[v]) dfs(v);
		q[qn++] = u;
	};
	int T = 0;
	function<void(int)> rdfs= [&](int u) {
		vis[u] = T;
		cycle[T].push_back(u);
		for (int v : radj[u]) if (!vis[v]) rdfs(v);
	};
	memset(vis, 0, sizeof(int) * m);
	qn = 0;
	for (int i = 0; i < m; i++) if (!vis[i]) dfs(i);
	memset(vis, 0, sizeof(int) * m);
	for (int i = m - 1; i >= 0; i--) if (!vis[q[i]]) ++T, rdfs(q[i]);
	for (int i = 1; i <= T; i++) {
		if (cycle[i].size() >= 2) {
			int used[N] = {0};
			bool flag = true;
			int mask = 0;
			for (int j : cycle[i]) {
				if (used[c[j]]) flag = false;
				used[c[j]] = 1;
				mask |= 1 << c[j];
			}
			if (!flag) continue;
			dp[mask] = 1;
			if (ans[mask].empty()) {
				int x = cycle[i][0];
				vector<int> path;
				path.push_back(x);
				for (int y = adj[x][0]; y != x; y = adj[y][0]) {
					path.push_back(y);
				}
				for (int k = 0; k < path.size(); k++) {
					int u = path[k], v = path[(k + 1) % path.size()];
					ans[mask].emplace_back(c[v], a[c[v]][p[v]], c[u]);
				}
			}
		}
	}
	dp[0] = 1;
	for (int i = 1; i < 1<<n; i++) {
		if (dp[i]) continue;
		for (int j = i & (i - 1); j; j = (j - 1) & i) {
			if (dp[j] && dp[i - j]) {
				pr[i] = j;
				dp[i] = 1;
				break;
			}
		}
	}
	vector<pair<int, int>> ret(n);
	function<void(int)> solve = [&](int mask) {
		if (pr[mask] == 0) {
			for (auto t : ans[mask]) {
				int i, j, k; tie(i, j, k) = t;
				ret[i] = {j, k};
			}
			return;
		}
		solve(pr[mask]);
		solve(mask - pr[mask]);
	};
	if (dp[(1<<n)-1]) {
		cout << "Yes" << "\n";
		solve((1<<n)-1);
		for (auto t : ret) {
			cout << t.first << ' ' << t.second + 1 << "\n";
		}
		return 0;
	}
	cout << "No" << "\n";
	return 0;
}