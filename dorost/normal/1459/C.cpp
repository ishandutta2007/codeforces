/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			cout << x + a[0] << ' ';
		}
		return;
	}
	int gcd = a[1] - a[0];
	for (int i = 2; i < n; i++) {
		gcd = __gcd(gcd, a[i] - a[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << __gcd(gcd, a[0] + x) << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}