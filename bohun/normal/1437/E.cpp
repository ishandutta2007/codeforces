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

const int N = 5e5 + 50;

int n, m, res, a[N], b[N], dp[N];

int solve(int l, int r) {
	int len = r - l;
	fill(dp, dp + len, (1 << 30) + 1);
	dp[0] = a[l];
	if (a[l] > a[r]) {
		printf ("-1\n");
		exit(0);
	}
	rep(i, l + 1, r - 1) {
		int pos = upper_bound(dp, dp + len, a[i]) - dp;
		if (pos != 0)
			dp[pos] = a[i];
	}
	return upper_bound(dp, dp + len, a[r]) - dp - 1;
}

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) scanf ("%d", a + i), a[i] -= i;
	rep(i, 1, m) scanf ("%d", b + i);
	a[0] = -(1 << 30); a[n + 1] = 1 << 30; b[m + 1] = n + 1;
	rep(i, 1, m + 1) res += solve(b[i - 1], b[i]);
	printf ("%d\n", n - res - m);
}