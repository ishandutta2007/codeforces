#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int n, k;
	cin >> n >> k;
	vector<ll> p(k + 1);
	p[0] = 1;
	for (int i = 1; i <= k; i++) {
		p[i] = p[i - 1] * 3;
	}
	set<ll> s;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			assert(x == 0 || x == 1 || x == 2);
			a[i] += p[j] * x;
		}
		s.insert(a[i]);
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		int have = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			ll val = 0;
			for (int pos = 0; pos < k; pos++) {
				int xi = (a[i] / p[pos]) % 3;
				int xj = (a[j] / p[pos]) % 3;
				int xs = (6 - xi - xj) % 3;
				val += p[pos] * xs;
			}
			if (s.count(val)) {
				have++;
			}
		}
		assert(have % 2 == 0);
		have /= 2;
		sol += have * (have - 1) / 2;
	}
	cout << sol << "\n";
	
	return 0;
}