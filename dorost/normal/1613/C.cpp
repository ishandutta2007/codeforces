/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 102;
int a[N];

void solve() {
	ll n, h;
	cin >> n >> h;
	vector <ll> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0)
			v.push_back(a[i] - a[i - 1]);
	}
	v.push_back(h + a[n - 1]);
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int d = n - i;
		if (d * (v[i] - (i == 0 ? 0 : v[i - 1])) >= h) {
			ans +=	(h + d - 1) / d;
			h = 0;
			break;
		} else {
			ans += (v[i] - (i == 0 ? 0 : v[i - 1]));
			h -= d * (v[i] - (i == 0 ? 0 : v[i - 1]));
		}
	}
	cout << ans << ' ';
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