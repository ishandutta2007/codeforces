/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1003;
int a[N];

void solve() {
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= l && a[i] <= r) {
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	int x = 0;
	for (int i = 0; i < v.size(); i++) {
		k -= v[i];
		if (k < 0) {
			break;
		}
		x++;
	}
	cout << x << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}