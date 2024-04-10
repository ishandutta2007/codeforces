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

const int N = 1e5 + 50;

int r, n;
int t[N], x[N], y[N], dp[N], mx[N];

int main() {
	scanf ("%d%d", &r, &n);
	x[0] = y[0] = 1;
	rep(i, 1, n) {
		scanf ("%d%d%d", t + i, x + i, y + i);
		rep(j, max(0, i - r - r), i - 1)
			if (t[j] + abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] && x[j] - 1 + y[j] - 1 <= t[j])
				dp[i] = max(dp[i], dp[j] + 1);
		if (i - r - r > 0)
			dp[i] = max(dp[i], mx[i - r - r - 1] + 1);
		mx[i] = max(mx[i - 1], dp[i]);
		//~ cat(dp[i]);
	}
	printf ("%d\n", mx[n]);
	return 0;
}