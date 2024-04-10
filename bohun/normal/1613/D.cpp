#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int N = 500500;
const int P = 998244353;

void add(int &a, int b) {
	a = (a + b) % P;
}

int n, a[N], dp[N][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		rep(i, 1, n)
			cin >> a[i];

		rep(i, 0, n)
			dp[i][0] = dp[i][1] = 0;

		dp[0][0] = 1;

		rep(i, 1, n) {
			if (a[i] >= 1) {
				add(dp[a[i] - 1][1], dp[a[i] - 1][1]);
				add(dp[a[i] - 1][1], dp[a[i] - 1][0]);
			}

			add(dp[a[i] + 1][0], dp[a[i] + 1][0]);
			add(dp[a[i] + 1][0], dp[a[i]][0]);
			add(dp[a[i] + 1][1], dp[a[i] + 1][1]);
		}

		int res = 0;
		rep(i, 0, n) {
			add(res, dp[i][0]);
			add(res, dp[i][1]);
		}

		cout << (res + P - 1) % P << "\n";
	}
	return 0;
}