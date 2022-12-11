#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int fastpow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXN = 500010;
const int MAXS = 10000000;
std::bitset<MAXS + 10> npri;
int pri[MAXS / 10], mu[MAXS + 10], bak;
void sieve(int lim) {
	mu[1] = 1;
	for (int i = 2, t; i <= lim; ++i) {
		if (!npri[i]) mu[pri[++bak] = i] = -1;
		for (int j = 1; j <= bak && (t = pri[j] * i) <= lim; ++j) {
			npri[t] = true;
			if (i % pri[j] == 0) { mu[t] = 0; break; }
			mu[t] = -mu[i];
		}
	}
}
int hav[MAXS + 10], pw2[MAXN];
int A[MAXN], n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = *pw2 = 1; i <= n; ++i) reduce(pw2[i] = pw2[i - 1] * 2 - mod);
	for (int i = 1; i <= n; ++i) std::cin >> A[i], ++hav[A[i]];
	int lim = *std::max_element(A + 1, A + 1 + n);
	sieve(lim);
	for (int i = 1; i <= bak; ++i)
		for (int j = lim / pri[i]; j; --j)
			hav[j] += hav[j * pri[i]];
	// for (int i = 1; i <= lim; ++i) std::cout << hav[i] << ' '; std::cout << std::endl;
	LL suma = 0, sumb = 0;
	for (int i = 1; i <= lim; ++i) if (mu[i]) {
		suma += (LL) (pw2[hav[i]] - 1) * hav[i] % mod * (mu[i] + mod) % mod;
		sumb += (LL) (pw2[hav[i]] - 1) * (mu[i] + mod) % mod;
	}
	suma %= mod, sumb %= mod;
	int ans = suma - mul(sumb, n); reduce(ans);
	std::cout << ans << std::endl;
	return 0;
}