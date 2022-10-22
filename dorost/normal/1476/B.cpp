/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 112;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = a[0], mx = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] * 100 >= sum * k) {
			mx = max(mx, (a[i] * 100 - sum * k) / k + (((a[i] * 100 - sum * k) % k) >= 1));
		}
		sum += a[i];
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