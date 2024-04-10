/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N], d[N];

void ans(int l, int r, int dep) {
	if (l == r)
		return;
	int in = max_element(a + l, a + r) - a;
	d[in] = dep;
	ans(l, in, dep + 1);
	ans(in + 1, r, dep + 1);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ans(0, n, 0);
	for (int i = 0; i < n; i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}