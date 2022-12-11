#include <bits/stdc++.h>

const int MAXN = 100010;
int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

int n, L, R;
int fac[MAXN], inv[MAXN];
int cnt[MAXN][20];
int li[MAXN], bak;
void factor() {
	int t = mod;
	for (int i = 2; i * i <= t; ++i)
		if (t % i == 0) {
			while (t % i == 0) t /= i;
			li[bak++] = i;
		}
	if (t > 1) li[bak++] = t;
}
int factor(int * A, int t) {
	for (int i = 0; i < bak; ++i)
		while (t % li[i] == 0)
			t /= li[i], ++A[i];
	return t;
}
void exgcd(int a, int b, int & x, int & y) {
	if (!b) { x = 1, y = 0; }
	else {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}
int getinv(int x) {
	int a, b;
	exgcd(x, mod, a, b);
	a += a >> 31 & mod;
	return a;
}
const int HI = 100;
int pws[20][HI];
int C(int a, int b) {
	int rs = (LL) fac[a] * inv[b] % mod * inv[a - b] % mod;
	for (int i = 0; i < bak; ++i) {
		int px = cnt[a][i] - cnt[b][i] - cnt[a - b][i];
		rs = mul(rs, pws[i][px]);
	}
	return rs;
}
int main() {
	std::cin >> n >> mod >> L >> R;
	factor();
	for (int i = 0; i != bak; ++i) {
		pws[i][0] = 1;
		for (int j = 1; j < HI; ++j)
			pws[i][j] = mul(pws[i][j - 1], li[i]);
	}
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; ++i) {
		memcpy(cnt[i], cnt[i - 1], bak << 2);
		fac[i] = (LL) fac[i - 1] * factor(cnt[i], i) % mod;
	}
	for (int i = 0; i <= n; ++i) inv[i] = getinv(fac[i]);
//	std::cout << C(5, 2) << std::endl;
//	return 0;
	int ans = 0;
	for (int D = 0; D <= n; ++D) {
		int l = std::max(D - R, 0), r = D - L;
		if (l > r || r < 0) continue;
		l = (l >> 1) + (l & 1), r >>= 1;
		int t = C(D, r);
		if (l) reduce(t -= C(D, l - 1));
		ans = ((LL) t * C(n, D) + ans) % mod;
	}
	std::cout << ans << std::endl;
	return 0;
}