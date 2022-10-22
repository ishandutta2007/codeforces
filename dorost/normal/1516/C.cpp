/* 	* In the name of GOD 
	* Ftr max vhwxyhkvxl ux pbma rhn :)) */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105, M = 2005;
int a[N], dp[N][N * M], n;

bool ans(int i, int sum) {
	if (sum < 0)
		return false;
	if (sum == 0)
		return true;
	if (i >= n)
		return false;
	if (dp[i][sum] != -1) {
		return bool(dp[i][sum]);
	}
	return dp[i][sum] = (ans(i + 1, sum) || ans(i + 1, sum - a[i]));
}

void solve() {
	cin >> n;
	bool f = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2)
			f = false;
	}
	while (f) {
		for (int i = 0; i < n; i++) {
			a[i] /= 2;
			if (a[i] % 2)
				f = false;
		}
	}
	bool h = true;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			h = false;
		}
		sum += a[i];
	}
	if (h) {
		if (n % 2) {
			cout << 0;
			return;
		}
	}
	if (sum % 2) {
		cout << 0;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * M; j++) {
			dp[i][j] = -1;
		}
	}
	if (ans(0, sum / 2)) {
		cout << "1\n";
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) {
				cout << i + 1;
				break;
			}
		}
	} else {
		cout << 0;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}