/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 50123;
int a[N], b[N], n, m, k;

int f(int x) {
	int wef = x;
	while (wef % m == 0)
		wef /= m;
	return wef;
}

void solve() {
	vector <pair <ll, int>> va, vb;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++) 
		cin >> b[i];
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n) {
			va.push_back({sum, f(a[i - 1])});
			break;
		}
		int x = f(a[i]);
		int y = x;
		if (i != 0)
			y = f(a[i - 1]);
		if (((x != y))) {
			va.push_back({sum, y});
			sum = 0;
		}
		sum += a[i];
	}
	sum = 0;
	for (int i = 0; i <= k; i++) {
		if (i == k) {
			vb.push_back({sum, f(b[i - 1])});
			break;
		}
		int x = f(b[i]);
		int y = x;
		if (i != 0)
			y = f(b[i - 1]);
		if (((x != y))) {
			vb.push_back({sum, y});
			sum = 0;
		}
		sum += b[i];
	}
	cout << (va == vb ? "Yes" : "No") << '\n';
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