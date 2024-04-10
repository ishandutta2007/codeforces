#include <bits/stdc++.h>

const int MAXN = 3333;
typedef long long LL;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
char buf[10010];
int P, A[MAXN], dig, alpha;
int f[2][MAXN][2][2];
inline int calc2(int x) { return (LL) (x + 1) * x / 2 % mod; }
inline int calc(int R) {
	if (R >= P) return ((LL) P * P - calc2(P * 2 - R - 2)) % mod;
	return calc2(R + 1);
}
int calc(int l, int r, int k) {
	l -= k, r -= k; l = std::max(l, 0);
	if (l > r) return 0; r = std::max(r, 0);
	int res = calc(r);
	if (l) reduce(res -= calc(l - 1));
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> P >> alpha >> buf;
	int len = strlen(buf);
	for (int i = 0; i < len; ++i) buf[i] &= 15;
	std::reverse(buf, buf + len);
	while (len) {
		LL now = 0;
		for (int i = len - 1; ~i; --i) {
			now = now * 10 + buf[i];
			buf[i] = now / P;
			now %= P;
		}
		A[dig++] = now;
		while (len && !buf[len - 1]) --len;
	}
	int now = 1, lst = 0;
	f[now][0][0][0] = 1;
	int ans = 0;
	for (int i = 0; i < dig; ++i) {
		std::swap(lst, now);
		int val = A[i];
		memset(f[now], 0, sizeof (int) * 2 * 2 * i);
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					if (int t = f[lst][j][k][l]) {
		reduce(f[now][j][0][0] += mul(t, calc(0, val - 1, l)) - mod);
		reduce(f[now][j + 1][0][1] += mul(t, calc(P, P + val - 1, l)) - mod);
		reduce(f[now][j][k][0] += mul(t, calc(val, val, l)) - mod);
		reduce(f[now][j + 1][k][1] += mul(t, calc(P + val, P + val, l)) - mod);
		reduce(f[now][j][1][0] += mul(t, calc(val + 1, P - 1, l)) - mod);
		reduce(f[now][j + 1][1][1] += mul(t, calc(P + val + 1, P * 2 - 1, l)) - mod);
					}
	}
	for (int j = dig - 1; j >= alpha; --j)
		reduce(ans += f[now][j][0][0] - mod);
	std::cout << ans << std::endl;
	return 0;
}