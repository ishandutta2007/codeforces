/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int v[N];
int n, m;

bool is_valid (int x) {
	int cntg = 0, cntb = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] > x) {
			cntb += (v[i] - x);
		} else {
			cntg += (x - v[i]) / 2;
		}
	}
	return (cntg >= cntb);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		v[i] = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v[x]++;
	}
	int l = 0, r = 2 * m + 2;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << ' ';
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