/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int n, k;
const int N = 101234, INF = 1000 * 1000 * 1000;
int a[N], b[N];

bool is_valid (int x) {
	int nk = k;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		if (a[i] * 2 < x) {
			b[i] = INF;
			nk--;
		}
		mx = max(mx, b[i]);
	}
	if (nk < 0)
		return false;
	if (nk >= 2)
		return true;
	if (nk == 1) {
		return (mx >= x);
	} 
	mx = 0;
	for (int i = 0; i < n - 1; i++) {
		mx = max(mx, min(b[i], b[i + 1]));
	}
	return (mx >= x);
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = 0, r = 1000 * 1000 * 1000 + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (is_valid(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << '\n';
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