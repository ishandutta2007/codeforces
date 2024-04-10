#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 10010;
typedef long long LL;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

LL n, m, a[MAXN], L;
int K;
LL bs[MAXN], ms[MAXN];
inline LL mul(LL x, LL y, LL mod) {
	LL t = x * y - static_cast<LL> (static_cast<long double> (x) * y / mod + 0.5) * mod;
	return t + (t >> 63 & mod);
}
void exgcd(LL a, LL b, LL & x, LL & y) {
	if (!b) { x = 1, y = 0; return ; }
	exgcd(b, a % b, y, x); y -= a / b * x;
}
LL INV(LL x, LL y) {
	LL ta, tb;
	exgcd(x, y, ta, tb);
	return ta + (ta >> 63 & y);
}
bool merge(int dst, int src) {
	const LL G = gcd(ms[dst], ms[src]);
	LL t = (bs[src] - bs[dst]) % ms[src];
	t += t >> 63 & ms[src];
	if (t % G != 0) return false;
	t /= G;
	const LL m1 = ms[dst] / G, m2 = ms[src] / G;
	const LL k = mul(t, INV(m1, m2), m2);
	const LL mx = m1 * m2 * G;
	(bs[dst] += mul(k, ms[dst], mx)) %= mx;
	ms[dst] = mx;
	return true;
}
int main() {
	scanf("%lld%lld%d", &n, &m, &K);
	for (int i = 1; i <= K; ++i) {
		scanf("%lld", a + i);
		if (!L) L = a[1];
		const LL G = gcd(L, a[i]);
		int d1 = __builtin_clzll(L / G), d2 = __builtin_clzll(a[i]);
		if ((63 - d1) + (63 - d2) > 63) return puts("NO"), 0;
		L = L / G * a[i];
		if (L > n) return puts("NO"), 0;
	}
	for (int i = 1; i <= K; ++i) {
		ms[i] = a[i];
		bs[i] = (a[i] - (i - 1) % a[i]) % a[i];
	}
	for (int i = K - 1; i; --i) if (!merge(i, i + 1)) return puts("NO"), 0;
	if (!bs[1]) bs[1] = L;
	if (bs[1] + K - 1 > m) return puts("NO"), 0;
	const LL bse = bs[1] - 1;
	for (int i = 1; i <= K; ++i) 
		if (gcd(L, bse + i) != a[i])
			return puts("NO"), 0;
	puts("YES");
	return 0;
}