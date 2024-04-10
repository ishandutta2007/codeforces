#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int MOD = 998244353;
const int N = 5050;

int j, n, a[N];
ll dp[N][N], sum[N][N];

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	sort(a + 1, a + n + 1);
	dp[1][0] = sum[1][0] = 1;
	rep(i, 2, n) {
		while (2 * a[j + 1] <= a[i]) j++;
		dp[i][0] = 1;
		sum[i][0] = (dp[i][0] + sum[i - 1][0]) % MOD;
		rep(k, 1, j) {
			dp[i][k] = (dp[i][k - 1] * (j - (k - 1)) % MOD + sum[j][k - 1]) % MOD;
			sum[i][k] = (dp[i][k] + sum[i - 1][k]) % MOD;
		}
	}
	printf ("%lld\n", dp[n][n - 1]);
}