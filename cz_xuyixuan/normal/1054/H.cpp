#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 490019;
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
int power(int x, int y, int p) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2, p);
	if (y % 2 == 0) return 1ll * tmp * tmp % p;
	else return 1ll * tmp * tmp % p * x % p;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
struct point {long double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
point operator / (point a, long double x) {return (point) {a.x / x, a.y / x}; }
namespace FFT {
	const int MAXN = 1024;
	const long double pi = acos(-1);
	int N, Log, home[MAXN];
	void FFTinit() {
		N = 1024, Log = 10;
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
}
int n, m, v, val[MAXN], vbl[MAXN];
bool flga[MAXN], flgb[MAXN]; int merg[2][1024][1024];
int a[2][1024][1024], b[2][1024][1024]; int c[P];
int p491[1024], p499[1024], log491[1024], log499[1024];
void multiply() {
	FFT :: FFTinit();
	static point res[2][1024][1024], tmp[1024], tnp[1024];
	static point ta[2][1024][1024], tb[2][1024][1024];
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1023; j++) {
		for (int k = 0; k <= 1023; k++) {
			tmp[k] = (point) {(double) a[i][j][k], 0};
			tnp[k] = (point) {(double) b[i][j][k], 0};
		}
		FFT :: FFT(tmp, 1);
		FFT :: FFT(tnp, 1);
		for (int k = 0; k <= 1023; k++) {
			ta[i][j][k] = tmp[k];
			tb[i][j][k] = tnp[k];
		}
	}
	for (int i = 0; i <= 1; i++)
	for (int k = 0; k <= 1023; k++) {
		for (int j = 0; j <= 1023; j++) {
			tmp[j] = ta[i][j][k];
			tnp[j] = tb[i][j][k];
		}
		FFT :: FFT(tmp, 1);
		FFT :: FFT(tnp, 1);
		for (int j = 0; j <= 1023; j++) {
			ta[i][j][k] = tmp[j];
			tb[i][j][k] = tnp[j];
		}
	}
	for (int i = 0; i <= 1023; i++)
	for (int j = 0; j <= 1023; j++) {
		ta[0][i][j] = ta[0][i][j] + ta[1][i][j];
		tb[0][i][j] = tb[0][i][j] + tb[1][i][j];
		res[0][i][j] = ta[0][i][j] * tb[0][i][j];
		res[1][i][j] = ta[1][i][j] * tb[1][i][j];
	}
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1023; j++) {
		for (int k = 0; k <= 1023; k++)
			tmp[k] = res[i][j][k];
		FFT :: FFT(tmp, -1);
		for (int k = 0; k <= 1023; k++)
			res[i][j][k] = tmp[k];
	}
	for (int i = 0; i <= 1; i++)
	for (int k = 0; k <= 1023; k++) {
		for (int j = 0; j <= 1023; j++)
			tmp[j] = res[i][j][k];
		FFT :: FFT(tmp, -1);
		for (int j = 0; j <= 1023; j++)
			res[i][j][k] = tmp[j];
	}
	for (int i = 0; i <= 1023; i++)
	for (int j = 0; j <= 1023; j++) {
		res[0][i][j] = res[0][i][j] - res[1][i][j];
		update(c[merg[0][p491[i]][p499[j]]], (ll) (res[0][i][j].x + 0.5) % P);
		update(c[merg[1][p491[i]][p499[j]]], (ll) (res[1][i][j].x + 0.5) % P);
	}
}
int main() {
	read(n), read(m), read(v);
	for (int i = 0, ta = 1, tb = 1; i <= 1023; i++, ta = ta * 2 % 491, tb = tb * 7 % 499) {
		p491[i] = ta, p499[i] = tb;
		if (i <= 491 - 2) log491[ta] = i;
		if (i <= 499 - 2) log499[tb] = i;
	}
	for (int i = 0; i <= P - 1; i++) {
		assert(merg[i % 2][i % 491][i % 499] == 0);
		merg[i % 2][i % 491][i % 499] = i;
	}
	for (int i = 0; i <= n - 1; i++) {
		read(val[i]);
		int tmp = 1ll * i * i % (P - 1);
		if (tmp % 491 && tmp % 499) update(a[tmp & 1][log491[tmp % 491]][log499[tmp % 499]], val[i]);
		else flga[i] = true;
	}
	for (int i = 0; i <= m - 1; i++) {
		read(vbl[i]);
		int tmp = 1ll * i * i * i % (P - 1);
		if (tmp % 491 && tmp % 499) update(b[tmp & 1][log491[tmp % 491]][log499[tmp % 499]], vbl[i]);
		else flgb[i] = true;
	}
	multiply();
	for (int i = 0; i <= n - 1; i++) {
		if (!flga[i]) continue;
		for (int j = 0; j <= m - 1; j++) {
			int tmp = 1ll * i * i % (P - 1) * j % (P - 1) * j % (P - 1) * j % (P - 1);
			update(c[tmp], 1ll * val[i] * vbl[j] % P);
		}
	}
	for (int j = 0; j <= m - 1; j++) {
		if (!flgb[j]) continue;
		for (int i = 0; i <= n - 1; i++) {
			if (flga[i]) continue;
			int tmp = 1ll * i * i % (P - 1) * j % (P - 1) * j % (P - 1) * j % (P - 1);
			update(c[tmp], 1ll * val[i] * vbl[j] % P);
		}
	}
	int ans = 0;
	for (int i = 0; i <= P - 1; i++)
		update(ans, 1ll * c[i] * power(v, i, P) % P);
	writeln(ans);
	return 0;
}