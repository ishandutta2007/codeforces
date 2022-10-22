/* 	* In the name of GOD *  */

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5000;
ll dp[N][N];
int a[N], b[N];

inline ll ansswap(int l, int r) {
	return ((ll)a[r] * (ll)b[l] + (ll)a[l] * (ll)b[r]) - ((ll)a[l] * (ll)b[l] + (ll)a[r] * (ll)b[r]);
}

inline ll ans(int l, int r) {
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	if (l == r) {
		return 0;
	}
	if (l == r - 1) {
		return dp[l][r] = ansswap(l, r);
	}
	return dp[l][r] = ansswap(l, r) + ans(l + 1, r - 1);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	int n;
	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s += (ll)a[i] * (ll)b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ans(i, j);
		}
	}
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx + s;
}