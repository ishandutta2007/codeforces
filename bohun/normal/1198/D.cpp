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

int n;
char s[55][55];
int p[55][55];

int dp[55][55][55][55];

int sum(int r1, int r2, int c1, int c2) {
	return p[r2][c2] - p[r2][c1 - 1] - p[r1 - 1][c2] + p[r1 - 1][c1 - 1];
}

int solve(int r1, int r2, int c1, int c2) {
	if (dp[r1][r2][c1][c2] != -1) return dp[r1][r2][c1][c2];
	if (sum(r1, r2, c1, c2) == 0) return 0;
	int ans = max(r2 - r1, c2 - c1) + 1;
	rep(r, r1, r2 - 1) 
		ans = min(ans, solve(r1, r, c1, c2) + solve(r + 1, r2, c1, c2));
	rep(c, c1, c2 - 1)
		ans = min(ans, solve(r1, r2, c1, c) + solve(r1, r2, c + 1, c2));
	return dp[r1][r2][c1][c2] = ans;
}
	

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%s", s[i] + 1);
		rep(j, 1, n) p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (s[i][j] == '#');
	}
	rep(i1, 1, n) rep(i2, 1, n) rep(j1, 1, n) rep(j2, 1, n) dp[i1][i2][j1][j2] = -1;
	printf ("%d\n", solve(1, n, 1, n));
	
	return 0;
}