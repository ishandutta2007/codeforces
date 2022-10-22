/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mkp make_pair
const int N = 101234;
int a[N];

void solve() {
	int cnt0 = 0, p0 = 0, p1 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			cnt0++;
	}
	int ans = min(cnt0, n - cnt0);
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			p0++;
		else
			p1++;
		ans = min(ans, max(p1, cnt0 - p0));
	}
	cout << ans << '\n';
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