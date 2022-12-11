#include <bits/stdc++.h>

const int mod = 490019;
const int phi = mod - 1;
const int MAXN = 1 << 20 | 1;
const int mod1 = 998244353;
const int mod2 = 1004535809;
typedef long long LL;
int pow(int a, int b, int m, int r = 1) {
	for (; b; b >>= 1, a = (LL) a * a % m) if (b & 1) r = (LL) r * a % m;
	return r;
}
const int imod = pow(mod1, mod2 - 2, mod2);
class num {
	int a1, a2;
public:
	num() { a1 = a2 = 0; }
	num(int x) { a1 = x, a2 = x; }
	num(int a, int b) { a1 = a, a2 = b; }
	num operator + (num b) const {
		b.a1 += a1 - mod1; b.a1 += b.a1 >> 31 & mod1;
		b.a2 += a2 - mod2; b.a2 += b.a2 >> 31 & mod2;
		return b;
	}
	num operator - (num b) const {
		num r = *this;
		r.a1 -= b.a1; r.a1 += r.a1 >> 31 & mod1;
		r.a2 -= b.a2; r.a2 += r.a2 >> 31 & mod2;
		return r;
	}
	num operator * (num b) const {
		b.a1 = (LL) a1 * b.a1 % mod1;
		b.a2 = (LL) a2 * b.a2 % mod2;
		return b;
	}
	num pow(int x, int y) const {
		return num(::pow(a1, x, mod1), ::pow(a2, y, mod2));
	}
	num inv() const {
		return pow(mod1 - 2, mod2 - 2);
	}
	LL operator () () const {
		int k = (LL) (a2 - a1 + mod2) * imod % mod2;
		return (LL) k * mod1 + a1;
	}
} wn[MAXN], wt[MAXN];
int rev[MAXN], lim, dig;
void init(int sz) {
	lim = 1, dig = -1;
	while (lim < sz) lim <<= 1, ++dig;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
	const num Wn = num(3).pow((mod1 - 1) / lim, (mod2 - 1) / lim);
	*wn = num(1);
	for (int i = 1; i <= lim; ++i) wn[i] = wn[i - 1] * Wn;
}
void NTT(num * A, int typ) {
	for (int i = 0; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int i = 0, W = 0; i != mid; ++i, W += Wn)
			wt[i] = wn[typ == 1 ? W : lim - W];
		for (int k = 0; k != lim; k += mid << 1) {
			const num * W = wt;
			for (int l = 0; l != mid; ++l) {
				num X = A[l + k], Y = *(W++) * A[l + k + mid];
				A[l + k] = X + Y;
				A[l + k + mid] = X - Y;
			}
		}
	}
	if (typ == -1) {
		num liminv = num(lim).inv();
		for (int i = 0; i != lim; ++i) A[i] = A[i] * liminv;
	}
}
int pw[mod], ipw[mod];
int n, m, C;
int A[MAXN], B[MAXN];
int comb(int x) { return (LL) x * (x - 1) / 2 % phi; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> C;
	int IC = -1;
	for (int i = 1; i < mod; ++i)
		if ((LL) C * i % mod == 1) {
			IC = i; break;
		}
	for (int i = *pw = *ipw = 1; i != mod; ++i) {
		pw[i] = (LL) pw[i - 1] * C % mod;
		ipw[i] = (LL) ipw[i - 1] * IC % mod;
	}
	for (int i = 0, t, v; i < n; ++i) {
		std::cin >> v, t = (LL) i * i % phi;
		A[t] = (A[t] + (LL) v * ipw[comb(t)]) % mod;
	}
	for (int i = 0, t, v; i < m; ++i) {
		std::cin >> v, t = (LL) i * i * i % phi;
		B[t] = (B[t] + (LL) v * ipw[comb(t)]) % mod;
	}
	static num ta[MAXN], tb[MAXN];
	const int sz = phi + phi - 1; init(sz);
	for (int i = 0; i < phi; ++i) ta[i] = num(A[i]);
	for (int i = 0; i < phi; ++i) tb[i] = num(B[i]);
	NTT(ta, 1); NTT(tb, 1);
	for (int i = 0; i < lim; ++i) ta[i] = ta[i] * tb[i];
	NTT(ta, -1);
	int ans = 0;
	for (int i = 0; i < sz; ++i)
		ans = (ans + (LL) ta[i]() % mod * pw[comb(i)]) % mod;
	std::cout << ans << std::endl;
	return 0;
}