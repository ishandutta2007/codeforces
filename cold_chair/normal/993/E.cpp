#include<cmath>
#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define ff(i, x, y) for(int i = x; i < y; i ++)
#define ld long double
using namespace std;

const int N = 8e5 + 5;

const ld pi = acos(-1);

struct Z {
	ld x, y;
	Z (ld _x = 0, ld _y = 0) {x = _x, y = _y;}
};

Z operator +(Z a, Z b) {return Z(a.x + b.x, a.y + b.y);}
Z operator -(Z a, Z b) {return Z(a.x - b.x, a.y - b.y);}
Z operator *(Z a, Z b) {return Z(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}

int n, tp;
Z w[N], a[N], b[N];

void dft(Z *a, int n) {
	ff(i, 0, n) {
		int p = i, q = 0;
		fo(j, 1, tp) q = q * 2 + p % 2, p /= 2;
		if(q > i) swap(a[i], a[q]);
	}
	for(int m = 2; m <= n; m *= 2) {
		int h = m / 2;
		ff(i, 0, h) {
			Z W = w[i * (n / m)];
			for(int j = i; j < n; j += m) {
				int k = j + h;
				Z u = a[j], v = a[k] * W;
				a[j] = u + v; a[k] = u - v;
			}
		}
	}
}

void fft(Z *a, Z *b, int n) {
	w[0] = Z(1, 0); Z u = Z(cos(2 * pi / n), sin(2 * pi / n));
	fo(i, 1, n) w[i] = w[i - 1] * u;
	dft(a, n); dft(b, n);
	ff(i, 0, n) a[i] = a[i] * b[i];
	fo(i, 0, n / 2) swap(w[i], w[n - i]);
	dft(a, n);
	ff(i, 0, n) a[i].x /= n;
}

int x, y, n0, c[N];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &x);
	long long ans = 0, o = 0;
	fo(i, 1, n) {
		scanf("%d", &c[i]);
		if(c[i] < x) {
			ans += o * (o + 1) / 2;
			o = 0;
		} else o ++;
		c[i] = (c[i] < x) + c[i - 1];
	}
	
	fo(i, 0, n) {
		a[c[i]].x ++;
		b[n - c[i]].x ++;
	}
	
	n0 = n; n = n * 2; while(1 << ++ tp <= n); n = 1 << tp;
	
	fft(a, b, n);
	
	printf("%I64d ", ans + o * (o + 1) / 2);
	fo(i, n0 + 1, n0 * 2) printf("%I64d ", (long long) (a[i].x + 1e-1));
}