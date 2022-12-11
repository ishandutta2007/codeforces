#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 262145;

const int Dollar1 = 998244353;
const int G = 3, Ginv = (Dollar1 + 1) / 3;
typedef long long LL;
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline void add(int & x, const int y) { x += y - Dollar1, x += x >> 31 & Dollar1; }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline void dec(int & x, const int y) { x -= y, x += x >> 31 & Dollar1; }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline void mulr(int & x, const int y) { x = static_cast<LL> (x) * y % Dollar1; }
inline int fastpow(int a, int b) { int res = 1; while (b) { if (b & 1) mulr(res, a); mulr(a, a); b >>= 1; } return res; }
int rev[MAXN], wn[MAXN], wt[MAXN], lim, dig;
void init(int sz) {
	*wn = lim = 1, dig = -1;
	while (lim <= sz) lim <<= 1, ++dig;
	for (int i = 1; i != lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
	const int W = fastpow(G, (Dollar1 - 1) / lim);
	for (int i = 1; i <= lim; ++i) wn[i] = mul(wn[i - 1], W);
}
void NTT(int * A, int typ) {
	for (int i = 0; i != lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int i = 0, W = 0; i != mid; ++i, W += Wn)
			wt[i] = wn[typ == 1 ? W : lim - W];
		for (int k = 0; k != lim; k += mid << 1) {
			const int * W = wt;
			for (int l = 0; l != mid; ++l, ++W) {
				const int X = A[l + k], Y = mul(A[l + k + mid], *W);
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
inline void clear(int * b, const int * e) {
	if (b >= e) return;
	memset(b, 0, e - b << 2);
}
int n, K, A[MAXN], B[MAXN], C[MAXN], XP[MAXN];
void fastpow(int sz) {
	if (sz == 1) {
		A[0] = A[1] = 1;
		B[0] = 1;
		return ;
	}
	fastpow(sz >> 1);
	NTT(A, 1); NTT(B, 1); NTT(C, 1);
	for (int i = 0; i != lim; ++i) {
		const int X = A[i], Y = B[i], Z = C[i], XP = ::XP[i];
		A[i] = up(mul(X, X) + mul(mul(Y, Y), XP));
		B[i] = up(mul(X, Y) + mul(mul(Y, Z), XP));
		C[i] = up(mul(Y, Y) + mul(mul(Z, Z), XP));
	}
	NTT(A, -1); NTT(B, -1); NTT(C, -1);
	clear(A + K, A + lim); clear(B + K, B + lim); clear(C + K, C + lim);
	if (sz & 1) for (int i = K - 1; ~i; --i) {
		C[i] = B[i]; B[i] = A[i];
		if (i) add(A[i], up(A[i - 1] + B[i - 1]));
	}
}
int main() {
	scanf("%d%d", &n, &K); ++K;
	init(K << 1 | 1);
	XP[1] = 1; NTT(XP, 1);
	fastpow(n);
	for (int j = 1; j != K; ++j) printf("%d ", A[j]); putchar(10);
	return 0;
}