#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	vector<int> asum(n, 0), bsum(n, 0);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		asum[i] = asum[i - 1] + a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> b[i];
		bsum[i] = bsum[i - 1] + b[i];
	}
	vector<int> dp(n, 0);
	int stairs = 0;
	int elevators = 0;
	cout << 0 << ' ';
	for (int i = 1; i < n; i++) {
		dp[i] = min(stairs + asum[i], elevators + bsum[i] + m);
		stairs = min(stairs, dp[i] - asum[i]);
		elevators = min(elevators, dp[i] - bsum[i]);
		cout << dp[i] << ' ';
	}
	return 0;
}