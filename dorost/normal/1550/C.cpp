/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ms[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int as = 0;
	for (int i = 0; i < n; i++) {
		bool f = true;
		int ans = i;
		for (int j = i + 1; j < n && f; j++) {
			for (int x = i; x <= j && f; x++) {
				for (int y = x + 1; y <= j && f; y++) {
					for (int z = y + 1; z <= j && f; z++) {
						if ((a[x] >= a[y] && a[y] >= a[z]) || (a[x] <= a[y] && a[y] <= a[z])) {
//							cout << j << ' ' << a[x] << ' ' << a[y] << ' ' << a[z] << '\n';
							f = false;
							ans = j - 1;
							break;
						}
					}
				}
			}
			if (j == n - 1 && f) {
				ans = n - 1;
			}
		}
		as += ans - i + 1;
//		cout << ans << '\n';
	}
	cout << as << ' ';
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