#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[10000], d[1000][1000];
vector<int>x[10000];
vector<pair<int, int>>dp[1000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++)d[i][j] += a[k];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			int sum = d[j][i - 1];
			if (sum == 0)continue;
			if (dp[i].size() == 0) { dp[i] = dp[j]; dp[i].push_back(make_pair(j + 1, i)); }
		}
	}
	if (dp[n].size() == 0)cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << dp[n].size() << endl;
		for (int i = 0; i < dp[n].size(); i++) {
			cout << dp[n][i].first << ' ' << dp[n][i].second << endl;
		}
	}
	return 0;
}