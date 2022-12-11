#include <bits/stdc++.h>

const int MAXN = 1048577;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int x, int y) { return (LL) x * y % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int lim, dig, rev[MAXN], wn[MAXN], wt[MAXN];
void init(int sz) {
	lim = 1, dig = -1;
	while (lim < sz) lim <<= 1, ++dig;
	for (int i = 1; i != lim; ++i)
		rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
	const int W = pow(3, (mod - 1) / lim);
	for (int i = *wn = 1; i <= lim; ++i)
		wn[i] = mul(wn[i - 1], W);
}
void NTT(int * A, int typ) {
	for (int i = 0; i < lim; ++i) if (i < rev[i])
		std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int i = 0, W = 0; i != mid; W += Wn, ++i)
			wt[i] = wn[typ == 1 ? W : lim - W];
		for (int k = 0; k != lim; k += mid << 1) {
			const int * W = wt;
			for (int l = 0; l != mid; ++l) {
				const int X = A[l + k], Y = mul(A[l + k + mid], *W++);
				reduce(A[l + k] = X + Y - mod);
				reduce(A[l + k + mid] = X - Y);
			}
		}
	}
	if (typ == -1) {
		const int liminv = pow(lim, mod - 2);
		for (int i = 0; i != lim; ++i)
			A[i] = mul(A[i], liminv);
	}
}

int n;
char buf[MAXN];
int A[MAXN], B[MAXN];
void solve() {
	std::cin >> n >> buf;
	const int sz = n * 2 - 1;
	init(sz);
	memset(A, 0, lim << 2);
	memset(B, 0, lim << 2);
	for (int i = 0; i != n; ++i) A[i] = buf[i] == 'V';
	for (int i = 0; i != n; ++i) B[n - i - 1] = buf[i] == 'K';
	NTT(A, 1); NTT(B, 1);
	for (int i = 0; i != lim; ++i) A[i] = mul(A[i], B[i]);
	NTT(A, -1);
	static int li[MAXN >> 1], bak;
	bak = 0;
	for (int i = 1; i <= n; ++i) {
		bool can = true;
		for (int j = i; j < n; j += i)
			can &= A[j + n - 1] == 0 && A[n - j - 1] == 0;
		if (can) li[++bak] = i; 
	}
	std::cout << bak << '\n';
	for (int i = 1; i <= bak; ++i)
		std::cout << li[i] << (" \n" [i == bak]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) solve();
	return 0;
}