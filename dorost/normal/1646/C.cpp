/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
vector <ll> v;
vector <pair <ll, int>> h;

int ans(ll n) {
	int cnt = 0;
	while (n) {
		cnt += n % 2;
		n /= 2;
	}
	return cnt;
}

void solve() {
	ll n;
	cin >> n;
	int mn = INT_MAX;
	for (auto [x, cnt] : h) {
		if (x > n)
			continue;
		mn = min(mn, ans(n - x) + cnt);
	}
	cout << mn << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll x = 1;
	v.push_back(x);
	for (int i = 2; i <= 14; i++) {
		x *= i;
		v.push_back(x);
	}
	int n = (1 << 14);
	for (int msk = 0; msk < n; msk++) {
		ll sum = 0;
		int mask = msk;
		int cnt = 0;
		for (int i = 0; i < 14; i++) {
			if (mask % 2)
				sum += v[i], cnt++;
			mask /= 2;
		}
		h.push_back(make_pair(sum, cnt));
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}