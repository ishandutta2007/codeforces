#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define MAXN 524289
const double PI = acos(-1);
struct Complex {
	double a, i;
	Complex(double _ = 0, double __ = 0) { a = _; i = __; }
	inline friend Complex operator + (const Complex & A, const Complex & B) { return (Complex) {A.a + B.a, A.i + B.i}; }
	inline friend Complex operator - (const Complex & A, const Complex & B) { return (Complex) {A.a - B.a, A.i - B.i}; }
	inline friend Complex operator * (const Complex & A, const Complex & B) { return (Complex) {A.a * B.a - A.i * B.i, A.i * B.a + A.a * B.i}; }
} A[MAXN], B[MAXN];
int rev[MAXN], lim, dig;
void init(int sz) {
	lim = 1; dig = 0;
	while (lim <= sz) lim <<= 1, ++dig;
	for (int i = 1; i != lim; ++i)
		rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (dig - 1);
}
void FFT(Complex * A, int type) {
	for (int i = 0; i != lim; ++i)
		if (i < rev[i])
			swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		Complex Wn(cos(PI / mid), type * sin(PI / mid));
		for (int k = 0; k != lim; k += (mid << 1)) {
			Complex W(1, 0);
			for (int l = 0; l != mid; ++l, W = W * Wn) {
				Complex X = A[l + k], Y = A[l + k + mid] * W;
				A[l + k] = X + Y;
				A[l + k + mid] = X - Y;
			}
		}
	}
	if (type == -1) for (int i = 0; i != lim; ++i) A[i].a /= lim;
}
LL ansl[MAXN];
int n, x, a[MAXN], prel[MAXN], prer[MAXN];
void solve(int l, int r) {
	if (l == r) { ++ansl[a[l]]; return ; }
	int mid = l + r >> 1;
	solve(l, mid); solve(mid + 1, r);
	int llen = mid - l + 1, rlen = r - mid;
	init(llen + rlen);
	for (int i = 0; i != lim; ++i) A[i].a = A[i].i = B[i].a = B[i].i = 0;
	int bak1 = 0, bak2 = 0;
	for (int i = mid; i >= l; --i) ++bak1, prel[bak1] = prel[bak1 - 1] + a[i];
	for (int i = mid + 1; i <= r; ++i) ++bak2, prer[bak2] = prer[bak2 - 1] + a[i];
	for (int i = 1; i <= bak1; ++i) A[prel[i]].a += 1;
	for (int i = 1; i <= bak2; ++i) B[prer[i]].a += 1;
	FFT(A, 1); FFT(B, 1);
	for (int i = 0; i != lim; ++i) A[i] = A[i] * B[i];
	FFT(A, -1);
	for (int i = 0; i != lim; ++i) ansl[i] += (long long)(A[i].a + 0.5);
}
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] = a[i] < x;
	solve(1, n);
	for (int i = 0; i <= n; ++i) printf("%lld ", ansl[i]); putchar(10);
	return 0;
}