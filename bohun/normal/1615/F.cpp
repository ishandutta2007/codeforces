#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int P = 1e9 + 7;

void add(int &a, int b) {
	a = (a + b) % P;
}

void solve() {
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1));
	vector<vector<int>> dp_res(n + 1, vector<int>(2 * n + 1));
	dp[0][n] = 1;

	for (int i = 0; i < n; i++) {
		int A = (a[i] == '?' ? 3 : (1 << (a[i] - '0')));
		int B = (b[i] == '?' ? 3 : (1 << (b[i] - '0')));

		if (i % 2 == 0) {
			if (A < 3) A = (A == 1 ? 2 : 1);
			if (B < 3) B = (B == 1 ? 2 : 1);
		}

		for (int d = 1; d < 2 * n; d++) {
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					if (!(A >> x & 1)) continue;
					if (!(B >> y & 1)) continue;

					int new_d = d;
					int res = 0;

					if (x) {
						new_d++;
						if (new_d <= n) 
							add(res, i);
						else 
							add(res, P - i);
					}

					if (y) {
						new_d--;
						if (new_d >= n) 
							add(res, i);
						else 
							add(res, P - i);
					}

					res = 1ll * res * dp[i][d] % P;
					add(res, dp_res[i][d]);

					add(dp[i + 1][new_d], dp[i][d]);
					add(dp_res[i + 1][new_d], res);
				}
			}
		}
	}

	cout << dp_res[n][n] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}