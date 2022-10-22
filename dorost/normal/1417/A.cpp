/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int a[N];

void solve() {
	int n, k, mn = INT_MAX, an = -1, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < mn) {
			mn = a[i];
			an = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == an)
			continue;
		ans += (k - a[i]) / mn;
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}