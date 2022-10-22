/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vector <int> v;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] > x) {
			v.push_back((a[i + 1] - a[i] - 1) / x);
		}
	}
	int ans = v.size() + 1;
	sort(v.begin(), v.end());
	for (auto y : v) {
		if (k >= y) {
			k -= y;
			ans--;
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//	cin >> t;
	while (t--) {
		solve();
	}
}