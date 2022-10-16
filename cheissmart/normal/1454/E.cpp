#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];
int d[N], pa[N];

void dfs(int u, int p = 0, int depth = 0) {
	d[u] = depth;
	pa[u] = p;
	for(int v:G[u]) if(v != p)
		dfs(v, u, depth + 1);
}

int dfs_sz(int u, int p = -1) {
	int s = 1;
	for(int v:G[u]) if(v != p) s += dfs_sz(v, u);
	return s;
}

void solve() {
	int n;
	cin >> n;
	int x, y;
	vi p(n + 1);
	iota(ALL(p), 0);
	function<int(int)> find = [&](int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	};
	for(int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if(find(u) != find(v)) {
			p[find(u)] = p[find(v)];
			G[u].PB(v);
			G[v].PB(u);
		} else {
			x = u, y = v;
		}
	}
	ll ans = (ll) n * (n - 1) / 2;
	dfs(x);
	vi path, yes(n + 1);
	while(y != x) {
		path.PB(y);
		y = pa[y];
	}
	path.PB(x);
	for(int i:path) yes[i] = 1;
	int sum = 0;
	for(int i:path) {
		int cur = 1;
		for(int j:G[i]) if(!yes[j]) cur += dfs_sz(j, i);
		ans += (ll) sum * cur;
		sum += cur;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) G[i].clear();
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;	
	while(t--) solve();

}