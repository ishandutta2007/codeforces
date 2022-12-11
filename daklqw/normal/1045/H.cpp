#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXS = 300010;
int fac[MAXS], inv[MAXS];
int C(int a, int b) { return a < b ? 0 : (LL) fac[a] * inv[b] % mod * inv[a - b] % mod; }
int put(int x, int y) {
	if (y == 0) return x == 0;
	return C(x + y - 1, y - 1);
}
int solve(int _c[2][2], bool up = false) {
	static int c[2][2]; memcpy(c, _c, 16);
	if (up) {
		std::swap(c[0][1], c[1][0]);
		std::swap(c[0][0], c[1][1]);
	}
	if (c[0][1] != c[1][0] && c[0][1] + 1 != c[1][0]) return 0;
	int c0 = c[1][0], c1 = c[0][1] + 1;
	return mul(put(c[0][0], c0), put(c[1][1], c1));
}
int calc(const char * S, int _c[2][2]) {
	static int c[2][2]; memcpy(c, _c, 16);
	const int dig = c[0][0] + c[0][1] + c[1][0] + c[1][1] + 1;
	int L = strlen(S);
	while (L && S[L - 1] == '0') --L;
	if (dig < L) return solve(c);
	if (dig > L) return 0;
	LL ans = 0;
	for (int i = L - 2; ~i; --i) {
		int lst = S[i + 1] & 15;
		if (S[i] == '1') {
			if (--c[lst][0] >= 0)
				ans += solve(c, true);
			++c[lst][0];
		}
		if (--c[lst][S[i] & 15] < 0) break;
	}
	if (c[0][0] == 0 && c[0][1] == 0 && c[1][0] == 0 && c[1][1] == 0) ++ans;
	return ans % mod;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXS; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	static char L[MAXN], R[MAXN];
	static int c[2][2];
	std::cin >> L >> R;
	std::reverse(L, L + strlen(L));
	std::reverse(R, R + strlen(R));
	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 2; ++j)
			std::cin >> c[i][j];
	int Ans = calc(R, c), cur = 0;
	while (L[cur] != '1') ++cur;
	L[cur--] = '0';
	while (~cur) L[cur--] = '1';
	reduce(Ans -= calc(L, c));
	std::cout << Ans << std::endl;
	return 0;
}