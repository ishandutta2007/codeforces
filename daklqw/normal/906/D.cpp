#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;

int n, m, A[MAXN], pl[MAXN], bak;
int phi(int x) {
	int res = 1;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
		res *= i - 1; x /= i;
		while (x % i == 0) res *= i, x /= i;
	}
	if (x != 1) res *= x - 1;
	return res;
}
bool GREATER_SIGN;
int fastpow(int a, int b, const int mod) {
	GREATER_SIGN = false; bool AG_SIGN = false;
	int res = 1;
	if (a >= mod) AG_SIGN = true; a %= mod;
	LL t;
	while (b) {
		if (b & 1) {
			t = static_cast<LL> (res) * a;
			if (AG_SIGN || t >= mod) GREATER_SIGN = true;
			res = t % mod;
		}
		t = static_cast<LL> (a) * a;
		if (AG_SIGN || t >= mod) AG_SIGN = true;
		a = t % mod;
		b >>= 1;
	}
	return res;
}
int calc(int l, int r, int dep) {
	const int mod = pl[dep];
	if (l == r || mod == 1) return A[l] % mod + (A[l] >= mod) * mod;
	int pw = fastpow(A[l], calc(l + 1, r, dep + 1), mod);
	return pw + GREATER_SIGN * mod;
}
int main() {
	scanf("%d%d", &n, &m);
	pl[bak = 1] = m;
	while (pl[bak] != 1) pl[bak + 1] = phi(pl[bak]), ++bak;
	for (int i = 1; i <= n; ++i) scanf("%d", A + i);
	int T; scanf("%d", &T);
	while (T --> 0) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", calc(l, r, 1) % m);
	}
	return 0;
}