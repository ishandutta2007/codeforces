#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const long double eps = 1e-17;
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
int main() {
	int x, y;
	read(x), read(y);
	long double a = y * log(x);
	long double b = x * log(y);
	if (a - b > eps) printf(">");
	else if (b - a > eps) printf("<");
	else printf("=");
	return 0;
}