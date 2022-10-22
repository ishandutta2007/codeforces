/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int all = 0;
	for (int i = 0; i < n - 1; i++) {
		int x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
		int ans = -1;
		while (x < y) {
			x *= 2;
			ans++;
		}
		all += max(0, ans);
	}
	cout << all << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}