#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int n, a[709], dp[709][709][3], par[709][709];

int solve(int l, int r, int mask) {
	if (l > r) return 1;
	if (dp[l][r][mask] >= 1) return dp[l][r][mask];

	dp[l][r][mask] = 0;
	for (int i = l; i <= r; i++) {
		bool flag = true;
		if (mask == 1 && par[r + 1][i] == 0) flag = false;
		if (mask == 2 && par[l - 1][i] == 0) flag = false;

		if (flag == true) {
			int V1 = solve(l, i - 1, 1);
			int V2 = solve(i + 1, r, 2);
			if (V1 == 1 && V2 == 1) { dp[l][r][mask] = 1; break; }
		}
	}
	if (dp[l][r][mask] == 0) dp[l][r][mask] = 2;
	return dp[l][r][mask];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { if (gcd(a[i], a[j]) >= 2) par[i][j] = 1; } }

	solve(1, n, 0);
	if (dp[1][n][0] == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}