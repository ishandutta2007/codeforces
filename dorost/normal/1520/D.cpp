/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], cnt[2 * N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n + 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
		a[i] += n;
		cnt[a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < 2 * n + 10; i++) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
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