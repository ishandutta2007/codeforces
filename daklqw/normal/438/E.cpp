#include <bits/stdc++.h>

const int MAXN = 1 << 18 | 10;
const int mod = 119 << 23 | 1;
const int inv2 = mod + 1 >> 1;

typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int r = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a);
	return r;
}

int wn[MAXN], rev[MAXN], lim, dig;
void initall(int sz) {
	for (int mid = 1; mid < sz; mid <<= 1) {
		const int Wn = pow(3, (mod - 1) / mid / 2);
		for (int i = 0, W = 1; i != mid; ++i)
			wn[mid + i] = W, W = mul(W, Wn);
	}
}
void init(int sz) {
	lim = 1, dig = -1;
	while (lim < sz) lim <<= 1, ++dig;
	for (int i = 0; i != lim; ++i)
		rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
}

void NTT(int * A, int typ) {
	for (int i = 0; i < lim; ++i) if (rev[i] < i)
		std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1)
		for (int k = 0; k != lim; k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				const int Y = mul(A[l + k + mid], wn[mid + l]);
				reduce(A[l + k + mid] = A[l + k] - Y);
				reduce(A[l + k] += Y - mod);
			}
	if (typ == -1) {
		const int liminv = pow(lim, mod - 2);
		for (int i = 0; i != lim; ++i) A[i] = mul(A[i], liminv);
		std::reverse(A + 1, A + lim);
	}
}

int A[MAXN], B[MAXN], n, m;
void copy(int * B, const int * A, int L) {
	std::memcpy(B, A, L << 2);
	std::memset(B + L, 0, lim - L << 2);
}
void INV(int * B, const int * A, int m) {
	if (m == 1) return (void) (*B = pow(*A, mod - 2));
	const int mid = m + 1 >> 1;
	INV(B, A, mid);
	static int ta[MAXN], tb[MAXN];
	init(mid + m - 1);
	copy(ta, A, m), copy(tb, B, mid);
	NTT(ta, 1), NTT(tb, 1);
	for (int i = 0; i != lim; ++i)
		ta[i] = (LL) (mod - ta[i]) * tb[i] % mod * tb[i] % mod;
	NTT(ta, -1);
	std::copy(ta + mid, ta + m, B + mid);
}
void solve(int * B, const int * A, int m) {
	if (m == 1) return (void) (*B = 1);
	const int mid = m + 1 >> 1;
	solve(B, A, mid);
	static int ta[MAXN], tb[MAXN];
	init(mid + m - 1);
	copy(ta, A, m), copy(tb, B, mid);
	NTT(ta, 1), NTT(tb, 1);
	for (int i = 0; i != lim; ++i) ta[i] = mul(ta[i], tb[i]);
	NTT(ta, -1);
	for (int i = 0; i != m; ++i) ta[i] = mul(ta[i], 4);
	reduce(*ta -= 2);
	INV(tb, ta, m);
	init(m);
	memset(tb + m, 0, lim - m << 2);
	copy(ta, B, mid);
	reduce(*ta -= 2);
	NTT(ta, 1); NTT(tb, 1);
	for (int i = 0; i != lim; ++i) ta[i] = mul(ta[i], tb[i]);
	NTT(ta, -1);
	std::copy(ta + mid, ta + m, B + mid);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m; ++m;
	init(m + (m + 1 >> 1) - 1);
	initall(lim);
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, A[t] = 1;
	solve(B, A, m);
	for (int i = 1; i < m; ++i)
		std::cout << B[i] << '\n';
	return 0;
}