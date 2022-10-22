/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 1000 * 1000 * 1000 + 7;
int a[N];

int C2(int n) {
	return (n) * (n - 1);
}

void solve() {
	int n, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn)
			x++;
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if ((a[i] & mn) != mn) {
			f = false;
		}
	}
	if (!f) {
		cout << 0 << ' ';
	} else {
		int ans = C2(x);
		ans %= M;
		for (int i = 0; i < n - 2; i++) {
			ans *= (i + 1);
			ans %= M;
		}
		cout << ans << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}