#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
struct point {int x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
long long operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
ll x[MAXN], y[MAXN], sx, sy;
int main() {
	int n; read(n);
	if (n & 1) {
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]);
		sx += x[i], sy += y[i];
	}
	for (int i = 1, j = n / 2 + 1; j <= n; i++, j++)
		if (x[i] * n + x[j] * n != sx * 2
		||  y[i] * n + y[j] * n != sy * 2) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}