/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1100;
int a[N];

void solve() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cout << (a[0] + a[1] <= d || a[n - 1] <= d ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}