#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 1024;
const int M = 30 * N;
int n, k, b[N], c[N], f[N], dp[M];

void solve() {
	cin >> n >> k;
	rep(i, 1, n) cin >> b[i];
	rep(i, 1, n) cin >> c[i];
	dp[0] = 0;
	rep(i, 1, M - 1) dp[i] = -1e9;
	rep(i, 1, n) {
		int w = f[b[i]];
		per(j, 0, M - 1 - w) {
			dp[j + w] = max(dp[j + w], dp[j] + c[i]);
		}
	}
	int res = 0;
	rep(i, 0, min(k, M - 1)) res = max(res, dp[i]);
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 2, 1000) f[i] = 1e9;
	rep(i, 1, 1000) {
		rep(j, 1, i) {
			int x = i + i / j;
			if (x > 1000) continue;
			f[x] = min(f[x], f[i] + 1);
		}
	}
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}