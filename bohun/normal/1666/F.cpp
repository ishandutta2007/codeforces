#include<bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 5050;
const int P = 998244353;

void add(int &a, int b) {
	a = (a + b) % P;
}

int n, c[N], dp[N][N], C[N][N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) c[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i = 1; i <= n + 1; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 0;
	dp[n + 1][0] = 1;

	int sum = 0;
	for (int i = n; 1 <= i; i--) {
		for (int j = 0; j <= n; j++) {
			if (dp[i + 1][j] == 0) continue;
			//cout << i << " " << j << " " << dp[i][j] << endl;
			int all_holes = max(0, j - 1);
			int av_holes = all_holes - (sum - j) + (j == n / 2);
			assert(av_holes >= 0);
			if (c[i] > 0) {
				add(dp[i][j + 1], 1LL * dp[i + 1][j] * C[av_holes][c[i] - 1] % P);
			}
			add(dp[i][j], 1LL * dp[i + 1][j] * C[av_holes][c[i]] % P);
		}
		sum += c[i];
	}

	cout << dp[1][n / 2] << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}