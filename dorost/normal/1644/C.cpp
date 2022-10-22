/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
int a[N], mx[N];
int ps[N];

void solve() {
	int n, x;
	cin >> n >> x;
	ps[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ps[i + 1] = ps[i] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		mx[i] = INT_MIN;
	}
	mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			mx[i] = max(mx[i], ps[j + i] - ps[j]);
		}
	}
	for (int i = 0; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j <= n; j++) {
			ans = max(ans, min(j, i) * x + mx[j]);
		}
		cout << ans << ' ';
	}
	cout << '\n';
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