#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int n, m; long double ans;
long long calc(int x, int y) {
	int len = y - x + 1;
	return 1ll * (x + y) * len / 2;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, d; read(x), read(d);
		ans += x * n;
		if (d >= 0) ans += d * calc(0, n - 1);
		else {
			if (n & 1) ans += 2 * d * calc(0, n / 2);
			else ans += d * (calc(0, n / 2) + calc(0, n / 2 - 1));
		}
	}
	printf("%.10Lf\n", ans / n);
	return 0;
}