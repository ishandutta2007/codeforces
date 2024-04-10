#include<bits/stdc++.h>
using namespace std;
const int MAXN = 524288;
const int REAL = 200005;
const int SIZE = 7200;
const int MAXK = 205;
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
namespace FFT {
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
				a[i] = a[i] / (4 * N);
		}
	}
	void times(double *a, double *b, double *c, int limit) {
		N = 1, Log = 0;
		while (N <= 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = 0; i < limit; i++)
			tmp[i] = (point) {a[i] + b[i], a[i] - b[i]};
		for (int i = limit; i < N; i++)
			tmp[i] = (point) {0, 0};
		FFTinit();
		FFT(tmp, 1);
		for (int i = 0; i < N; i++)
			tmp[i] = tmp[i] * tmp[i];
		FFT(tmp, -1);
		for (int i = 0; i < N; i++)
			c[i] = tmp[i].x;
	}
	void times(int *a, int *b, int *c, int limit) {
		N = 1, Log = 0;
		while (N <= 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = 0; i < limit; i++)
			tmp[i] = (point) {(double) (a[i] + b[i]), (double) (a[i] - b[i])};
		for (int i = limit; i < N; i++)
			tmp[i] = (point) {0, 0};
		FFTinit();
		FFT(tmp, 1);
		for (int i = 0; i < N; i++)
			tmp[i] = tmp[i] * tmp[i];
		FFT(tmp, -1);
		for (int i = 0; i < N; i++)
			c[i] = (int) (tmp[i].x + 0.5);
	}
	void times(long long *a, long long *b, long long *c, int limit) {
		N = 1, Log = 0;
		while (N <= 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = 0; i < limit; i++)
			tmp[i] = (point) {(double) (a[i] + b[i]), (double) (a[i] - b[i])};
		for (int i = limit; i < N; i++)
			tmp[i] = (point) {0, 0};
		FFTinit();
		FFT(tmp, 1);
		for (int i = 0; i < N; i++)
			tmp[i] = tmp[i] * tmp[i];
		FFT(tmp, -1);
		for (int i = 0; i < N; i++)
			c[i] = (long long) (tmp[i].x + 0.5);
	}
}
int ls, lt, tot;
char s[MAXN], t[MAXN];
int ans[MAXK][REAL];
int a[MAXN], b[MAXN], c[MAXN];
int index[MAXN], l[MAXN], r[MAXN];
int query(int ps, int pt) {
	int tans = 0;
	if (ps + SIZE >= ls || pt + SIZE >= lt) {
		while (ps < ls && pt < lt) tans += s[ps++] == t[pt++];
		return tans;
	}
	while (index[pt] == index[pt - 1]) tans += s[ps++] == t[pt++];
	tans += ans[index[pt]][ps];
	return tans;
}
int main() {
	scanf("\n%s\n%s", s, t);
	ls = strlen(s);
	lt = strlen(t);
	for (int i = 0; i < lt; i++) {
		if (i % SIZE == 0) l[++tot] = i;
		index[i] = tot; r[tot] = i;
	}
	for (int p = 1; p <= tot; p++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < ls; i++)
			if (s[i] == '0') a[i] = 1;
			else a[i] = -1;
		for (int i = l[p]; i < lt; i++)
			if (t[i] == '0') b[lt - 1 - i] = 1;
			else b[lt - 1 - i] = -1;
		int len = lt - l[p] - 1;
		int limit = max(ls, lt - l[p]);
		FFT::times(a, b, c, limit);
		for (int i = 0; i < ls; i++)
			ans[p][i] += (c[i + len] + len + 1 - max(0, i + len - ls + 1)) / 2;
	}
	int q; read(q);
	while (q--) {
		int ps, pt, len;
		read(ps), read(pt), read(len);
		writeln(len - query(ps, pt) + query(ps + len, pt + len));
	}
	return 0;
}