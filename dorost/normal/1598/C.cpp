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
	int n;
	cin >> n;
	map <int, int> mp;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mp[a[i]]++;
	}
	int x = (ll)(sum * 2LL) / (ll)n;
	if ((sum * 2) % n) {
		cout << 0 << ' ';
		return;
	}
	ll ans = 0;
	for (auto [o, y] : mp) {
		if (x % 2 == 0 && o == x / 2) {
			ans += (ll)y * (ll)(y - 1) / 2LL;
		} else if (o <= x / 2) {
			ans += (ll)mp[o] * (ll)mp[x - o];
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