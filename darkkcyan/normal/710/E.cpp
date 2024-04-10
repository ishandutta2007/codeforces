#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
int main() {
	long long n, x, y; cin >> n >> x >> y;
	dp.push_back(0);
	dp.push_back(x);
	for (int i = 2; i <= n; ++i)
		dp.push_back(min(dp[i - 1] + x, dp[(i + 1) / 2] + y + (i & 1) * x));
	cout << dp[n];
	return 0;
}