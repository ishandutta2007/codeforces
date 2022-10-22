/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int  long long
const int N = 1012;
int a[N];

void solve() {
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	int x = 0;
	int b = a[0] + a[1];
	x += (h / b) * 2;
	h %= b;
	if (h <= 0) {
		cout << x << '\n';
		return;
	}
	for (int i = 0; ; i++) {
		h -= a[0];
		x++;
		if (h <= 0) {
			cout << x << '\n';
			return;
		}
		h -= a[1];
		x++;
		if (h <= 0) {
			cout << x << '\n';
			return;
		}
	}
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