#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

long long f;
long long M, P;

vector<long long> A, B;

void get(long long m, long long n, long long r, long long r1, long long x, long long y) {
	if (m == M) {
		B.push_back(n);
		return;
	}
	long long m1 = m * 5;
	long long xx = 0, yy = 1;
	for (int i = 0; i < 5; i++) {
		long long tx = (x * xx + y * yy) % M;
		yy = (y * xx + (x + y) % M * yy) % M;
		xx = tx;
	}
	swap(xx, yy);
	xx = (xx - yy + M) % M;
	for (int i = 0; i < 5; i++) {
		if ((f - r) % m1 == 0) {
			get(m1, n, r, r1, xx, yy);
			return;
		}
		n += 4 * m;
		long long tr = (x * r + y * r1) % M;
		r1 = (y * r + (x + y) % M * r1) % M;
		r = tr;
	}
}

template <typename T>
T extEuclid(T a, T b, T &x, T &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	T d = extEuclid(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

long long crt(long long a1, long long m1, long long a2, long long m2) {
	long long n1, n2;
	extEuclid(m1, m2, n1, n2);
	n1 = (n1 % m2 + m2) % m2;
	n2 = (n2 % m1 + m1) % m1;
	return (1LL * a1 * n2 % m1 * m2 + 1LL * a2 * n1 % m2 * m1) % (m1 * m2);
}

int main() {
	scanf("%lld", &f);
	long long a = -1, b = 1;
	M = 8192, P = 12288;
	for (int i = 0; i < P; i++) {
		a = (a + b) % M, swap(a, b);
		if ((f - b) % M == 0) A.push_back(i);
	}
	M = 1;
	for (int i = 0; i < 13; i++) M *= 5;
	a = -1, b = 1;
	for (int i = 0; i < 20; i++) {
		a = (a + b) % M, swap(a, b);
	}
	long long a1 = b, b1 = (a + b) % M;
	a = -1, b = 1;
	for (int i = 0; i < 20; i++) {
		a = (a + b) % M, swap(a, b);
		if ((f - b) % 5 == 0) get(5, i, b, (a + b) % M, a1, b1);
	}
	long long ans = 1LL<<60;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			long long x1 = A[i], m1 = 3072;
			long long x2 = B[j], m2 = M;
			if ((x1 - x2) % 4 != 0) continue;
			int r = x1 % 4;
			x1 /= 4, x2 /= 4;
			chkmin(ans, crt(x1, m1, x2, m2) * 4 + r);
		}
	}
	if (ans > 1LL<<50) {
		puts("-1");
		return 0;
	}
	cout << ans << endl;
	return 0;
}