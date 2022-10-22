/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int x[N], ss[N];

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	ss[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		ss[i] = ss[i + 1] + x[i];
	}
	int mn = ss[0] * b;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += b * (x[i] - (i == 0 ? 0 : x[i - 1]));
		ans += a * (x[i] - (i == 0 ? 0 : x[i - 1]));
		mn = min(mn, ans + b * (ss[i + 1] - x[i] * (n - i - 1)));
	}
	cout << mn << '\n';
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