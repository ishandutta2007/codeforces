/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], b[N], c[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int mx = 0;
	for (int i = n - 1; i > 0; i--) {
		int ans = c[i] - 1;
		while (true) {
			i--;
			ans += 2;
			if (i == 0) {
				ans += (abs(a[1] - b[1]));
				break;
			}
			if (a[i + 1] == b[i + 1]) {
				break;
			}
			ans += abs(a[i + 1] - b[i + 1]);
			mx = max(mx, ans);
			ans -= abs(a[i + 1] - b[i + 1]);
			ans += (c[i] - 1) - abs(a[i + 1] - b[i + 1]);
			ans = max(ans, c[i] - 1);
		}
		i++;
		mx = max(mx, ans);
	}
	cout << mx << '\n';
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