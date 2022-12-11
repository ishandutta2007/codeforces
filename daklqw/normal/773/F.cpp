#include <bits/stdc++.h>

typedef long long LL;
const int mod1 = 998244353;
const int mod2 = 1004535809;
int pow(int a, int b, int m, int r = 1) {
	for (; b; b >>= 1, a = (LL) a * a % m) if (b & 1) r = (LL) r * a % m;
	return r;
}
const int imod = pow(mod1, mod2 - 2, mod2);
const int MAXN = 1048577;
class num {
	int a1, a2;
public:
	num() { a1 = a2 = 0; }
	num(int x) { a1 = x, a2 = x; }
	// num(int x) { a1 = x % mod1, a2 = x % mod2; }
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
typedef std::vector<int> VI;
std::ostream & operator << (std::ostream & out, const VI & x) {
	const int s = x.size();
	out << '(';
	for (int i = 0; i != s; ++i) out << x[i] << (" )" [i == s - 1]);
	return out;
}
int A, mod;
void reduce(int & x) { x += x >> 31 & mod; }
VI operator * (const VI & a, const VI & b) {
	static num ta[MAXN], tb[MAXN];
	static int res[MAXN];
	const int ls = a.size(), rs = b.size();
	const int sz = ls + rs - 1; init(sz);
	for (int i = 0; i < ls; ++i) ta[i] = num(a[i]);
	for (int i = 0; i < rs; ++i) tb[i] = num(b[i]);
	std::fill(ta + ls, ta + lim, num());
	std::fill(tb + rs, tb + lim, num());
	NTT(ta, 1); NTT(tb, 1);
	for (int i = 0; i < lim; ++i) ta[i] = ta[i] * tb[i];
	NTT(ta, -1);
	for (int i = 0; i < sz; ++i) res[i] = ta[i]() % mod;
	return VI(res, res + std::min(sz, A));
}
VI operator + (const VI & a, const VI & b) {
	static int res[MAXN];
	const int ls = a.size(), rs = b.size();
	const int sz = std::max(ls, rs);
	std::fill(res, res + sz, 0);
	for (int i = 0; i != ls; ++i) res[i] = a[i];
	for (int i = 0; i != rs; ++i) reduce(res[i] += b[i] - mod);
	return VI(res, res + sz);
}
typedef std::pair<VI, VI> VP;
int P, Q, N;
int Ans = 0;
VP solve(int K) {
	if (K == 0) return VP({0}, {0});
	if (K == 1) {
		reduce(Ans += 1 - mod);
		return VP({0, 1}, {0});
	}
	int nt = K >> 1;
	VP ret = solve(nt);
	VI sm = ret.second + ret.first + VI({1});
	VI odd = ret.first + sm * (nt & 1 ? ret.second : ret.first);
	VI even = ret.second + sm * (nt & 1 ? ret.first : ret.second);
	if (K & 1) {
		std::swap(odd, even);
		odd = odd * VI({1, 1}) + VI({0, 1});
		even = even * VI({1, 1});
	}
	const int sz = odd.size();
	for (int i = 1; i < sz; i += 2)
		reduce(Ans += odd[i] - mod);
	return VP(odd, even);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int B;
	std::cin >> A >> B >> mod; ++A;
	solve(B / 2);
	std::cout << Ans << std::endl;
	return 0;
}