/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		int ans = 0;
		int x = (a[i] == 0);
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] == 0)
				x++;
			else 
				ans += x, x = 0;
		}
		x = (a[i] == 0);
		for (int j = i + 1; j < n; j++) {
			if (a[j] == 0)
				x++;
			else 
				ans += x, x = 0;
		}
//		cout << i << ' ' << ans << '\n';
		mn = min(mn, ans);
	}
	cout << mn << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}