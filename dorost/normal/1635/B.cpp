/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];
bool f[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], f[i] = false;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			f[i] = true;
	}
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		if (f[i] && f[i + 2]) {
			f[i] = false;
			f[i + 2] = false;
			ans++;
			a[i + 1] = max(a[i], a[i + 2]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (f[i]) {
			a[i] = max(a[i - 1], a[i + 1]);
			ans++;
			f[i] = false;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
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