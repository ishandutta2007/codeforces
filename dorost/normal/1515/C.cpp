/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <int, int> a[N];
int ans[N];

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i].F, a[i].S = i;
	cout << "YES\n";
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ans[a[i].S] = i % m + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}