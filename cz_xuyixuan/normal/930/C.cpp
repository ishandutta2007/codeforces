#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int n, m, Max, x[MAXN];
int a[MAXN], f[MAXN], g[MAXN];
int main() {
	read(m), read(n);
	for (int i = 1; i <= m; i++) {
		int y, z; read(y), read(z);
		x[y]++, x[z + 1]--;
	}
	for (int i = 1; i <= n; i++)
		x[i] += x[i - 1];
	memset(a, 0, sizeof(a));
	Max = 1, f[1] = 1, a[1] = x[1];
	for (int i = 2; i <= n; i++) {
		int tmp = upper_bound(a, a + Max + 1, x[i]) - a;
		f[i] = tmp;
		if (tmp == Max + 1) a[++Max] = x[i];
		else a[tmp] = min(a[tmp], x[i]);
	}
	memset(a, 0, sizeof(a));
	Max = 1, g[n] = 1, a[1] = x[n];
	for (int i = n - 1; i >= 1; i--) {
		int tmp = upper_bound(a, a + Max + 1, x[i]) - a;
		g[i] = tmp;
		if (tmp == Max + 1) a[++Max] = x[i];
		else a[tmp] = min(a[tmp], x[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i] + g[i] - 1);
	writeln(ans);
	return 0;
}