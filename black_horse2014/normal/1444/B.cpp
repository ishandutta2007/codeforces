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
	int n; cin >> n;
	vector<int> a(2 * n);
	for (int &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	const int P = 998244353;
	const int N = 330000;
	vector<int> f(N), g(N), r(N);
	for (int i = 0; i < N; i++) {
		f[i] = i == 0 ? 1 : f[i - 1] * 1LL * i % P;
		r[i] = i < 2 ? i : r[P % i] * 1LL * (P - P / i) % P;
		g[i] = i == 0 ? 1 : g[i - 1] * 1LL * r[i] % P;
	}
	auto C = [&](int n, int m) {
		return f[n] * 1LL * g[m] % P * g[n - m] % P;
	};
	int ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {
			ans = (ans + 1LL * (P * 2 - a[i])) % P;
		} else {
			ans = (ans + a[i]) % P;
		}
	}
	cout << ans * 1LL * C(2 * n, n) % P << endl;
	return 0;
}