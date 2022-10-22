/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012345;
int a[N];

void solve() {
	int k, n;
	string s;
	cin >> k >> s;
	n = s.size();
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			a[i + 1] = s[i] - '0';
		else
			a[i + 1] = s[i] - '0' + a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += lower_bound(a + i + 1, a + n + 1, a[i] + k + 1) - lower_bound(a + i + 1, a + n + 1, a[i] + k);
	}
	cout << ans;
}

int32_t main() {
	solve();
}