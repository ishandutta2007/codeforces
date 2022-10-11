#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)

long long a[1000009], n, k, l, ret, mod = 1000000007; vector<int>V; vector<long long>dp[1000009];
int main() {
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < l%n; i++)V.push_back(a[i]); sort(V.begin(), V.end()); sort(a, a + n);
	vector<long long>F(n + 1, 0); for (int i = 0; i <= k; i++)dp[i] = F;
	for (int i = 0; i <= n; i++)dp[0][i] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			int pos1 = lower_bound(a, a + n, a[j] + 1) - a; pos1--;
			if (pos1 >= 0)dp[i][j] = dp[i - 1][pos1];
		}
		for (int j = 1; j <= n; j++) { dp[i][j] += dp[i][j - 1]; dp[i][j] %= mod; }
	}
	for (long long i = 1; i <= k; i++) {
		ret += (max(0LL, ((l / n) - i + 1)) % mod)*dp[i][n];
		for (int j = 0; j < V.size(); j++) {
			int pos1 = lower_bound(a, a + n, V[j] + 1) - a; pos1--;
			if (pos1 >= 0 && (l / n) >= i - 1)ret += dp[i - 1][pos1];
		}
		ret %= mod;
	}
	cout << ret << endl;
	return 0;
}