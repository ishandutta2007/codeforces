#include <bits/stdc++.h>

const int MAXN = 1 << 17;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

int n, K, X, Y, Z;
void FFT(int * A) {
	const int U = 1 << K;
	for (int mid = 1; mid != U; mid <<= 1)
		for (int k = 0; k != U; k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				const int Y = A[l + k + mid];
				reduce(A[l + k + mid] = A[l + k] - Y);
				reduce(A[l + k] += Y - mod);
			}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> X >> Y >> Z;
	const int U = 1 << K;
	int sm = 0;
	static int A[MAXN], B[MAXN], C[MAXN];
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		b ^= a, c ^= a;
		++A[b], ++B[c], ++C[b ^ c];
		sm ^= a;
	}
	FFT(A), FFT(B), FFT(C);
	LL a00 = remod((LL) X + Y + Z);
	LL a01 = remod((LL) X + Y - Z);
	LL a10 = remod((LL) X - Y + Z);
	LL a11 = remod((LL) X - Y - Z);
	for (int i = 0; i != U; ++i) {
		int a = A[i], b = B[i], c = C[i];
		A[i] = (LL)
				pow(a00, remod((LL) n + a + b + c) >> 2) *
				pow(a01, remod((LL) n + a - b - c) >> 2) % mod *
				pow(a10, remod((LL) n - a + b - c) >> 2) % mod *
				pow(a11, remod((LL) n - a - b + c) >> 2) % mod;
	}
	FFT(A);
	const int liminv = pow(U, mod - 2);
	for (int i = 0; i != U; ++i)
		A[i] = mul(A[i], liminv);
	for (int i = 0; i != U; ++i)
		std::cout << A[i ^ sm] << (" \n" [i == U - 1]);
	return 0;
}