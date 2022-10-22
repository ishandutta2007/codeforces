/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 71;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = n - 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int p = a[j] - a[i], q = j - i;
			int x = __gcd(p, q);
			p /= x;
			q /= x;
			int ans = 0;
			for (int k = 0; k < n; k++) {
				if (((k - i) * p) % q) {
					ans++;
				} else {
					if (a[k] != (k - i) * p / q + a[i]) 
						ans++;
				}
			}
			mn = min(mn, ans);
		}
	}
	cout << mn << ' ';
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