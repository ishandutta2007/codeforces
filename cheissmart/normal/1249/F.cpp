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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 202;

int n, k, a[N], dp[N][N];
vi G[N];

void dfs(int u, int p = 0) {
	for(int v:G[u]) if(v != p)
		dfs(v, u);
	for(int depth = 0; depth < n; depth++) {
		if(depth == 0) {
			dp[u][depth] = a[u];
			for(int v:G[u]) if(v != p)
				if(depth + k < n)
					dp[u][depth] += dp[v][depth + k];
		} else {
			for(int v:G[u]) if(v != p) {
				int cur = dp[v][depth - 1];
				for(int vv : G[u]) if(vv != p && vv != v)
					cur += dp[vv][max(depth - 1, k - depth)];
				dp[u][depth] = max(dp[u][depth], cur);
			}
		}
	}
	for(int i = n - 2; i >= 0; i--)
		dp[u][i] = max(dp[u][i], dp[u][i + 1]);
}

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << dp[1][0] << endl;
}