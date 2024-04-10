/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N], n;

bool hom(int i) {
	if (i <= 0 || i >= n - 1) {
		return false;
	}
	return ((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += hom(i);
	}
	int mn = ans, x, y;
	for (int i = 0; i < n; i++) {
		int t = a[i];
		x = hom(i - 1) + hom(i) + hom(i + 1);
		a[i] = -1;
		y = hom(i - 1) + hom(i) + hom(i + 1);
		mn = min(mn, y - x + ans);
		a[i] = 1000 * 1000 * 1000 + 10;
		y = hom(i - 1) + hom(i) + hom(i + 1);
		mn = min(mn, y - x + ans);
		if (i != 0) {
			a[i] = a[i - 1];
			y = hom(i - 1) + hom(i) + hom(i + 1);
			mn = min(mn, y - x + ans);
		}
		if (i != n - 1) {
			a[i] = a[i + 1];
			y = hom(i - 1) + hom(i) + hom(i + 1);
			mn = min(mn, y - x + ans);
		}
		a[i] = t;
	}
	cout << mn << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}