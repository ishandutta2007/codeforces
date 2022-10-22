/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ps[N];

void solve() {
	int n, q;
	cin >> n >> q;
	ps[0] = 0;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + a[i];
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		int l = n - x + 1;
		int r = l + y - 1;
		cout << ps[r] - ps[l - 1] << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}