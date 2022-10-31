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

const int P = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, k; cin >> n >> k;
		vector<int> a(n + 1);
		vector<int> pos(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		vector<bool> f(n + 1, true);
		vector<int> B(k);
		for (int i = 0; i < k; i++) {
			cin >> B[i];
		}
		long long res = 1;
		for (int i = k - 1; i >= 0; i--) {
			int b = pos[B[i]];
			int cur = 0;
			if (b > 1) {
				cur += f[a[b - 1]];
			}
			if (b < n) {
				cur += f[a[b + 1]];
			}
			res = res * cur % P;
			f[a[b]] = false;
		}
		cout << res << "\n";
	}
	return 0;
}