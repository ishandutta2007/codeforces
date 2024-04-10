/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];
int cnt[N];
int l[N];
int n, q;

bool is_valid(int x) {
	int iq = q;
	for (int i = x; i < n; i++) {
		if (a[i] > iq)
			iq--;
	}
	return (iq >= 0);
}

void solve() {
	cin >> n >> q;
 	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	l[n] = q;
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid))
			r = mid;
		else
			l = mid;
	}
	for (int i = 0; i < r; i++) {
		cout << (a[i] <= q);
	}
	for (int i = r; i < n; i++)
		cout << 1;
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