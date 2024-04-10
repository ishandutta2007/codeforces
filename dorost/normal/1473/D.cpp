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
pair <int, int> pre[N], suf[N];
int prex[N];

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	pre[0] = {0LL, 0LL};
	prex[0] = 0LL;
	int mn = 0, mx = 0, x = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '+')
			x++;
		else
			x--;
		mn = min(mn, x);
		mx = max(mx, x);
		pre[i] = {mn, mx};
		prex[i] = x;
	}
	suf[n] = {0LL, 0LL};
	mn = 0, mx = 0, x = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '+') {
			mx++;
			mn = min(mn + 1, 0LL);
		} else {
			mn--;
			mx = max(mx - 1, 0LL);
		}
		suf[i] = {mn, mx};
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int a = 0, b = 0;
		if (l != 1) {
			a = min(a, pre[l - 1].F);
			b = max(b, pre[l - 1].S);
		}
		if (r != n) {
			a = min(a, suf[r].F + prex[l - 1]);
			b = max(b, suf[r].S + prex[l - 1]);
		}
		cout << b - a + 1 << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}