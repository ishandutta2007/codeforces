#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
	const double pi = acos(-1);
	struct point {double x, y; };
	point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
	point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
	point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
	point operator / (point a, double x) {return (point) {a.x / x, a.y / x}; }
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
			point delta = (point) {cos(2 * pi / len * mode), sin(2 * pi / len * mode)};
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
			ax[i] = (point) {a[i] & 511, 0};
			ay[i] = (point) {a[i] >> 9, 0};
			bx[i] = (point) {b[i] & 511, 0};
			by[i] = (point) {b[i] >> 9, 0};
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
			res = (512ll * res + num(y[i])) % P;
			res = (512ll * res + num(x[i])) % P;
			c[i] = res;
		}
	}
}
int n, m, ans, P, odd[MAXN], even[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void work(int m) {
	if (m == 1) {
		odd[1] = 1;
		update(ans, 1);
		return;
	}
	work(m / 2);
	static int reso[MAXN], rese[MAXN], a[MAXN], b[MAXN];
	memset(reso, 0, sizeof(reso));
	memset(rese, 0, sizeof(rese));
	
	memset(a, 0, sizeof(a)), a[0] = 1;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++) {
		a[i] = (odd[i] + even[i]) % P;
		if (m / 2 % 2) b[i] = even[i];
		else b[i] = odd[i];
	}
	AnyModuloFFT :: times(a, b, reso, P, n);
	for (int i = 1; i <= n; i++)
		update(reso[i], odd[i]);
	for (int i = n + 1; i <= 2 * n; i++)
		reso[i] = 0;
	
	memset(a, 0, sizeof(a)), a[0] = 1;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++) {
		a[i] = (odd[i] + even[i]) % P;
		if (m / 2 % 2) b[i] = odd[i];
		else b[i] = even[i];
	}
	AnyModuloFFT :: times(a, b, rese, P, n);
	for (int i = 1; i <= n; i++)
		update(rese[i], even[i]);
	for (int i = n + 1; i <= 2 * n; i++)
		even[i] = 0;
	
	if (m % 2 == 1) {
		for (int i = n; i >= 2; i--)
			update(reso[i], (reso[i - 1] + rese[i - 1]) % P);
		update(reso[1], 1);
	}
	memcpy(odd, reso, sizeof(reso));
	memcpy(even, rese, sizeof(rese));
	for (int i = 1; i <= n; i += 2)
		update(ans, odd[i]);
}
int main() {
	read(n), read(m), read(P);
	if (m != 1) work(m / 2);
	writeln(ans);
	return 0;
}