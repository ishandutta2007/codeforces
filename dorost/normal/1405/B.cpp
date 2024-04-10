/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	int x = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x += a[i];
		if (x < 0) {
			ans += -x;
			x = 0;
		}
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