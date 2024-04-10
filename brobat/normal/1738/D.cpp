#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vi v(n + 1);
	rep(i, 1, n + 1) cin >> v[i];
	int k = 0;
	rep(i, 1, n + 1) {
		if(i < v[i]) k = i;
	}
	cout << k << '\n';
	vector<vector<int>> adj(n + 1);
	vi prev(n + 1, 0);
	rep(i, 1, n + 1) {
		if(v[i] == n + 1 || v[i] == 0) {
			prev[i] = 0;
			adj[0].push_back(i);
		} else {
			prev[i] = v[i];
			adj[v[i]].push_back(i);
		}
	}
	vi d(n + 1, -1);

	function<void(int, int)> DFS_D = [&](int node, int depth) -> void {
		d[node] = depth;
		for(auto nx : adj[node]) {
			DFS_D(nx, depth + 1);
		}
	};
	DFS_D(0, 0);
	vector<vector<int>> depth(n + 1);
	for(int i = 0; i <= n; i++) {
		depth[d[i]].push_back(i);
	}
	for(int i = 0; i <= n; i++) {
		sort(depth[i].begin(), depth[i].end(), [&](int x, int y) {
			return sz(adj[x]) < sz(adj[y]);
		});
	}
	for(int i = 1; i <= n; i++) {
		for(auto j : depth[i]) cout << j << ' ';
	}
	cout << '\n';
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--) {
		solve();
	}
}