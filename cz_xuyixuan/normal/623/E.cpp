#include<bits/stdc++.h>
using namespace std;
const int MAXN = 262144;
const int MAXLOG = 15;
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
namespace AnyModuloFFT {
	const int MAXN = 262144;
	const long double pi = acosl(-1);
	struct point {long double x, y; };
	point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
	point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
	point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
	point operator / (point a, long double x) {return (point) {a.x / x, a.y / x}; }
	int N, Log, home[MAXN];
	point tmp[MAXN];
	void FFTinit() {
		for (int i = 0; i < N; i++) {
			int tmp = i, ans = 0;
			for (int j = 1; j <= Log; j++) {
				ans <<= 1;
				ans += tmp & 1;
				tmp >>= 1;
			}
			home[i] = ans;
		}
	}
	void FFT(point *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] < i) swap(a[i], a[home[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			point delta = (point) {cosl(2 * pi / len * mode), sinl(2 * pi / len * mode)};
			for (int i = 0; i < N; i += len) {
				point now = (point) {1, 0};
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					point tmp = a[j];
					point tnp = a[k] * now;
					a[j] = tmp + tnp;
					a[k] = tmp - tnp;
					now = now * delta;
				}
			}
		}
		if (mode == -1) {
			for (int i = 0; i < N; i++)
				a[i] = a[i] / N;
		}
	}
	void times(int *a, int *b, int *c, int P, int limit) {
		N = 1, Log = 0;
		while (N <= 2 * limit) {
			N <<= 1;
			Log++;
		}
		static point ax[MAXN], ay[MAXN];
		static point bx[MAXN], by[MAXN];
		for (int i = 0; i <= limit; i++) {
			ax[i] = (point) {a[i] & 32767, 0};
			ay[i] = (point) {a[i] >> 15, 0};
			bx[i] = (point) {b[i] & 32767, 0};
			by[i] = (point) {b[i] >> 15, 0};
		}
		for (int i = limit + 1; i < N; i++) {
			ax[i] = (point) {0, 0};
			ay[i] = (point) {0, 0};
			bx[i] = (point) {0, 0};
			by[i] = (point) {0, 0};
		}
		FFTinit();
		FFT(ax, 1), FFT(ay, 1), FFT(bx, 1), FFT(by, 1);
		static point x[MAXN], y[MAXN], z[MAXN];
		for (int i = 0; i < N; i++) {
			x[i] = ax[i] * bx[i];
			y[i] = ax[i] * by[i] + ay[i] * bx[i];
			z[i] = ay[i] * by[i];
		}
		FFT(x, -1), FFT(y, -1), FFT(z, -1);
		auto num = [&] (point x) {
			return (long long) (x.x + 0.5) % P;
		};
		for (int i = 0; i < N; i++) {
			int res = num(z[i]);
			res = (32768ll * res + num(y[i])) % P;
			res = (32768ll * res + num(x[i])) % P;
			c[i] = res;
		}
	}
}
ll n; int k;
int dp[MAXLOG][MAXN];
int fac[MAXN], inv[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1ll) % P;
}
int main() {
	read(n), read(k);
	if (n > k) {
		puts("0");
		return 0;
	}
	init(k);
	for (int i = 1; i <= k; i++)
		dp[0][i] = inv[i];
	for (int p = 1; p < MAXLOG; p++) {
		static int a[MAXN], b[MAXN], c[MAXN];
		for (int i = 0; i <= k; i++) {
			a[i] = 1ll * dp[p - 1][i] * power(2, i * (1 << (p - 1))) % P;
			b[i] = dp[p - 1][i];
		}
		AnyModuloFFT :: times(a, b, c, P, k);
		for (int i = 0; i <= k; i++)
			dp[p][i] = c[i];
	}
	static int curr[MAXN]; curr[0] = 1;
	for (int p = MAXLOG - 1; p >= 0; p--) {
		if ((n & (1 << p)) == 0) continue;
		static int a[MAXN], b[MAXN], c[MAXN];
		for (int i = 0; i <= k; i++) {
			a[i] = 1ll * curr[i] * power(2, i * (1 << p)) % P;
			b[i] = dp[p][i];
		}
		AnyModuloFFT :: times(a, b, c, P, k);
		for (int i = 0; i <= k; i++)
			curr[i] = c[i];
	}
	int ans = 0;
	for (int i = n; i <= k; i++)
		ans = (ans + 1ll * curr[i] * inv[k - i]) % P;
	writeln(1ll * ans * fac[k] % P);
	return 0;
}