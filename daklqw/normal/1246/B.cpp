#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int A[MAXN], n, K;
int B[MAXN], diva[MAXN];
int hav[MAXN];
LL fastpow(int a, int b) {
	LL res = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1) res = res * a;
	return res;
}
int range, overrange;
LL fastpow(int a, int b, LL c) {
	overrange = false;
	while (b--) {
		c *= a;
		if (c > range) {
			overrange = true;
			return c;
		}
	}
	return c;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	int ma = 0;
	for (int i = 1; i <= n; ++i) { std::cin >> A[i]; ma = std::max(ma, A[i]); }
	int lim = pow(ma, 1. / K) + 0.2, can = 0;
	for (int i = 1; i <= lim && fastpow(i, K) <= ma; ++i) {
		for (LL t = fastpow(i, K), j = t; j <= ma; j += t) 
			diva[j] = std::max(diva[j], i);
		can = std::max(can, i);
	}
	for (int i = 1; i <= n; ++i)
		++hav[A[i] / fastpow(diva[A[i]], K)];
	LL ans = 0;
	for (int i = 1; i <= ma; ++i) if (hav[i]) {
		int t = i; LL tar = 1;
		for (int j = 2; j <= t; ++j) if (t % j == 0) {
			int tc = K;
			while (t % j == 0) t /= j, --tc;
			range = ma;
			tar = fastpow(j, tc, tar);
			if (overrange) {
				tar = 0;
				break;
			}
		}
		if (!tar) continue;
		if (i == tar) ans += hav[i] * (hav[i] - 1ll) / 2;
		else {
			ans += hav[i] * hav[tar];
			hav[i] = hav[tar] = 0;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}