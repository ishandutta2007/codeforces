#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5009;
const int P = 1e9 + 7;
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
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
namespace Lagrange {
	int n; long long x[MAXN], y[MAXN], a[MAXN];
	long long p[MAXN], q[MAXN];
	void work() {
		memset(p, 0, sizeof(p)); p[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				p[j + 1] = (p[j + 1] + p[j]) % P;
				p[j] = (P - p[j] * x[i] % P) % P;
			}
		}
		for (int i = 1; i <= n; i++) {
			memset(q, 0, sizeof(q));
			for (int j = n - 1; j >= 0; j--)
				q[j] = (p[j + 1] + q[j + 1] * x[i]) % P;
			long long now = 1;
			for (int j = 1; j <= n; j++)
				if (j != i) now = now * (x[i] - x[j]) % P;
			now = power((P + now) % P, P - 2);
			for (int j = 0; j <= n; j++)
				q[j] = q[j] * now % P;
			for (int j = 0; j <= n; j++)
				a[j] = (a[j] + q[j] * y[i]) % P;
		}
	}
	long long get(long long x) {
		long long ans = 0, now = 1;
		for (int i = 0; i <= n; i++) {
			ans = (ans + now * a[i]) % P;
			now = now * x % P;
		}
		return ans;
	}
}
long long mul[MAXN], fac[MAXN], inv[MAXN];
long long c(int x, int y) {return fac[x] * inv[y] % P * inv[x - y] % P; }
int main() {
	int n, k; read(n), read(k);
	for (int i = 1; i < MAXN; i++)
		mul[i] = power(i, k);
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[MAXN - 1] = power(fac[MAXN - 1], P - 2);
	for (int i = MAXN - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	long long two = 1, owt = power(2, P - 2);
	for (int i = 1; i <= k + 5; i++) {
		long long now = 0;
		for (int j = 1; j <= i; j++)
			now += c(i, j) * mul[j] % P;
		now %= P; two = two * owt % P;
		using namespace Lagrange;
		Lagrange::n++, x[Lagrange::n] = i, y[Lagrange::n] = now * two % P;
	}
	Lagrange::work();
	writeln(Lagrange::get(n) * power(2, n) % P);
	return 0;
}