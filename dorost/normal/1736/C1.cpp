/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= (i + 1);
	}
	ll ans = 0;
	int lst = -1;
	for (int i = 0; i < n; i++) {
		while (lst != n - 1 && a[lst + 1] >= (-1 * i))
			lst++;
		ans += (lst - i + 1);
	}
	cout << ans << '\n';
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