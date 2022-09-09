#include<bits/stdc++.h>
using namespace std;
const int MAXN = 150005;
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
long long x[MAXN], y[MAXN];
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	long long ans = 0;
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]);
		ans = gcd(x[i] * y[i], ans);
	}
	if (ans == 1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (gcd(ans, x[i]) != 1) ans = gcd(ans, x[i]);
		else ans = gcd(ans, y[i]);
	}
	writeln(ans);
	return 0;
}