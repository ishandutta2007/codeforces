#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4194304;
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
	const int MAXN = 4194304;
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
	void times(int *a, int *b, int *c, int limit) {
		N = 1, Log = 0;
		while (N < 2 * limit) {
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
	void getmul(int *a, int &lena, int p) {
		a[0] = 1;
		static int b[MAXN]; b[0] = 3;
		lena = 1; int lenb = 1;
		while (p != 0) {
			if (p & 1) {
				times(a, b, a, max(lena, lenb));
				lena += lenb + 15;
				for (int i = 0; i < lena; i++) {
					a[i + 1] += a[i] / 10;
					a[i] %= 10;
				}
				while (a[lena - 1] == 0) lena--;
			}
			p >>= 1;
			times(b, b, b, lenb);
			lenb += lenb + 15;
			for (int i = 0; i < lenb; i++) {
				b[i + 1] += b[i] / 10;
				b[i] %= 10;
			}
			while (b[lenb - 1] == 0) lenb--;
		}
	}
}
char s[MAXN]; int l;
int a[MAXN], lena, ansa;
int b[MAXN], lenb, ansb;
int c[MAXN], lenc, ansc;
void multiply(int *a, int &len, int &ans, int val) {
	ans += val;
	for (int i = 0; i < len; i++)
		a[i] *= val;
	for (int i = 0; i < len; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[len] != 0) len++;
}
bool Greater(int *a, int len) {
	if (len > l) return true;
	if (len < l) return false;
	for (int i = len - 1; i >= 0; i--) {
		if (a[i] > s[i] - '0') return true;
		if (a[i] < s[i] - '0') return false;
	}
	return true;
}
int main() {
	scanf("%s", s);
	l = strlen(s);
	reverse(s, s + l);
	if (l == 1 && s[0] == '1') {
		printf("1\n");
		return 0;
	}
	int p = max(l / log10(3) - 4, 0.0);
	FFT::getmul(a, lena, p);
	memcpy(b, a, sizeof(b));
	memcpy(c, a, sizeof(c));
	lenb = lenc = lena;
	ansa = ansb = ansc = p * 3;
	while (!Greater(a, lena)) multiply(a, lena, ansa, 3);
	multiply(b, lenb, ansb, 2);
	while (!Greater(b, lenb)) multiply(b, lenb, ansb, 3);
	multiply(c, lenc, ansc, 2); multiply(c, lenc, ansc, 2);
	while (!Greater(c, lenc)) multiply(c, lenc, ansc, 3);
	printf("%d\n", min(min(ansa, ansb), ansc));
	return 0;
}