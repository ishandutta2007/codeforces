#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1005, M = 10005;
 
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'
 
typedef long long ll;
 
template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
 
ll dp[N][M];
int c[N];
ll cost[N];
 
void relax(ll &u, ll v) {
	u = max(u, v);
}
 
void solve() {
	int n = read();
	ll W = read(), B = read(), X = read();
 
	forn(i, n) c[i] = read();
	forn(i, n) cost[i] = read();
 
	fill_n(&dp[0][0], N * M, -1);
	dp[0][0] = W;
 
	forn(i, n)
		for (int j = 0; j < M && dp[i][j] != -1; j++)
			for (int k = 0; k <= c[i] && dp[i][j] - k * cost[i] >= 0; k++)
				relax(dp[i + 1][k + j], min(W + (k + j) * B, dp[i][j] - k * cost[i] + X));
 
	int ans = 0;
	forn(i, M)
		if (dp[n][i] != -1)
			ans = max(ans, i);
 
	printf("%d\n", ans);
}
 
signed main() {
	int t = 1;
 
	while (t--) {
		clock_t z = clock();
		solve();
		debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
}