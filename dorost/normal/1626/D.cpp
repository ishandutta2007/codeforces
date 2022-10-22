/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n + 10; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;
	int mn = INT_MAX;
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 18; j++) {
			int x = (1 << i);
			int y = (1 << j);
			int c = 0, c2 = 0;
			int in2 = n + 1;
			for (int k = 0; k <= n; k++) {
				c += cnt[k];
				if (c > x) {
					in2 = k - 1;
					c -= cnt[k];
					break;
				}
			}
			for (int k = n; k >= in2; k--) {
				c2 += cnt[k];
				if (c2 > y) {
					c2 -= cnt[k];
					break;
				}
			}
			int s = (n - c - c2);
			int z = 1;
			while (z < s)
				z *= 2;
			mn = min(mn, z - s + x - c + y - c2);
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