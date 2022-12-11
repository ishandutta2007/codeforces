#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 262145;
const int Dollar1 = 998244353;
const int G = 3, Ginv = (Dollar1 + 1) / G;
typedef long long LL;
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline void add(int & x, const int y) { x += y - Dollar1, x += x >> 31 & Dollar1; }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline void dec(int & x, const int y) { x -= y, x += x >> 31 & Dollar1; }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline void mulr(int & x, const int y) { x = static_cast<LL> (x) * y % Dollar1; }
inline int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) mulr(res, a);
		mulr(a, a);
		b >>= 1;
	}
	return res;
}
int rev[MAXN], wn[MAXN], lim, dig;
void init(int sz) {
	lim = 1, dig = -1;
	while (lim <= sz) lim <<= 1, ++dig;
	const int W = fastpow(G, (Dollar1 - 1) / lim);
	*wn = 1; for (int i = 1; i <= lim; ++i) wn[i] = mul(wn[i - 1], W);
	for (int i = 1; i != lim; ++i)
		rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
}
void NTT(int * A, int typ) {
	for (int i = 0; i != lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int k = 0; k != lim; k += mid << 1) {
			int W = 0;
			for (int l = 0; l != mid; ++l, W += Wn) {
				const int X = A[l + k], Y = mul(A[l + k + mid], wn[typ == 1 ? W : lim - W]);
				A[l + k] = up(X + Y);
				A[l + k + mid] = down(X - Y);
			}
		}
	}
	if (typ == -1) {
		const int liminv = fastpow(lim, Dollar1 - 2);
		for (int i = 0; i != lim; ++i) mulr(A[i], liminv);
	}
}
inline void clear(int * b, int * e) { while (b != e) *b++ = 0; }
int n, m, inv[MAXN], fac[MAXN], ifac[MAXN], A[MAXN], B[MAXN];
long long tm;
using std::reverse;
int main() {
	inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[Dollar1 % i], Dollar1 - Dollar1 / i);
		ifac[i] = mul(ifac[i - 1], inv[i]);
	}
	scanf("%d%lld", &n, &tm); m = tm % (Dollar1 - 1); ++n;
	init(n << 1);
	for (int i = 0; i != n; ++i) scanf("%d", &A[i]), mulr(A[i], fac[i]);
	for (int i = 0; i != n; ++i) B[i] = ifac[i];
	reverse(A, A + n);
	NTT(A, 1); NTT(B, 1);
	for (int i = 0; i != lim; ++i) mulr(A[i], B[i]);
	NTT(A, -1);
	reverse(A, A + n);
	for (int i = 0; i != n; ++i) mulr(A[i], fastpow(inv[i + 1], m));
	for (int i = 0, t = 1; i != n; ++i, t = down(-t)) B[i] = mul(t, ifac[i]);
	clear(A + n, A + lim); clear(B + n, B + lim);
	reverse(A, A + n);
	NTT(A, 1); NTT(B, 1);
	for (int i = 0; i != lim; ++i) mulr(A[i], B[i]);
	NTT(A, -1);
	reverse(A, A + n);
	for (int i = 0; i != n; ++i) printf("%d ", mul(A[i], ifac[i])); putchar(10);
	return 0;
}