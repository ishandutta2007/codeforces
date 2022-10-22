/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], b[N], n, c;

void solve() {
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		cin >> b[i];
	int mn = INT_MAX, s = 0, x = 0;
	for (int i = 0; i < n; i++) {
		mn = min(mn, s + ((c - x) + (a[i] - 1)) / a[i]);
		if (i == n - 1)
			continue;
		int y = ((b[i] - x) + (a[i] - 1)) / a[i];
		s += y + 1;
		x += y * a[i];
		x -= b[i];
	}
	cout << mn << ' ';
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