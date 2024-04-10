/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N], all[2 * N], n;
pair <int, int> bb[N];

int bs(int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (bb[mid].F >= x) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (b[bb[l].S] != x) {
	//	cout << x << ' ' << b[bb[l].S] << '\n';
		return 2 * n;
	} else {
		return bb[l].S;
	}
}

void solve() {
	int x = 0;
	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		cin >> all[i];
		if (all[i] == 1) 
			x++;
		else {
			x--;
			all[i] = -1;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) 
			a[n - i - 1] = all[i];
		else
			a[n - i - 1] = a[n - i - 2] + all[i];
	}
	for (int i = n; i < 2 * n; i++) {
		if (i == n)
			b[i - n] = all[i];
		else
			b[i - n] = b[i - n - 1] + all[i];
		bb[i - n] = {b[i - n], i - n};
	}
	if (x == 0) {
		cout << 0 << ' ';
		return;
	}
	sort(bb, bb + n);
	int mn = 2 * n;
	for (int i = -1; i < n; i++) {
		int y = x - (i == -1 ? 0 : a[i]); // a[i] + y == x -> y = x - a[i]
//		cout << a[i] << ' ' << y << ' ' << i << ' ' << bs(y) << endl;
//		cout << x << ' ' << a[i] << endl;
		mn = min(mn, i + (y == 0 ? -1 : bs(y)) + 2);
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