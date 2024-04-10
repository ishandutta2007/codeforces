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
		int n; string s; cin >> n >> s;
		vector<int> f(n);
		for (int i = 0; i < n; i++) {
			f[i] = i;
		}
		function<int(int)> find_set = [&](int u) {
			return f[u] == u ? u : f[u] = find_set(f[u]);
		};
		int cnt = n;
		for (int i = 0; i < n; i++) {
			if (s[i] == '-') {
				int u = find_set(i);
				int v = find_set((i + 1) % n);
				f[u] = v;
				cnt--;
			}
		}
		if (cnt == 1) {
			cout << n << '\n';
			continue;
		}
		bool a = false, b = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '>') {
				a = true;
			}
			if (s[i] == '<') {
				b = true;
			}
		}
		if (!a || !b) {
			cout << n << '\n';
			continue;
		}
		vector<int> sz(n);
		for (int i = 0; i < n; i++) {
			sz[find_set(i)]++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (sz[i] > 1) {
				ans += sz[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}