#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[505][505], n, a[10000];
int solve(int L, int R) {
	if (dp[L][R] != -1)return dp[L][R];
	if (L >= R)return 1;
	int maxn = solve(L, R - 1) + 1;
	maxn = min(maxn, solve(L + 1, R) + 1);
	if (a[L] == a[R])maxn = min(maxn, solve(L + 1, R - 1));
	for (int i = L + 1; i < R; i++) {
		if (a[L] == a[i])maxn = min(maxn, solve(L + 1, i - 1) + solve(i + 1, R));
		if (a[i] == a[R])maxn = min(maxn, solve(L, i - 1) + solve(i + 1, R - 1));
	}
	dp[L][R] = maxn;
	return maxn;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < 505; i++) { for (int j = 0; j < 505; j++)dp[i][j] = -1; }
	cout << solve(0, n - 1) << endl;
	return 0;
}