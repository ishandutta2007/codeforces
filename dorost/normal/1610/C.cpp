/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N];
int n;

bool is_valid(int x) {
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		if (a[i] + b[i] + 1 < x)
			continue;
		v.push_back({a[i], b[i]});
	}
	int c = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].S >= c && v[i].F >= (x - c - 1)) {
			c++;
		}
		if (c == x)
			return true;
	}
	return false;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int l = 1, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << ' ';
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