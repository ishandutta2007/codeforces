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
	int k; cin >> k;
	vector<long long> F(6);
	for (int i = 0; i < 6; i++) {
		cin >> F[i];
	}
	const int N = 1e6;
	vector<vector<long long>> dp(6, vector<long long>(N, -1));
	for (int i = 0; i <= 9 * k && i < N; i++) {
		if (i <= 9 * (k - 1) || i % 3 == 0) {
			dp[0][i] = i / 3 * F[0];
		} else {
			dp[0][i] = 3 * (k - 1) * F[0];
		}
	}
	vector<int> pw(7);
	for (int i = 0; i < 7; i++) {
		pw[i] = i == 0 ? 1 : pw[i - 1] * 10;
	}
	const long long inf = 1LL << 60;
	for (int step = 1; step < 6; step++) {
		long long maxs = min<long long>((pw[step + 1] - 1) * 1LL * k, N - 1);
		for (int x = 0; x < pw[step]; x++) {
			vector<long long> f(3, -inf);
			for (int y = 0; y <= (maxs - x) / pw[step]; y++) {
				int s = y * pw[step] + x;
				if (y <= 9 * (k - 1)) {
					if (dp[step - 1][s] >= 0) {
						f[y % 3] = max(f[y % 3], dp[step - 1][s] * 3 - y * F[step]);
					}
					for (int t : {0, 1, 2}) {
						if (t > y) {
							break;
						}
						if (f[t] == -inf) {
							continue;
						}
						dp[step][s] = max(dp[step][s], ((y - (y - t) % 3) * F[step] + f[t]) / 3);
					}
				} else {
					for (int z = x, cur = y; z <= s; z += pw[step], cur--) {
						if (dp[step - 1][z] >= 0) {
							if (cur <= 9 * k) {
								long long cost = 0;
								if (cur <= 9 * (k - 1) || cur % 3 == 0) {
									cost = cur / 3 * F[step];
								} else {
									cost = 3 * (k - 1) * F[step];
								}
								dp[step][s] = max(dp[step][s], dp[step - 1][z] + cost);
							}
						} else {
							break;
						}
					}
				}
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		cout << dp[5][n] << '\n';
	}
	return 0;
}