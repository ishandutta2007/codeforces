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
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 5005;

int n, m, dp[N][N];
char s[N], t[N];

int main() {
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	int res = 0;
	rep(i, 1, n)
		rep(j, 1, m) {
			if (s[i] == t[j])
				dp[i][j] = 2 + dp[i - 1][j - 1];
			dp[i][j] = max(dp[i][j], -2 + dp[i - 1][j - 1]);
			dp[i][j] = max(dp[i][j], -1 + dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], -1 + dp[i][j - 1]);
			res = max(res, dp[i][j]);
		}
	printf ("%d\n", res);
			
	
	return 0;
}