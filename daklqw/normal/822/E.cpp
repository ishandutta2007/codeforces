#include <bits/stdc++.h>

const int MAXN = 524289;

int rk[MAXN], SA[MAXN], tl[MAXN], buc[MAXN];
char buf[MAXN];
void sort(int n, int ran) {
	memset(buc, 0, ran + 1 << 2);
	for (int i = 1; i <= n; ++i) ++buc[rk[i]];
	for (int i = 1; i <= ran; ++i) buc[i] += buc[i - 1];
	for (int i = n; i; --i) SA[buc[rk[tl[i]]]--] = tl[i];
}
bool cmp(int x, int y, int len) {
	return tl[x] == tl[y] && tl[x + len] == tl[y + len];
}
int lg2[MAXN], RMQ[17][262145];
void build(int n) {
	for (int i = 1; i <= n; ++i) rk[i] = buf[i], tl[i] = i;
	sort(n, 256);
	for (int len = 1; len <= n; len <<= 1) {
		int bak = 0, cnt = 1;
		for (int i = 1; i <= n; ++i) if (len + i > n) tl[++bak] = i;
		for (int i = 1; i <= n; ++i) if (SA[i] > len) tl[++bak] = SA[i] - len;
		sort(n, n);
		memcpy(tl, rk, n + 1 << 2);
		rk[SA[1]] = cnt;
		for (int i = 2; i <= n; ++i)
			rk[SA[i]] = cmp(SA[i], SA[i - 1], len) ? cnt : ++cnt;
	}
	lg2[0] = -1;
	for (int i = 1; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		if (now) --now;
		int at = SA[rk[i] - 1];
		while (buf[now + at] == buf[now + i]) ++now;
		RMQ[0][rk[i]] = now;
	}
	for (int i = 1; i != 17; ++i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++j)
			RMQ[i][j] = std::min(RMQ[i - 1][j], RMQ[i - 1][j + (1 << i - 1)]);
}
int LCP(int x, int y) {
	x = rk[x], y = rk[y];
	if (x > y) std::swap(x, y);
	++x; int lg = lg2[y - x + 1];
	return std::min(RMQ[lg][x], RMQ[lg][y - (1 << lg) + 1]);
}
int K, n, f[MAXN][31], m, len;
void getmax(int & x, int y) { x < y ? x = y : 0; }

int main() {
	std::cin >> n >> buf + 1;
	std::cin >> m >> buf + 2 + n >> K;
	len = n + m + 1;
	*(buf + n + 1) = '{';
	*(buf + len + 1) = 0;
	build(len);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= K; ++j) {
			if (f[i][j] == m) {
				std::cout << "YES" << std::endl;
				return 0;
			}
			getmax(f[i + 1][j], f[i][j]);
			if (j == K) break;
			int L = LCP(i + 1, f[i][j] + n + 2);
			getmax(f[i + L][j + 1], f[i][j] + L);
		}
	std::cout << "NO" << std::endl;
	return 0;
}