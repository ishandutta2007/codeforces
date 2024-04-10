#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
const int P = 998244353;
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
int binom(int x, int y) {
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
int a[MAXN], b[MAXN], cnt[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	int n, Max = 0; read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		b[a[i] + 1]++;
		chkmax(Max, a[i]);
	}
	init(Max + n);
	for (int i = 1; i <= n; i++)
	for (int j = a[i] + 1; j <= Max; j += n)
		cnt[j]++;
	int ans = 1, empty = 0, lft = n;
	for (int i = 1; i <= Max; i++) {
		empty++, lft -= b[i];
		if (empty < cnt[i]) break;
		empty -= cnt[i];
		update(ans, binom(empty + n - 1, n - 1));
		if (empty >= lft) update(ans, P - binom(empty - lft + n - 1, n - 1));
	}
	writeln(ans);
	return 0;
}