/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 998244353;
int a[N], ps[N], ss[N];
int fac[N];

int tav(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

int C(int n, int k) {
	if (k > n)
		return 0;
	ll ans = fac[n];
	ans *= inv(fac[k]);
	ans %= M;
	ans *= inv(fac[n - k]);
	ans %= M;
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ps[i + 1] = ps[i] + a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		ss[n - i] = ss[n - i - 1] + a[i];
	}
	int ans = 1;
	vector <pair <int, int>> v = {{0, n - 1}};
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == 0)
			continue;
		int in = lower_bound(ss, ss + n + 1, ps[i]) - ss;
		if (ps[i] == ss[in]) {
			if (i + in < n) 
				v.push_back(make_pair(i, n - in - 1));
			if (i + in == n) {
				ans *= 2;
				ans %= M;
			}
		}
	}
	for (auto [x, y] : v) {
		int cntl = 0, cntr = 0;
		for (int j = x; j <= y; j++) {
			if (a[j] == 0)
				cntl++;
			else
				break;
		}
		for (int j = y; j >= x; j--) {
			if (a[j] == 0)
				cntr++;
			else
				break;
		}
		if (cntl == cntr && cntl == (y - x + 1)) {
			if (x != 0)
				cntl += 2;
			for (int i = 0; i < cntl - 1; i++) {
				ans *= 2;
				ans %= M;
			}
			continue;
		}
		if (x != 0) {
			++cntl;
			++cntr;
		}
		int wef = 0;
		for (int i = 0; i <= min(cntl, cntr); i++) {
			wef += C(cntl, i) * C(cntr, i);
			wef %= M;
		}
		ans *= wef;
		ans %= M;
	}
	cout << ans << '\n';
}

int32_t main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = ((ll)fac[i - 1] * i) % M;
	}
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}