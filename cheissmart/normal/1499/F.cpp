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

const int INF = 1e9 + 7, M = 998244353, N = 5005;

vi G[N];
int dp[N][N], dp2[N][N];
int n, k;

void dfs(int u, int p = 0) {
	vi ch;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		ch.PB(v);
	}
	dp[u][0] = 1;
	for(int v:ch) {	
		for(int i = 0; i <= k; i++) {
			dp2[u][i] = dp[u][i];
			if(i) dp2[u][i] = (dp2[u][i] + dp2[u][i - 1]) % M;
		}
		// cut edge
		vi tmp(k + 1), aux(k + 1);
		for(int i = 0; i <= k; i++)
			tmp[i] = (ll) dp[u][i] * dp2[v][k] % M;
		// don't cut
		for(int i = 0; i < k; i++) {
			int can = k - i - 1;
			if(i + 1 <= can) {
				aux[i + 1] = (aux[i + 1] + dp[v][i]) % M;
				aux[can + 1] = (aux[can + 1] - dp[v][i] + M) % M; 
			}
			tmp[i + 1] = (tmp[i + 1] + (ll) dp2[u][min(i, can)] * dp[v][i] % M) % M;
		}
		for(int i = 0; i <= k; i++) {
			if(i) aux[i] = (aux[i] + aux[i - 1]) % M;
			tmp[i] = (tmp[i] + (ll) aux[i] * dp[u][i] % M) % M;
 			dp[u][i] = tmp[i];
		}
	}

	for(int i = 0; i <= k; i++) {
		dp2[u][i] = dp[u][i];
		if(i) dp2[u][i] = (dp2[u][i] + dp2[u][i - 1]) % M;
	}
}

signed main()
{
	IO_OP;

	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << dp2[1][k] << '\n';
}