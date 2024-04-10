/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N];

void solve() {
	int n;
	cin >> n;
	int ans = n * (n - 1) / 2;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] % 2 && a[j] % 2 && __gcd(a[i], a[j]) == 1)
				ans--;
		}
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