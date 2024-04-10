/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
#define int long long
int a[N], ps[N];

void solve() {
	int n, k, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	ps[0] = 0;
	ps[1] = a[1];
	for (int i = 2; i < n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		int ans = n - 1 - i;
		if ((k - ps[i]) > 0)
			ans += max(0LL, (a[0] - ((k - ps[i]) / (n - i))));
		else
			ans += max(0LL, (a[0] - ((k - ps[i] - (n - i) + 1) / (n - i))));
		mn = min(mn, ans);
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}