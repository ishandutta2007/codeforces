#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ld long double
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define ff(i, x, y) for(int i = x; i < y; i ++)
using namespace std;

const ld pi = acos(-1);

const int N = 1500005;

struct Z {
	ld x, y;
	Z (ld _x = 0, ld _y = 0) {x = _x, y = _y;}
};

Z operator +(Z a, Z b) {return Z(a.x + b.x, a.y + b.y);}
Z operator -(Z a, Z b) {return Z(a.x - b.x, a.y - b.y);}
Z operator *(Z a, Z b) {return Z(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}
Z w[N]; int tp;
void dft(Z *a, int n) {
	ff(i, 0, n) {
		int p = 0, q = i;
		fo(j, 1, tp) p = p * 2 + q % 2, q /= 2;
		if(p > i) swap(a[p], a[i]);
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
	fo(i, 0, n) w[i] = Z(cos(2 * pi * i / n), sin(2 * pi * i / n));
	dft(a, n); dft(b, n);
	ff(i, 0, n) a[i] = a[i] * b[i];
	fo(i, 0, n / 2) swap(w[i], w[n - i]);
	dft(a, n); ff(i, 0, n) a[i].x /= n;
}
void sqr(Z *a, int n) {
	fo(i, 0, n) w[i] = Z(cos(2 * pi * i / n), sin(2 * pi * i / n));
	dft(a, n);
	ff(i, 0, n) a[i] = a[i] * a[i];
	fo(i, 0, n / 2) swap(w[i], w[n - i]);
	dft(a, n); ff(i, 0, n) a[i].x /= n;
}
void jing(Z *a, int &n) {
	ff(i, 0, n) {
		ll o = a[i].x + 0.5;
		a[i + 1].x += o / 10000;
		a[i].x = o % 10000;
	}
	if(a[n].x > 0.5) n ++;
	ff(i, 0, n) a[i].y = 0, a[i].x = (ll) (a[i].x + 0.5);
}

char s[N]; int len, num[N];

int n, m, t, n0; Z a[N], b[N], c[N], d[N];

int pd(Z *a, Z *b, int n, int m) {
	if(n > m) return 1;
	if(n < m) return 0;
	fd(i, n - 1, 0) {
		int x = a[i].x + 0.5, y = b[i].x + 0.5;
		if(x > y) return 1;
		if(x < y) return 0;
	}
	return 2;
}

int main() {
	
//	freopen("d.in", "r", stdin);
	scanf("%s", s + 1); len = strlen(s + 1);
	fo(i, 1, len / 2) swap(s[i], s[len - i + 1]);
	fo(i, 5, len) num[i] = num[i - 1] + (i % 4 == 1);
	n = num[len] + 1; fd(i, len, 1) a[num[i]] = a[num[i]] * 10 + s[i] - '0';
	
	if(n == 1) {
		int x = a[0].x + 0.5;
		if(x == 1) {printf("1\n"); return 0;}
		if(x == 2) {printf("2\n"); return 0;}
		if(x == 3) {printf("3\n"); return 0;}
		if(x == 4) {printf("4\n"); return 0;}
	}
	
	int y = log(10) / log(3) * (len - 1), y0 = y;
	
	m = 1; b[0] = 3;
	t = 1; d[0] = 1;
	
	for(; y; y /= 2) {
		if(y & 1) {
			n0 = t + m - 1;
			tp = 0; while(1 << ++ tp < n0);
			n0 = 1 << tp;
			ff(i, t, n0) d[i] = (0, 0);
			ff(i, m, n0) b[i] = (0, 0);
			ff(i, 0, n0) c[i] = b[i];
			fft(d, c, n0);
			t = t + m - 1; jing(d, t);
		}
		n0 = m + m - 1;
		ff(i, m, n0) b[i] = (0, 0);
		tp = 0; while(1 << ++ tp < n0);
		n0 = 1 << tp; sqr(b, n0);
		m = m + m - 1; jing(b, m);
	}
	
	memset(c, 0, sizeof c);
	while(1) {
		ff(i, 0, t)	c[i] = d[i];
		
		m = t;
		ff(i, 0, m) c[i].x *= 3;
		jing(c, m);
		
		int pp = pd(c, a, m, n);

		if(pp == 0) {
			ff(i, 0, m)	d[i] = c[i];
			t = m;
			y0 ++;
			continue;
		}
		break;
	}
	
	ff(i, 0, t) c[i] = d[i]; ff(i, t, 1e6) c[i] = 0;
	int yu = 0; m = t;
	fd(i, m - 1, 0) {
		c[i].x += yu * 10000;
		yu = (int) (c[i].x + 0.5) % 3;
		c[i].x = (int) (c[i].x + 0.5) / 3;
	}
	ff(i, 0, m) c[i].x *= 4; jing(c, m);
	if(pd(c, a, m, n)) {
		printf("%d\n", y0 * 3 + 1);
		return 0;
	}
	
	
	ff(i, 0, t) c[i] = d[i]; ff(i, t, 1e6) c[i] = 0;
	m = t;
	ff(i, 0, m) c[i].x *= 2;
	jing(c, m);
	if(pd(c, a, m, n)) {
		printf("%d\n", y0 * 3 + 2);
		return 0;
	}
	
	printf("%d\n", (y0 + 1) * 3);

}