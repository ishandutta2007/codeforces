/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <int, int> a[N];
int ans[N];
bool f[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
		if (a[i].F < 0)
			f[i] = true;
		else
			f[i] = false;
		a[i].F = abs(a[i].F);
	}
	sort(a, a + n);
	for (int i = (n % 2 ? 3 : 0); i < (n); i += 2) {
		int x = a[i].F, y = a[i + 1].F;
		int u = __gcd(x, y);
		x /= u;
		y /= u;
		ans[a[i + 1].S] = x * (f[a[i + 1].S] ? -1 : 1);
		ans[a[i].S] = -1 * y * (f[a[i].S] ? -1 : 1);
	}
	if (n % 2) {
		int x = a[0].F, y = a[1].F, z = a[2].F;
		int u = __gcd(__gcd(x, y), z);
		x /= u;
		y /= u;
		z /= u;
		ans[a[0].S] = y * z * (f[a[0].S] ? -1 : 1);
		ans[a[1].S] = x * z * (f[a[1].S] ? -1 : 1);
		ans[a[2].S] = -2 * x * y * (f[a[2].S] ? -1 : 1);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
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