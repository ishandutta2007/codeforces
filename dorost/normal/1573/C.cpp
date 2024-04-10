/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int dp[N];
vector <int> a[N];

int ans(int i) {
	if (dp[i] != -1)
		return dp[i];
	dp[i] = N;
	int mx = 1;
	for (int j = 0; j < a[i].size(); j++) {
		if (a[i][j] < i) 
			mx = max(mx, ans(a[i][j]));
		else
			mx = max(mx, ans(a[i][j]) + 1);
	}
	return dp[i] = mx;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		dp[i] = -1;
		a[i].clear();
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			x--;
			a[i].push_back(x);
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, ans(i));
	}
	if (mx >= N)
		cout << -1 << ' ';
	else
		cout << mx << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}