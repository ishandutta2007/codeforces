#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
const int P = 1e9 + 7;
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
int fac[MAXN], inv[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int getc(int x, int y) {
	if (y > x) return 0;
	else return 1ll * fac[x] * inv[y] % P * inv[x - y] % P;
}
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1ll) % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	int n, m;
	read(n), read(m);
	init(n + m);
	int ans = 0, cnt = power(n, n - 2), inv = power(n, P - 2);
	for (int i = 1; i <= n - 1; i++) {
		cnt = 1ll * cnt * inv % P;
		int trees = 1ll * cnt * (i + 1) % P;
		int midps = 1ll * getc(n - 2, i - 1) * fac[i - 1] % P;
		int val = 1ll * getc(m - 1, i - 1) * power(m, n - 1 - i) % P;
		update(ans, 1ll * trees * midps % P * val % P);
	}
	writeln(ans);
	return 0;
}