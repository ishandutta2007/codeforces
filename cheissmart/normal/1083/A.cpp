#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 87;

int w[N], dp[N], ans;
vector<pi> G[N];

void dfs(int u, int p = -1) {
	dp[u] = w[u];
	vi ch;
	for(pi e:G[u]) {
		int v = e.F, d = e.S;
		if(v != p) {
			dfs(v, u);
			dp[u] = max(dp[u], w[u] + dp[v] - d);
			ch.PB(dp[v] - d);
		}
	}
	sort(ALL(ch), greater<int>());
	ans = max(ans, dp[u]);
	if(ch.size() > 1) ans = max(ans, w[u] + ch[0] + ch[1]);
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> w[i];
	for(int i=0;i<n-1;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	dfs(1);
	cout << ans << endl;
}