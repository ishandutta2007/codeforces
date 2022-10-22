/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012;
int a[N * N], b[N][N];

void solve() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n * k; i++) {
		cin >> a[i];
	}
	reverse(a, a + n * k);
	for (int i = 0; i < k; i++) {
		ans += a[((n) / 2 + 1) * (i + 1) - 1];
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