/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, INF = N * N * 10000LL;
int a[N], dp[N][2], n;
string s[N];

int ans(int x, bool r) {
	if (dp[x][r] != -1)
		return dp[x][r];
	if (x == n)
		return 0;
	int mn = INF;
	if (r) {
		reverse(s[x - 1].begin(), s[x - 1].end());
	}
	if (x == 0 || s[x] >= s[x - 1]) {
		if (x != 0 && r)
			reverse(s[x - 1].begin(), s[x - 1].end());
		mn = min(mn, ans(x + 1, 0));
	} else {
		if (r) 
			reverse(s[x - 1].begin(), s[x - 1].end());
	}
	if (r) {
		reverse(s[x - 1].begin(), s[x - 1].end());
	}
	reverse(s[x].begin(), s[x].end());
	if (x == 0 || s[x] >= s[x - 1]) {
		if (x != 0 && r) {
			reverse(s[x - 1].begin(), s[x - 1].end());
		}
		reverse(s[x].begin(), s[x].end());
		mn = min(mn, ans(x + 1, 1) + a[x]);
	} else {
		if (r) {
			reverse(s[x - 1].begin(), s[x - 1].end());
		}
		reverse(s[x].begin(), s[x].end());
	}
	return dp[x][r] = mn;
}

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cout << (ans(0, 0) == INF ? -1 : ans(0, 0));
}