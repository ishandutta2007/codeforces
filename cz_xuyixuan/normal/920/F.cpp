#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
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
struct BIT {
	long long a[MAXN]; int n;
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int y) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += y;
	}
	long long query(int x, int y) {
		long long ans = 0;
		for (int i = y; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = x - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} bit;
int tot, prime[MAXN], d[MAXN];
int n, m, f[MAXN], a[MAXN];
void init() {
	d[1] = 1;
	static int f[MAXN], g[MAXN];
	for (int i = 2; i < MAXN; i++) {
		if (f[i] == 0) {
			prime[++tot] = f[i] = g[i] = i;
			d[i] = 2;
			int j = i, k = 2;
			while ((MAXN - 1) / j >= i) {
				j *= i, k++;
				d[j] = k;
			}
		} else if (g[i] != i) d[i] = d[g[i]] * d[i / g[i]];
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp >= MAXN) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) g[tmp] = g[i] * f[i];
			else g[tmp] = prime[j];
		}
	}
}
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	init();
	read(n), read(m);
	bit.init(n);
	for (int i = 1; i <= n; i++)
		f[i] = i, read(a[i]), bit.modify(i, a[i]);
	f[n + 1] = n + 1;
	for (int i = 1; i <= m; i++) {
		int opt, l, r;
		read(opt), read(l), read(r);
		if (opt == 2) writeln(bit.query(l, r));
		else {
			for (int j = F(l); j <= r; j = F(j + 1)) {
				int delta = d[a[j]] - a[j];
				bit.modify(j, delta);
				a[j] = d[a[j]];
				if (a[j] <= 2) f[j] = j + 1;
			}
		}
	}
	return 0;
}