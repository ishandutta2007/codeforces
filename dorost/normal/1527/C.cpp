/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

void solve() {
	int n, ans = 0;
	cin >> n;
	map <int, int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += (n - i) * s[a[i]];
		s[a[i]] += i + 1;
	}
	cout << ans << ' ';
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