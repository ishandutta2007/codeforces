#ifndef CLASS_FAST_MODINT
#define CLASS_FAST_MODINT

#include <vector>
#include <cstdint>

using singlebit = uint32_t;
using doublebit = uint64_t;
static constexpr int digit_level = 32;

static constexpr singlebit find_inv(singlebit n, int d = 6, singlebit x = 1) {
	return d == 0 ? x : find_inv(n, d - 1, x * (2 - x * n));
}
template <singlebit mod> class fast_modint {
	// Fast Modulo Integer, Assertion: mod < 2^(bits of singlebit - 1) and mod is prime
private:
	singlebit n;
	static constexpr singlebit r2 = (((doublebit(1) << digit_level) % mod) << digit_level) % mod;
	static constexpr singlebit ninv = singlebit(-1) * find_inv(mod);
	singlebit reduce(doublebit x) const {
		singlebit res = (x + doublebit(singlebit(x) * ninv) * mod) >> digit_level;
		return res < mod ? res : res - mod;
	}
public:
	fast_modint() : n(0) {};
	fast_modint(singlebit n_) { n = reduce(doublebit(n_) * r2); };
	static constexpr singlebit get_mod() { return mod; }
	singlebit get() const { return reduce(n); }
	bool operator==(const fast_modint& x) const { return n == x.n; }
	bool operator!=(const fast_modint& x) const { return n != x.n; }
	fast_modint& operator+=(const fast_modint& x) { n += x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator-=(const fast_modint& x) { n += mod - x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator*=(const fast_modint& x) { n = reduce(doublebit(n) * x.n); return *this; }
	fast_modint operator+(const fast_modint& x) const { return fast_modint(*this) += x; }
	fast_modint operator-(const fast_modint& x) const { return fast_modint(*this) -= x; }
	fast_modint operator*(const fast_modint& x) const { return fast_modint(*this) *= x; }
	fast_modint inv() const { return binpow(mod - 2); }
	fast_modint binpow(singlebit b) const {
		fast_modint ans(1), cur(*this);
		while (b > 0) {
			if (b & 1) ans *= cur;
			cur *= cur;
			b >>= 1;
		}
		return ans;
	}
};

template<typename modulo>
std::vector<modulo> get_modvector(std::vector<int> v) {
	std::vector<modulo> ans(v.size());
	for (int i = 0; i < v.size(); ++i) {
		ans[i] = modulo(v[i]);
	}
	return ans;
}

#endif // CLASS_FAST_MODINT

#ifndef CLASS_POLYNOMIAL_NTT
#define CLASS_POLYNOMIAL_NTT

template<singlebit mod, singlebit depth, singlebit primroot>
class polynomial_ntt {
public:
	using modulo = fast_modint<mod>;
	static void fourier_transform(std::vector<modulo>& v, bool inverse) {
		std::size_t s = v.size();
		for (std::size_t i = 0, j = 1; j < s - 1; ++j) {
			for (std::size_t k = s >> 1; k > (i ^= k); k >>= 1);
			if (i < j) std::swap(v[i], v[j]);
		}
		std::size_t sc = 0, sz = 1;
		while (sz < s) sz *= 2, ++sc;
		modulo root = modulo(primroot).binpow((mod - 1) >> sc);
		std::vector<modulo> pw(s + 1); pw[0] = 1;
		for (std::size_t i = 1; i <= s; i++) pw[i] = pw[i - 1] * root;
		std::size_t qs = s;
		for (std::size_t b = 1; b < s; b <<= 1) {
			qs >>= 1;
			for (std::size_t i = 0; i < s; i += b * 2) {
				for (std::size_t j = i; j < i + b; ++j) {
					modulo delta = pw[(inverse ? b * 2 - j + i : j - i) * qs] * v[j + b];
					v[j + b] = v[j] - delta;
					v[j] += delta;
				}
			}
		}
		if (!inverse) return;
		modulo powinv = modulo((mod + 1) / 2).binpow(sc);
		for (std::size_t i = 0; i < s; ++i) {
			v[i] = v[i] * powinv;
		}
	}
	static std::vector<modulo> convolve(std::vector<modulo> v1, std::vector<modulo> v2) {
		std::size_t s1 = v1.size(), s2 = v2.size(), s = 1;
		while (s < s1 || s < s2) s *= 2;
		v1.resize(s * 2); fourier_transform(v1, false);
		v2.resize(s * 2); fourier_transform(v2, false);
		for (singlebit i = 0; i < s * 2; ++i) v1[i] *= v2[i];
		fourier_transform(v1, true);
		v1.resize(s1 + s2 - 1);
		return v1;
	}
};

#endif // CLASS_POLYNOMIAL_NTT

#ifndef CLASS_POLYNOMIAL_MOD
#define CLASS_POLYNOMIAL_MOD

#include <algorithm>

template<const singlebit mod, const singlebit depth, const singlebit primroot>
class polynomial_mod {
public:
	using modulo = fast_modint<mod>;
	using ntt = polynomial_ntt<mod, depth, primroot>;
protected:
	std::size_t sz;
	std::vector<modulo> a;
public:
	explicit polynomial_mod() : sz(1), a(std::vector<modulo>({ modulo() })) {};
	explicit polynomial_mod(std::size_t sz_) : sz(sz_), a(std::vector<modulo>(sz_, modulo())) {};
	explicit polynomial_mod(std::vector<modulo> a_) : sz(a_.size()), a(a_) {};
	polynomial_mod& operator=(const polynomial_mod& p) {
		sz = p.sz;
		a = p.a;
		return (*this);
	}
	std::size_t size() const { return sz; }
	std::size_t degree() const { return sz - 1; }
	modulo operator[](std::size_t idx) const {
		return a[idx];
	}
	modulo& operator[](std::size_t idx) {
		return a[idx];
	}
	bool operator==(const polynomial_mod& p) const {
		for (std::size_t i = 0; i < sz || i < p.sz; ++i) {
			if ((i < sz ? a[i] : modulo(0)) != (i < p.sz ? p.a[i] : modulo(0))) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const polynomial_mod& p) const {
		return !(operator==(p));
	}
	polynomial_mod resize_transform(std::size_t d) const {
		// Resize polynomial to d: in other words, f(x) := f(x) mod x^d
		polynomial_mod ans(*this);
		ans.sz = d;
		ans.a.resize(d, modulo(0));
		return ans;
	}
	polynomial_mod star_transform() const {
		// f*(x) = x^degree * f(1/x)
		polynomial_mod ans(*this);
		std::reverse(ans.a.begin(), ans.a.end());
		return ans;
	}
	polynomial_mod inverse(std::size_t d) const {
		// Find g(x) where g(x) * f(x) = 1 (mod x^d)
		polynomial_mod ans(std::vector<modulo>({ a[0].inv() }));
		while (ans.size() < d) {
			polynomial_mod nxt({ modulo(2) });
			nxt -= ans * resize_transform(ans.size() * 2);
			nxt *= ans;
			ans = nxt.resize_transform(ans.size() * 2);
		}
		ans = ans.resize_transform(d);
		return ans;
	}
	polynomial_mod& operator+=(const polynomial_mod& p) {
		sz = std::max(sz, p.sz);
		a.resize(sz);
		for (std::size_t i = 0; i < sz; ++i) a[i] += p.a[i];
		return (*this);
	}
	polynomial_mod& operator-=(const polynomial_mod& p) {
		sz = std::max(sz, p.sz);
		a.resize(sz);
		for (std::size_t i = 0; i < sz; ++i) a[i] -= p.a[i];
		return (*this);
	}
	polynomial_mod& operator*=(const polynomial_mod& p) {
		a = ntt::convolve(a, p.a);
		sz += p.sz - 1;
		return (*this);
	}
	polynomial_mod& operator/=(const polynomial_mod& p) {
		// Expected Time: 4 * multiply(p)
		std::size_t dn = degree(), dm = p.degree();
		if (dn < dm) (*this) = polynomial_mod();
		else {
			polynomial_mod gstar = p.star_transform().inverse(dn - dm + 1);
			polynomial_mod qstar = (gstar * (*this).star_transform()).resize_transform(dn - dm + 1);
			(*this) = qstar.star_transform();
		}
		return (*this);
	}
	polynomial_mod& operator%=(const polynomial_mod& p) {
		// Expected Time: 5 * multiply(p)
		(*this) -= polynomial_mod(*this) / p * p;
		(*this) = (*this).resize_transform(p.size() - 1);
		return (*this);
	}
	polynomial_mod operator+() const {
		return polynomial_mod(*this);
	}
	polynomial_mod operator-() const {
		return polynomial_mod() - polynomial_mod(*this);
	}
	polynomial_mod operator+(const polynomial_mod& p) const {
		return polynomial_mod(*this) += p;
	}
	polynomial_mod operator-(const polynomial_mod& p) const {
		return polynomial_mod(*this) -= p;
	}
	polynomial_mod operator*(const polynomial_mod& p) const {
		return polynomial_mod(*this) *= p;
	}
	polynomial_mod operator/(const polynomial_mod& p) const {
		return polynomial_mod(*this) /= p;
	}
	polynomial_mod operator%(const polynomial_mod& p) const {
		return polynomial_mod(*this) %= p;
	}
};
#endif // CLASS_POLYNOMIAL_MOD


#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long mod = 998244353;
long long fact[1 << 19], factinv[1 << 19];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 400000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= 400000; i++) factinv[i] = Div(1, fact[i], mod);
}

long long ncr(long long n, long long r) {
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

long long N, K, Q;
long long A[1 << 19], B[1 << 19], C[1 << 19];
long long V[1 << 22], cnt[1 << 22];
bool used[1 << 22];

using poly = polynomial_mod<998244353, 23, 3>;
using modulo = poly::modulo;

vector<long long> calc(vector<long long> v1, vector<long long> v2) {
	poly a(v1.size()), b(v2.size());
	for (int i = 0; i < v1.size(); i++) a[i] = v1[i];
	for (int i = 0; i < v2.size(); i++) b[i] = v2[i];

	poly c = a * b;
	vector<long long> ans;
	for (int i = 0; i < v1.size() + v2.size() - 1; i++) ans.push_back(c[i].get());
	return ans;
}

int main() {
	init();
	for (int i = 0; i < 22; i++) used[1 << i] = true;

	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= K; i++) scanf("%lld", &B[i]);
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld", &C[i]);

	for (int i = 1; i <= N; i++) cnt[A[i]]++;
	for (int i = 1; i <= K; i++) {
		long long ret1 = 0, ret2 = 0;
		for (int j = 1; j < B[i]; j++) {
			if (cnt[j] >= 2) ret2 += 2;
			else if (cnt[j] == 1) ret1++;
		}

		vector<long long> E1, E2;
		for (int j = 0; j <= ret1; j++) E1.push_back(ncr(ret1, j) * modpow(2, j, mod) % mod);
		for (int j = 0; j <= ret2; j++) E2.push_back(ncr(ret2, j));
		while (used[E1.size()] == false) E1.push_back(0);
		while (used[E2.size()] == false) E2.push_back(0);
		while (E1.size() < E2.size()) E1.push_back(0);
		while (E1.size() > E2.size()) E2.push_back(0);

		vector<long long> F = calc(E1, E2);
		for (int j = 0; j < F.size(); j++) {
			V[2LL * (B[i] + j + 1LL)] += F[j];
			V[2LL * (B[i] + j + 1LL)] %= mod;
		}
	}

	for (int i = 1; i <= Q; i++) printf("%lld\n", V[C[i]]);
	return 0;
}