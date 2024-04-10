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
	int n, m; cin >> n >> m;
	long long sum = 0;
	int ret = 0;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; --x;
		ret = (ret + 1LL * x * y) % n;
		sum += y;
	}
	int need = 1LL * n * (n - 1) / 2 % n;
	if (sum > n || sum == n && ret != need) {
		cout << -1 << '\n';
	} else {
		cout << 1 << '\n';
	}
	return 0;
}