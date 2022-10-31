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
		int n; cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> b(n), c(n);
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < a[i + 1]) {
				c[i + 1] = a[i + 1] - a[i];
			}
			if (a[i] > a[i + 1]) {
				b[i] = a[i] - a[i + 1];
			}
		}
		{
			long long sum = 0;
			for (int i = n - 1; i >= 0; i--) {
				sum += b[i];
				a[i] -= sum;
			}
		}
		{
			long long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += c[i];
				a[i] -= sum;
			}
		}
		cout << (a[0] >= 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}