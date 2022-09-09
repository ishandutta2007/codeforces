#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const long double eps = 1e-10;
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
	long double R, X1, Y1, X2, Y2;
	read(R), read(X1), read(Y1), read(X2), read(Y2);
	long double dist = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
	if (dist >= R - eps) {
		printf("%.10Lf %.10Lf %.10Lf\n", X1, Y1, R - eps);
		return 0;
	}
	if (dist <= eps) {
		printf("%.10Lf %.10Lf %.10Lf\n", X1 + R / 2, Y1, R / 2 - eps);
		return 0;
	}
	long double ans = (R + dist) / 2 - eps, dx, dy;
	dx = X1 - X2, dy = Y1 - Y2;
	printf("%.10Lf %.10Lf %.10Lf\n", X2 + dx / dist * (dist + R) / 2, Y2 + dy / dist * (dist + R) / 2, ans);
	return 0;
}