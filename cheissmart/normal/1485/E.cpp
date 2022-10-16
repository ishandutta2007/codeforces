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
const ll oo = 1e18;

int a[N], p[N], d[N], D;
vi G[N], who[N];

void dfs(int u, int pa = 0, int depth = 0) {
	d[u] = depth;
	p[u] = pa;
	who[depth].PB(u);
	D = max(D, depth);
	for(int v:G[u]) if(v != pa)
		dfs(v, u, depth + 1);
}

ll dp[N];

void ckmax(ll& a, ll b) {
	a = max(a, b);
}

void ckmin(ll& a, ll b) {
	a = min(a, b);
}

void solve() {
	int n;
	cin >> n;
	D = 0;
	for(int i = 2; i <= n; i++) {
		int j;
		cin >> j;
		G[i].PB(j);
		G[j].PB(i);
	}
	for(int i = 2; i <= n; i++)
		cin >> a[i];
	dfs(1);
	for(int i = 1; i <= n; i++) dp[i] = 0;
	for(int i = 1; i <= D; i++) {
		ll mx = -INF, mn = INF;
		for(int u:who[i]) {
			ckmax(mx, a[u]);
			ckmin(mn, a[u]);
		}
		ll smaller = -oo, bigger = -oo;
		for(int u:who[i]) {
			ckmax(dp[u], dp[p[u]] + mx - a[u]);
			ckmax(dp[u], dp[p[u]] + a[u] - mn);
			smaller = max(smaller, dp[p[u]] - a[u]);
			bigger = max(bigger, dp[p[u]] + a[u]);
		}
		for(int u:who[i]) {
			ckmax(dp[u], smaller + a[u]);
			ckmax(dp[u], bigger - a[u]);
		}
	}
	ll ans = 0;
	for(int u:who[D]) ans = max(ans, dp[u]);
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 0; i < n; i++) who[i].clear();
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}