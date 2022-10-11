#include <iostream>
using namespace std;

long long dp[1009][1009], a[1009], n, mod = 998244353;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i - 1][j] == 0) continue;
			if (j == 0 && a[i] >= 1 && a[i] <= n) { dp[i][a[i]] += dp[i - 1][j]; dp[i][a[i]] %= mod; }
			else { dp[i][j - 1] += dp[i - 1][j]; dp[i][j - 1] %= mod; }
			dp[i][j] += dp[i - 1][j]; dp[i][j] %= mod;
		}
	}
	cout << (dp[n][0] + mod - 1) % mod << endl;
	return 0;
}