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

const int INF = 1e9 + 7, N = 3e5 + 7, M = 998244353;

vi G[N];
int dp[N][3];
/*
	dp[u][0]: u is not in independent set
	dp[u][1]: u is in independent set
	dp[u][2]: u is in independent set and u is an isolated vertex
*/

void dfs(int u, int p = -1) {
	dp[u][0] = dp[u][1] = dp[u][2] = 1;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		dp[u][0] = dp[u][0] * ((dp[v][0] + dp[v][1] + dp[v][2] + dp[v][0] + dp[v][1]) % M) % M;
		dp[u][1] = dp[u][1] * ((dp[v][0] + dp[v][1] + dp[v][0]) % M) % M;
		dp[u][2] = dp[u][2] * ((dp[v][0] + dp[v][1]) % M) % M;
	}
	dp[u][1] = (dp[u][1] - dp[u][2] + M) % M;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][1] + M - 1) % M << endl;
	
}