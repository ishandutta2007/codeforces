#include <bits/stdc++.h>

const int MAXN = 1e5;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}

char buf[MAXN]; int n, m, Q;
int cnt[52];
int trans(char x) {
	return 'A' <= x && x <= 'Z' ? x - 'A' : x - 'a' + 26;
}
int inv[MAXN];
int gfac(int x) {
	int res = 1;
	for (int i = 1; i <= x; ++i) res = mul(res, i);
	return res;
}
int f[MAXN];
void add(int x) {
	for (int i = n; i >= x; --i)
		reduce(f[i] += f[i - x] - mod);
}
void dec(int x) {
	for (int i = 0; i + x <= n; ++i)
		reduce(f[i + x] -= f[i]);
}
int ansl[52][52];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf >> Q;
	n = (m = strlen(buf)) / 2;
	for (int i = 0; i < m; ++i) ++cnt[trans(buf[i])];
	int coef = pow(gfac(n), 2);
	int ma = 0;
	f[0] = 1;
	for (int i = 0; i < 52; ++i) if (cnt[i]) {
		coef = pow(gfac(cnt[i]), mod - 2, coef);
		add(cnt[i]);
		ma = std::max(ma, cnt[i]);
	}
	int all = mul(f[n], coef);
	if (ma <= n)
	for (int i = 0; i < 52; ++i) if (cnt[i]) {
		dec(cnt[i]);
		for (int j = i + 1; j < 52; ++j) if (cnt[j]) {
			int hi = n - cnt[i] - cnt[j];
			int t = 0;
			for (int k = 0; k <= hi; k += cnt[j] * 2)
				reduce(t += f[hi - k] - mod);
			for (int k = cnt[j]; k <= hi; k += cnt[j] * 2)
				reduce(t -= f[hi - k]);
			ansl[i][j] = ansl[j][i] = mul(t, coef * 2);
		}
		add(cnt[i]);
	}
	while (Q --> 0) {
		int x, y;
		std::cin >> x >> y;
		x = trans(buf[x - 1]), y = trans(buf[y - 1]);
		std::cout << (x == y ? all : ansl[x][y]) << '\n';
	}
	return 0;
}