/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, O = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int mn = O;
	for (int i = 1; ; i++) {
		int ans = 0;
		int c = 1;
		bool f = true;
		for (int j = 0; j < n; j++) {
			ans += abs(c - a[j]);
			c *= i;
			if (j < n - 1 && c > O) {
				f = false;
				break;
			}
		}
		if (f) {
			mn = min(mn, ans);
		}else {
			break;
		}
	}
	cout << mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}