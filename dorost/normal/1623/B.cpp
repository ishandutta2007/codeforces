/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
vector <int> s[N];
int a[N][N], sh[N], rh[N];

void ans (int l, int r) {
	if (l == r) {
		a[l][r] = l;
		return;
	}
	if (s[l].front() >= r) {
		a[l][r] = l;
		ans(l + 1, r);
	} else {
		int d = *(lower_bound(s[l].begin(), s[l].end(), r) - 1) + 1;
		a[l][r] = d;
		if (d != r) {
			ans(d + 1, r);
		}
		if (d != l) {
			ans(l, d - 1);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		s[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> sh[i] >> rh[i];
		s[sh[i]].push_back(rh[i]);
	}
	for (int i = 0; i <= n; i++) {
		sort(s[i].begin(), s[i].end());
	}
	ans(1, n);
	for (int i = 0; i < n; i++) {
		cout << sh[i] << ' ' << rh[i] << ' ' << a[sh[i]][rh[i]] << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}