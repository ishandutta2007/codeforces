#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	V<vi> G(n + 1);
	for(int i = 2; i <= n; i++) {
		int p; cin >> p;
		G[p].PB(i);
	}
	vi dp(n + 1), l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	int ans = 0;

	function<void(int)> dfs = [&] (int u) {
		for(int v:G[u]) {
			dfs(v);
			dp[u] = min(dp[u] + dp[v], INF);
		}
		dp[u] = min(dp[u], r[u]);
		if(dp[u] < l[u]) {
			dp[u] = r[u];
			ans++;
		}
	};
	dfs(1);

	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}