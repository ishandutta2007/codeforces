#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int P = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> ones = {-1};
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			ones.push_back(i);
	ones.push_back(n);

	if (k == 0 || ones.size() - 2 < k) {
		cout << 1 << '\n';
		return 0;
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % P;
	}

	int res = dp[ones[k + 1] - ones[0] - 1][k];
	for (int i = 2; i + k < ones.size(); i++) {
		res = (res + dp[ones[k + i] - ones[i - 1] - 1][k]) % P;
		res = (res + P - dp[ones[k + i - 1] - ones[i - 1] - 1][k - 1]) % P;
	}

	cout << res << '\n';
	return 0;
}