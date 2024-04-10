/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N	= 1022;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = *min_element(a, a + n), ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != mn)
			ans++;
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}