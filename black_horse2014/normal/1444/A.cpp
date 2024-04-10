//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long p, q; cin >> p >> q;
		if (p % q != 0) {
			cout << p << '\n';
			continue;
		}
		long long m = q, n = p;
		vector<pair<int, int>> f, g;
		for (int x = 2; x * x <= q; x++) if (q % x == 0) {
			int y = 0;
			while (q % x == 0) {
				q /= x;
				y++;
			}
			f.emplace_back(x, y);
			int z = 0;
			while (p % x == 0) {
				p /= x;
				z++;
			}
			g.emplace_back(x, z);
		}
		if (q > 1) {
			f.emplace_back(q, 1);
			int z = 0;
			while (p % q == 0) {
				p /= q;
				z++;
			}
			g.emplace_back(q, z);
		}
		long long ans = p;
		for (int i = 0; i < f.size(); i++) {
			int x = f[i].first;
			int y = f[i].second;
			int z = g[i].second;
			long long cur = 1;
			for (int j = 0; j < z - y + 1; j++) {
				cur *= x;
			}
			ans = max(n / cur, ans);
		}
		cout << ans << '\n';
	}
	return 0;
}