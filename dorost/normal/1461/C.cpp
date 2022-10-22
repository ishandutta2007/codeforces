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
int a[N], r[N];
ld p[N];

void solve() {
	cout << fixed << setprecision(12);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> r[i] >> p[i];
	}
	ld x = 1;
	int mn = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != i + 1) {
			mn = i + 1;
			break;
		}
	}
	if (mn == 0) {
		cout << 1 << '\n';
		return;
	}
	for (int i = 0; i < m; i++) {
		if (r[i] >= mn) {
			x *= 1 - p[i];
		}
	}
	cout << 1 - x << '\n';
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