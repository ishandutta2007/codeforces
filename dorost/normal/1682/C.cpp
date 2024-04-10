/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	map <int, int> cnt;
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++, mx = max(mx, a[i]);
	int ans = 0;
	for (pair <int, int> p : cnt) {
		ans += (min(2, p.S));
	}
	cout << (ans + 1) / 2 << '\n';
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