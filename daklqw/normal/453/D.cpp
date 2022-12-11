#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
typedef long double db;
const int MAXN = 1 << 20 | 1;
LL mod;
void reduce(LL & x) { x += x >> 63 & mod; }
LL mul(const LL x, const LL y) {
	LL t = x * y - (LL) ((db) x * y / mod + 0.5) * mod;
	return t + (t >> 63 & mod);
}
LL pow(LL a, LL b, LL r = 1) {
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) r = mul(r, a);
	return r;
}

int m, P, b[MAXN];
LL f[MAXN], g[MAXN], t;

void FWT(LL * A) {
	const int lim = 1 << m;
	for (int mid = 1; mid != lim; mid <<= 1)
		for (int k = 0; k != lim; k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				const LL Y = A[l + k + mid];
				reduce(A[l + k + mid] = A[l + k] - Y);
				reduce(A[l + k] += Y - mod);
			}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> m >> t >> P;
	mod = (LL) P << m;
	const int lim = 1 << m;
	for (int i = 0; i != lim; ++i)
		std::cin >> f[i];
	for (int i = 0; i <= m; ++i)
		std::cin >> b[i];
	for (int i = 0; i != lim; ++i)
		g[i] = b[__builtin_popcount(i)];
	FWT(f); FWT(g);
	for (int i = 0; i != lim; ++i)
		f[i] = pow(g[i], t, f[i]);
	FWT(f);
	for (int i = 0; i != lim; ++i)
		std::cout << (f[i] >> m) << '\n';
	return 0;
}