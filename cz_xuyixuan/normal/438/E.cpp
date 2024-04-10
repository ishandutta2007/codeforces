#include<bits/stdc++.h>
using namespace std;
const int MAXN = 524288;
const int P = 998244353;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
namespace NTT {
	const int G = 3;
	int power(int x, int y) {
		if (y == 0) return 1;
		int tmp = power(x, y / 2);
		if (y % 2 == 0) return 1ll * tmp * tmp % P;
		else return 1ll * tmp * tmp % P * x % P;
	}
	int N, Log, home[MAXN];
	void NTTinit() {
		for (int i = 0; i < N; i++) {
			int ans = 0, tmp = i;
			for (int j = 1; j <= Log; j++) {
				ans <<= 1;
				ans += tmp & 1;
				tmp >>= 1;
			}
			home[i] = ans;
		}
	}
	void NTT(int *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] < i) swap(a[i], a[home[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			int delta;
			if (mode == 1) delta = power(G, (P - 1) / len);
			else delta = power(G, P - 1 - (P - 1) / len);
			for (int i = 0; i < N; i += len) {
				int now = 1;
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					int tmp = a[j];
					int tnp = 1ll * a[k] * now % P;
					a[j] = (tmp + tnp) % P;
					a[k] = (tmp - tnp + P) % P;
					now = 1ll * now * delta % P;
				}
			}
		}
		if (mode == -1) {
			int inv = power(N, P - 2);
			for (int i = 0; i < N; i++)
				a[i] = 1ll * a[i] * inv % P;
		}
	}
	void times(int *a, int *b, int *c, int limit) {
		N = 1, Log = 0;
		while (N < 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = limit; i < N; i++)
			a[i] = b[i] = 0;
		NTTinit();
		NTT(a, 1);
		NTT(b, 1);
		for (int i = 0; i < N; i++)
			c[i] = 1ll * a[i] * b[i] % P;
		NTT(c, -1);
	}
	void timesabb(int *a, int *b, int *c, int limit) {
		N = 1, Log = 0;
		while (N < 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = limit; i < N; i++)
			a[i] = 0;
		for (int i = limit / 2; i <= N; i++)
			b[i] = 0;
		NTTinit();
		NTT(a, 1);
		NTT(b, 1);
		for (int i = 0; i < N; i++)
			c[i] = 1ll * a[i] * b[i] % P * b[i] % P;
		NTT(c, -1);
	}
	void inverse(int *a, int *b, int limit) {
		for (int i = 0; i < 2 * limit; i++) {
			if (i >= limit) a[i] = 0;
			b[i] = 0;
		}
		b[0] = power(a[0], P - 2);
		for (int now = 1; now < limit; now <<= 1) {
			static int c[MAXN], d[MAXN];
			for (int i = 0; i < now * 2; i++)
				c[i] = a[i], d[i] = b[i];
			timesabb(c, d, d, now * 2);
			for (int i = 0; i < now * 2; i++)
				b[i] = (2ll * b[i] - d[i] + P) % P;
		}
	}
	void getsqrt(int *a, int *b, int limit, int residue) {
		for (int i = 0; i < 2 * limit; i++) {
			if (i >= limit) a[i] = 0;
			b[i] = 0;
		}
		b[0] = residue; int inv = power(2, P - 2);
		for (int now = 1; now < limit; now <<= 1) {
			static int c[MAXN], d[MAXN];
			for (int i = 0; i < now * 2; i++)
				c[i] = a[i];
			inverse(b, d, now * 2);
			times(c, d, d, now * 2);
			for (int i = 0; i < now * 2; i++)
				b[i] = 1ll * (b[i] + d[i]) * inv % P;
		}
	}
}
int n, m;
int f[MAXN], c[MAXN], g[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		c[x] = P - 4;
	}
	c[0] = 1;
	NTT::getsqrt(c, g, m + 1, 1);
	g[0] = (g[0] + 1) % P;
	NTT::inverse(g, f, m + 1);
	for (int i = 1; i <= m; i++)
		writeln(f[i] * 2 % P);
	return 0;
}