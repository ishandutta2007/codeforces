#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>
#define ull unsigned long long

using namespace std;

const int N = 110;
const int K = 25;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n, k;
int a, b;
vector <int> v[N];

int dp[N][K][K];
int dp2[K][K]; 
// node, najglebszy niespel, najplytszy czarny
// dystans to liczba wierzolkw 

int qw1(int i1, int j1, int i2, int j2) {
	bool ok1 = (i1 + j2 <= k || i1 == 0);
	bool ok2 = (i2 + j1 <= k || i2 == 0);
	if (!ok1 && !ok2) return max(i1, i2 + 1);
	if (!ok1 && ok2) return i1;
	if (ok1 && !ok2) return i2 + 1;
	return 0;
}

int qw2(int i1, int j1, int i2, int j2) {
	return min(k + 1, min(j1, j2 + 1));
}

void dfs(int u, int p) {
	dp[u][1][k + 1] = 1;
	dp[u][0][1] = 1;
	
	for (auto it : v[u]) {
		if (it == p) continue;
		dfs(it, u);
		
		rep(i, 0, k) rep(j, 0, k + 1) dp2[i][j] = 0;
		
		rep(i1, 0, k)
			rep(i2, 0, k)
				rep(j1, 0, k + 1)
					rep(j2, 0, k + 1) {
						if (!dp[u][i1][j1] || !dp[it][i2][j2]) continue;
						int g = qw1(i1, j1, i2, j2);
						int p = qw2(i1, j1, i2, j2);
						//printf ("%d %d %d %d %d %d %d\n", i1, j1, i2, j2, g, p, dp[u][i1][j1] * dp[it][i2][j2] % MOD);
						add(dp2[g][p], (LL) dp[u][i1][j1] * dp[it][i2][j2] % MOD);
					}
					
		rep(i, 0, k) rep(j, 0, k + 1) dp[u][i][j] = dp2[i][j];
	}
	
	/*printf ("node = %d\n", u);
	rep(i, 0, k) 
		rep(j, 0, k + 1) {
			if (!dp[u][i][j]) continue;
			printf ("%d %d %d\n", i, j, dp[u][i][j]);
		}
	printf ("\n");
	*/
}	

int main() {
	scanf ("%d%d", &n, &k);
	k++;
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	int ans = 0;
	rep(j, 0, k + 1) add(ans, dp[1][0][j]);
	printf ("%d\n", ans);
	
	
	return 0;
}