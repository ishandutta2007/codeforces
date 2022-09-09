#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long double INF = 1e100;
const long double eps = 1e-12;
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
int n, p, q;
long double a[MAXN], b[MAXN];
long double check(long double x) {
	long double y = 1;
	for(int i = 1; i <= n; i++)
		chkmin(y, (1.0 - x * a[i]) / b[i]);
	return x * p + y * q;
}
int main() {
	read(n), read(p), read(q);
	long double l = 0, r = INF;
	for (int i = 1; i <= n; i++) {
		read(a[i]), read(b[i]);
		chkmin(r, 1.0 / a[i]);
	}
	while (l + eps < r) {
		long double ml = (2 * l + r) / 3, mr = (l + 2 * r) / 3;
		if (check(ml) > check(mr)) r = mr;
		else l = ml;
	}
	printf("%.10Lf\n", check((l + r) / 2));
	return 0;
}