#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int dp[N], ans[N], a[N];
vi G[N];

void dfs(int u, int p = 0) {
	dp[u] = a[u] ? 1 : -1;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		dp[u] += max(0, dp[v]);
	}
}

void dfs1(int u, int p = 0, int add = 0) {
	ans[u] = dp[u] + add;
	for(int v:G[u]) if(v != p) {
		int pass = ans[u];
		if(dp[v] > 0) pass -= dp[v];
		dfs1(v, u, max(pass, 0));
	}
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	dfs1(1);
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
}