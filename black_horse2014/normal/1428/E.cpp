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
	int n, k; cin >> n >> k;
	vector<long long> a(n), cnt(n, 1);
	priority_queue<pair<long long, int>> q;
	auto calc = [&](long long x, long long y) {
		long long q = x / y;
		long long r = x % y;
		return r * (q + 1) * (q + 1) + (y - r) * q * q;
	};
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i] * a[i];
		q.emplace(calc(a[i], cnt[i]) - calc(a[i], cnt[i] + 1), i);
	}
	for (int i = 0; i < k - n; i++) {
		auto t = q.top(); q.pop();
		int u = t.second;
		ans -= t.first;
		cnt[u]++;
		if (cnt[u] < a[u]) {
			q.emplace(calc(a[u], cnt[u]) - calc(a[u], cnt[u] + 1), u);
		}
	}
	cout << ans << endl;
	return 0;
}