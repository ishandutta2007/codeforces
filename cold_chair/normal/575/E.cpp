#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define db double

const db eps = 1e-8;

struct P {
	db x, y;
	P(db _x = 0, db _y = 0) {
		x = _x, y = _y;
	}
};

P operator + (P a, P b) {
	return P(a.x + b.x, a.y + b.y);
}

P operator - (P a, P b) {
	return P(a.x - b.x, a.y - b.y);
}

P operator * (P a, db b) {
	return P(a.x * b, a.y * b);
}

P operator * (P a, P b) {
	return a.x * b.x + a.y * b.y;
}

db operator ^(P a, P b) {
	return a.x * b.y - a.y * b.x;
}

db lenf(P a) {
	return a.x * a.x + a.y * a.y;
}

db len(P a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

struct L {
	P p, v;
};

P is(L a, L b) {
	return b.p + b.v * ((a.v ^ (a.p - b.p)) / (a.v ^ b.v));
}

int pd(P a, L b) {
	db x = b.p.x, y = x + b.v.x;
	if(x > y) swap(x, y);
	if(a.x < x - eps || a.x > y + eps) return 0;
	x = b.p.y, y = x + b.v.y;
	if(x > y) swap(x, y);
	return a.y >= x - eps && a.y <= y + eps;
}

const int N = 1e5 + 5;

int n;
P a[N]; db vi[N];

P mov[4] = {
	P(-1, 0), P(0, 1), P(1, 0), P(0, -1)
};

P d[4], d2[4];
L u[4], v[4];

P p[N * 16], lp[N * 16]; int p0;

bool operator < (P a, P b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int us[N * 16], z[N * 16], z0;
void build_tb() {
	sort(p + 1, p + p0 + 1);
	z[z0 = 1] = 1;
	fo(i, 2, p0) {
		while(z0 > 1 && ((p[i] - p[z[z0]]) ^ (p[z[z0]] - p[z[z0 - 1]])) <= eps) us[z[z0 --]] = 0;
		us[z[++ z0] = i] = 1;
	}
	int zm = z0;
	fd(i, p0 - 1, 1) if(!us[i]) {
		while(z0 > zm && ((p[i] - p[z[z0]]) ^ (p[z[z0]] - p[z[z0 - 1]])) <= eps) us[z[z0 --]] = 0;
		us[z[++ z0] = i] = 1;
	}
	z0 --;
	fo(i, 1, p0) lp[i] = p[i];
	p0 = z0;
	fo(i, 1, p0) p[i] = lp[z[i]];
}

db mdis(P a, P b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	scanf("%d", &n);
	d[0] = P(0, 0); d[1] = P(0, 1e5); d[2] = P(1e5, 1e5); d[3] = P(1e5, 0);
	fo(i, 0, 3) {
		d2[i] = d[i];
		u[i].p = d[i];
		u[i].v = d[(i + 1) % 4] - d[i];
	}
	fo(i, 1, n) {
		scanf("%lf %lf %lf", &a[i].x, &a[i].y, &vi[i]);
		fo(j, 0, 3) {
			if(mdis(d2[j], a[i]) <= vi[i] + eps) {
				p[++ p0] = d2[j];
			}
			d[j] = a[i] + mov[j] * vi[i];
			if(d[j].x >= 0 && d[j].x <= 1e5 && d[j].y >= 0 && d[j].y <= 1e5) {
				p[++ p0] = d[j];
			}
		}
		if(vi[i] != 0) {
			fo(j, 0, 3) {
				v[j].p = d[j];
				v[j].v = d[(j + 1) % 4] - d[j];
				fo(k, 0, 3) {
					P t = is(v[j], u[k]);
					if(pd(t, v[j]) && pd(t, u[k])) {
						//if(t.y < -eps) printf("SB\n");
						p[++ p0] = t;
					}
				}
			}
		}
	}
	build_tb();
	//fo(i, 1, p0) pp("p = %lf %.9lf\n", p[i].x, p[i].y);
	P a1, a2, a3; db ans = 0;
	fo(i, 1, p0) {
		P d1 = p[i], d2 = p[i % p0 + 1], d3 = p[(i + 1) % p0 + 1];
		P t1 = d2 - d1, t2 = d3 - d2, t3 = d1 - d3;
		if(abs(t1 ^ t2) < eps) swap(t1, t3);
		if(abs(t1 ^ t2) < eps) swap(t2, t3);
		db r = len(t1) * len(t2) * len(t3) / 2 / abs(t1 ^ t2);
		if(r > ans) {
			ans = r;
			a1 = d1, a2 = d2, a3 = d3;
		}
	}
	pp("%.0lf %.0lf\n", a1.x, a1.y);
	pp("%.0lf %.0lf\n", a2.x, a2.y);
	pp("%.0lf %.0lf\n", a3.x, a3.y);
}