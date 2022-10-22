#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 3e5 + 100;
const int MOD = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int n, a, b;
vector <int> g[N];
int dp[N][2][2][2];
int dp2[2][2][2];

void dfs(int u, int p) {
	dp[u][0][0][0] = 1;
	dp[u][1][0][0] = 1;
	dp[u][1][1][0] = 1;
	
	for (auto it : g[u]) {
		if (it == p) continue;
		
		dfs(it, u);
		
		rep(a, 0, 1) rep(b, 0, 1) rep(c, 0, 1) dp2[a][b][c] = 0;
		
		rep(a, 0, 1)
			rep(b, 0, 1)
				rep(c, 0, 1)
					rep(a0, 0, 1)
						rep(b0, 0, 1)
							rep(c0, 0, 1) {
								if (a == 0 && b + c) continue;
								if (a0 == 0 && b0 + c0) continue;
								if (a == 0 && a0 == 0) {
									add(dp2[0][0][0], (LL) dp[u][0][0][0] * dp[it][0][0][0] % MOD);
								}
								if (a == 0 && a0 == 1 && c0 == 1) {
									add(dp2[0][0][0], (LL) dp[u][0][0][0] * dp[it][a0][b0][c0] % MOD);
								}
								if (a == 1 && a0 == 0) {
									add(dp2[a][b][c], (LL) dp[u][a][b][c] * dp[it][0][0][0] % MOD);
								}
								if (a == 1 && a0 == 1) {
									 // 1.
									 if (!b || !b0)
									 add(dp2[a][b][1], (LL) dp[u][a][b][c] * dp[it][a0][b0][c0] % MOD);
									 // 2.
									 if (!c0) continue;
									 add(dp2[a][b][c], (LL) dp[u][a][b][c] * dp[it][a0][b0][c0] % MOD);
								}
							}
		rep(a, 0, 1)
			rep(b, 0, 1)
				rep(c, 0, 1)
					dp[u][a][b][c] = dp2[a][b][c];
	}
	/*printf ("node = %d\n", u);
	rep(a, 0, 1)
		rep(b, 0, 1)
			rep(c, 0, 1)
				printf ("%d %d %d %d\n", a, b, c, dp[u][a][b][c]);
	*/
}	
		

int main() {
	scanf ("%d", &n);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	int ans = 0;
	rep(a, 0, 1)
		rep(b, 0, 1)
			rep(c, 0, 1) {
				if (a == 1 && c == 0) continue;
				add(ans, dp[1][a][b][c]);
			}
	printf ("%d\n", (ans - 1 + MOD) % MOD);
	
    return 0;
}