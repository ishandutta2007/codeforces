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

int n, ans[1 << 20], dp[1 << 20][2];
char s[1 << 20];

void solve() {
	scanf("%d%s", &n, s + 1);
	rep(i, 1, n) {
		if (s[i] == 'L') {
			dp[i][1] = 1 + dp[i - 1][0];
			dp[i][0] = 0;
		}
		else {
			dp[i][0] = 1 + dp[i - 1][1];
			dp[i][1] = 0;
		}
	}
	rep(i, 0, n)
		ans[i] = dp[i][1];
	dp[n + 1][0] = dp[n + 1][1] = 0;
	per(i, 1, n) {
		if (s[i] == 'L') {
			dp[i][1] = 1 + dp[i + 1][0];
			dp[i][0] = 0;
		}
		else {
			dp[i][0] = 1 + dp[i + 1][1];
			dp[i][1] = 0;
		}
	}
	rep(i, 0, n) {
		ans[i] += dp[i + 1][0];
		printf("%d ", ans[i] + 1);
	}
	puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}