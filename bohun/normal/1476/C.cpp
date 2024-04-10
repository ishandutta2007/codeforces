#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, a[N], b[N], c[N];
ll dp[N];

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", c + i);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) scanf("%d", b + i);
	ll ans = 0;
	dp[0] = -(1LL << 60);
	rep(i, 1, n - 1) {
		dp[i] = abs(a[i + 1] - b[i + 1]);
		if (a[i + 1] != b[i + 1]) {
			ll cur = min(a[i + 1], b[i + 1]) - 1 + c[i] - max(a[i + 1], b[i + 1]) + 2 + dp[i - 1];
			dp[i] = max(dp[i], cur);
		}
		ans = max(ans, c[i + 1] + dp[i] + 1);
	}
	printf("%lld\n", ans);
}
	

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}