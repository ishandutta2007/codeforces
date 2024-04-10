/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N], w[2 * N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], w[a[i]] = i;
	for (int i = 0; i < n; i++)
		cin >> b[i], w[b[i]] = i;
	int mn = INT_MAX, nx = N;
	for (int i = 2; i <= 2 * n; i += 2) {
		int x = w[i];
		nx = min(nx, w[i - 1]);
		mn = min(mn, x + nx);
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