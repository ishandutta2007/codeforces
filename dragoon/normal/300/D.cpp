//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <random>
#include <chrono>
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include <array>
#include <complex>
#include<iomanip>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL> VPL;
typedef vector<PII> VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;
typedef unsigned long long ULL;

#define MAXN 1000
#define MAXN2 MAXN*MAXN
//#define MAXN 1006

const LL MOD = 1000000007;
//const LL MOD = 998244353;
//const LL INF = 2000000000000000001LL; //2e18 + 1

/**
 * Author: Andrew He
 * Description: FFT/NTT, polynomial mod/log/exp
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf
 * Papers about accuracy: http://www.daemonology.net/papers/fft.pdf, http://www.cs.berkeley.edu/~fateman/papers/fftvsothers.pdf
 * For integers rounding works if $(|a| + |b|)\max(a, b) < \mathtt{\sim} 10^9$, or in theory maybe $10^6$.
 */

#define FFT 1


int NumTrailingZeroes(LL x) {
	int ret = 0;
	if (x == 0) return 0;
	while (!(x & 1)) {
		ret++;
		x >>= 1;
	}
	return ret;
}

int NumLeadingZeroes(int x) {
	if (x == 0) return 0;
	LL xx = x;
	for (int i = 31; i >= 0; i--) {
		if (xx & (1LL << i)) {
			return 31 - i;
		}
	}
}

namespace fft {

#if FFT
	// FFT
	struct num {
		double x, y;
		num(double x_ = 0, double y_ = 0) : x(x_), y(y_) { }
	};
	inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
	inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
	inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline num conj(num a) { return num(a.x, -a.y); }
	inline num inv(num a) { double n = (a.x * a.x + a.y * a.y); return num(a.x / n, -a.y / n); }
	const double PI = acos(-1.);
#else

	// NTT
	const int mod = 7340033, g = 3;
	// For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
	// (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
	struct num {
		int v;
		num(LL v_ = 0) : v(int(v_% mod)) { if (v < 0) v += mod; }
		explicit operator int() const { return v; }
	};
	inline num operator+(num a, num b) { return num(a.v + b.v); }
	inline num operator-(num a, num b) { return num(a.v + mod - b.v); }
	inline num operator*(num a, num b) { return num(1ll * a.v * b.v); }
	inline num pow(num a, int b) {
		num r = 1;
		do { if (b & 1)r = r * a; a = a * a; } while (b >>= 1);
		return r;
	}
	inline num inv(num a) { return pow(a, mod - 2); }

#endif

	using vn = vector<num>;
	VI rev({ 0, 1 });
	vn rt(2, num(1)), fa, fb;

	inline void init(int n) {
		if (n <= SZ(rt)) return;
		rev.resize(n);
		FORN(i, n) rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
		rt.reserve(n);
		for (int k = SZ(rt); k < n; k *= 2) {
			rt.resize(2 * k);
#if FFT
			double a = PI / k; num z(cos(a), sin(a)); // FFT
#else
			num z = pow(num(g), (mod - 1) / (2 * k)); // NTT
#endif
			FORAB(i, k / 2, k - 1) rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
		}
	}

	inline void fft(vector<num>& a, int n) {
		init(n);
		int s = NumTrailingZeroes(SZ(rev) / n);
		FORN(i, n) if (i < rev[i] >> s) swap(a[i], a[rev[i] >> s]);
		for (int k = 1; k < n; k *= 2)
			for (int i = 0; i < n; i += 2 * k) FORN(j, k) {
				num t = rt[j + k] * a[i + j + k];
				a[i + j + k] = a[i + j] - t;
				a[i + j] = a[i + j] + t;
			}
	}

	// Complex/NTT
	vn multiply(vn a, vn b) {
		int s = SZ(a) + SZ(b) - 1;
		if (s <= 0) return {};
		int L = s > 1 ? 32 - NumLeadingZeroes(s - 1) : 0, n = 1 << L;
		a.resize(n), b.resize(n);
		fft(a, n);
		fft(b, n);
		num d = inv(num(n));
		FORN(i, n) a[i] = a[i] * b[i] * d;
		reverse(a.begin() + 1, a.end());
		fft(a, n);
		a.resize(s);
		return a;
	}

	// Complex/NTT power-series inverse
	// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
	vn inverse(const vn& a) {
		if (a.empty()) return {};
		vn b({ inv(a[0]) });
		b.reserve(2 * a.size());
		while (SZ(b) < SZ(a)) {
			int n = 2 * SZ(b);
			b.resize(2 * n, 0);
			if (SZ(fa) < 2 * n) fa.resize(2 * n);
			fill(fa.begin(), fa.begin() + 2 * n, 0);
			copy(a.begin(), a.begin() + min(n, SZ(a)), fa.begin());
			fft(b, 2 * n);
			fft(fa, 2 * n);
			num d = inv(num(2 * n));
			FORN(i, 2 * n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
			reverse(b.begin() + 1, b.end());
			fft(b, 2 * n);
			b.resize(n);
		}
		b.resize(a.size());
		return b;
	}

#if FFT
	// Double multiply (num = complex)
	using vd = vector<double>;
	vd multiply(const vd& a, const vd& b) {
		int s = SZ(a) + SZ(b) - 1;
		if (s <= 0) return {};
		int L = s > 1 ? 32 - NumLeadingZeroes(s - 1) : 0, n = 1 << L;
		if (SZ(fa) < n) fa.resize(n);
		if (SZ(fb) < n) fb.resize(n);

		fill(fa.begin(), fa.begin() + n, 0);
		FORN(i, SZ(a)) fa[i].x = a[i];
		FORN(i, SZ(b)) fa[i].y = b[i];
		fft(fa, n);
		for (auto& x : fa) x = x * x;
		FORN(i, n) fb[i] = fa[(n - i) & (n - 1)] - conj(fa[i]);
		fft(fb, n);
		vd r(s);
		FORN(i, s) r[i] = fb[i].y / (4 * n);
		return r;
	}

	// Integer multiply mod m (num = complex) 
	VI multiply_mod(const VI& a, const VI& b, int m) {
		int s = SZ(a) + SZ(b) - 1;
		if (s <= 0) return {};
		int L = s > 1 ? 32 - NumLeadingZeroes(s - 1) : 0, n = 1 << L;
		if (SZ(fa) < n) fa.resize(n);
		if (SZ(fb) < n) fb.resize(n);

		FORN(i, SZ(a)) fa[i] = num(a[i] & ((1 << 15) - 1), a[i] >> 15);
		fill(fa.begin() + SZ(a), fa.begin() + n, 0);
		FORN(i, SZ(b)) fb[i] = num(b[i] & ((1 << 15) - 1), b[i] >> 15);
		fill(fb.begin() + SZ(b), fb.begin() + n, 0);

		fft(fa, n);
		fft(fb, n);
		double r0 = 0.5 / n; // 1/2n
		FORN(i, n / 2 + 1) {
			int j = (n - i) & (n - 1);
			num g0 = (fb[i] + conj(fb[j])) * r0;
			num g1 = (fb[i] - conj(fb[j])) * r0;
			swap(g1.x, g1.y); g1.y *= -1;
			if (j != i) {
				swap(fa[j], fa[i]);
				fb[j] = fa[j] * g1;
				fa[j] = fa[j] * g0;
			}
			fb[i] = fa[i] * conj(g1);
			fa[i] = fa[i] * conj(g0);
		}
		fft(fa, n);
		fft(fb, n);
		VI r(s);
		FORN(i, s) r[i] = int((LL(fa[i].x + 0.5)
			+ (LL(fa[i].y + 0.5) % m << 15)
			+ (LL(fb[i].x + 0.5) % m << 15)
			+ (LL(fb[i].y + 0.5) % m << 30)) % m);
		return r;
	}
#endif

} // namespace fft

// For multiply_mod, use num = modnum, poly = vector<num>
using fft::num;
using poly = fft::vn;
using fft::multiply;
using fft::inverse;

poly& operator+=(poly & a, const poly & b) {
	if (SZ(a) < SZ(b)) a.resize(b.size());
	FORN(i, SZ(b)) a[i] = a[i] + b[i];
	return a;
}
poly operator+(const poly & a, const poly & b) { poly r = a; r += b; return r; }
poly& operator-=(poly & a, const poly & b) {
	if (SZ(a) < SZ(b)) a.resize(b.size());
	FORN(i, SZ(b)) a[i] = a[i] - b[i];
	return a;
}
poly operator-(const poly & a, const poly & b) { poly r = a; r -= b; return r; }
poly operator*(const poly & a, const poly & b) {
	// TODO: small-case?
	return multiply(a, b);
}
poly& operator*=(poly & a, const poly & b) { return a = a * b; }

poly& operator*=(poly & a, const num & b) { // Optional
	for (auto& x : a) x = x * b;
	return a;
}
poly operator*(const poly & a, const num & b) { poly r = a; r *= b; return r; }

VI P[32];

void solve(int ks) {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int m = 0;
		while (n % 2 == 1 && n > 1) {
			n /= 2;
			m++;
		}
		printf("%d\n", P[m][k]);
	}
}

void gen() {
	P[0] = VI(1001, 0);
	P[0][0] = 1;
	for (int i = 1; i <= 31; i++) {
		P[i] = fft::multiply_mod(P[i - 1], P[i - 1], 7340033);
		P[i].resize(1001);
		P[i] = fft::multiply_mod(P[i], P[i], 7340033);
		P[i].resize(1001);
		for (int j = 1000; j >= 1; j--) P[i][j] = P[i][j - 1];
		P[i][0] = 1;
	}
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\Contests\\F\\sample.in", "r", stdin);
	//freopen("C:\\Home\\Contests\\F\\0.out", "w", stdout);
#endif

	gen();

	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 10);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			if (ks % 1 == 0) fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(1);
	}

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
	return 0;
}