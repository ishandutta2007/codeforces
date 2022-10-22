/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N], cnt[N], cnt2[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		cnt[a[i]]++;
		cnt2[b[i]]++;
	}
	ll ans = ((ll)n * (ll)(n - 1) * (ll)(n - 2)) / 6LL;
	for (int i = 0; i < n; i++) {
		ans -= (ll)(cnt[a[i]] - 1) * (ll)(cnt2[b[i]] - 1);
	}
	cout << ans << ' ';
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		cnt2[i] = 0;
	}
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