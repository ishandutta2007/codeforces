/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
pair <int, int> a[N];
int ans[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	ll ansa = 0;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) {
		ans[a[i].S + 1] = (i / 2 + 1) * (i % 2 ? 1 : -1);
		ansa += (i / 2 + 1) * a[i].F;
	}
	cout << ansa * 2LL << '\n';
	ans[0] = 0;
	for (int i = 0; i <= n; i++)
		cout << ans[i] << ' ';
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