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

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N], dp[N][42], dp2[N][42], ans[N];
int n, k;
vi G[N];

void dfs(int u, int p = 0) {
	dp[u][0] ^= a[u];
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		for(int i = 0; i < (2 * k); i++)
			dp[u][(i + 1) % (2 * k)] ^= dp[v][i];
	}
}

void dfs2(int u, int p, vi up) {
	for(int i = 0; i < (2 * k); i++)
		dp2[u][i] = dp[u][i];
	for(int i = 0; i < (2 * k); i++)
		dp2[u][(i + 1) % (2 * k)] ^= up[i];
	int tt = 0;
	for(int i = k; i < 2 * k; i++) tt ^= dp2[u][i];
	if(tt) ans[u] = 1;
	for(int i = 0; i < (2 * k); i++) up[i] = dp2[u][i];
	for(int v:G[u]) if(v != p) {
		vi tmp = up;
		for(int i = 0; i < (2 * k); i++)
			up[(i + 1) % (2 * k)] ^= dp[v][i];
		dfs2(v, u, up);
		up = tmp;
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
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	dfs2(1, 0, vi(2 * k));
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';

}