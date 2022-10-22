/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], v[N], ov[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n + 5; i++)
		v[i] = 0, ov[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]]++;
		ov[a[i]]++;
	}
	int wef = n - 1;
	while (wef >= 1 && a[wef] >= a[wef - 1])
		wef--;
	if (wef == 0) {
		cout << 0 << '\n';
		return;
	}
	int all = 0, none = 0;
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (v[a[i]] == ov[a[i]])
			none++;
		v[a[i]]--;
		if (v[a[i]] == 0)
			all++;
		if ((i >= wef - 1) && (none == all)) {
			ans = all;
			break;
		}
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