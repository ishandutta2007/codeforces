/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 42, M = 1000 * 1000 * 1000 + 7;
int l[N];

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i < 42; i++) {
		if (i == 41) {
			ans += (n / l[i]) * 42;
		} else {
			ans += (n / l[i] - n / l[i + 1]) * (i + 1);
		}
		ans %= M;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	l[1] = 1;
	for (int i = 2; i < N; i++) {
		l[i] = (l[i - 1] * i) / __gcd(l[i - 1], i);
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}