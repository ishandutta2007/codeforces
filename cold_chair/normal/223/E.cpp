#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

#define db double

int n, m, x, y;

vector<int> e[N];
#define pb push_back
#define si size()

struct P {
	db x, y;
	P(db _x = 0, db _y = 0) {
		x = _x, y = _y;
	}	
} a[N];

P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y);}
P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y);}
db operator ^ (P a, P b) { return a.x * b.y - a.y * b.x;}
db operator * (P a, P b) { return a.x * b.x + a.y * b.y;}
P operator * (P a, db b) { return P(a.x * b, a.y * b);}

int fa[N], bz[N], siz[N];

db ang(P a, P b) {
	return atan2(b.y - a.y, b.x - a.x);
}

vector<P> s[N];

int cmpe(P a, P b) {
	return a.x < b.x;
}

int d[N], d0;

void dg(int x) {
	d[d0 = 1] = x; bz[x] = 1;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		ff(_y, 0, e[x].si) {
			int y = e[x][_y];
			if(bz[y]) continue;
			fa[y] = x;
			bz[y] = 1;
			d[++ d0] = y;
		}
	}
	fd(i, d0, 1) {
		int x = d[i];
		siz[x] = 1;
		ff(_y, 0, e[x].si) {
			int y = e[x][_y];
			if(fa[y] != x) continue;
			siz[x] += siz[y];
			s[x].pb(P(ang(a[x], a[y]), -siz[y]));
		}
		if(fa[x] <= n) {
			s[x].pb(P(ang(a[x], a[fa[x]]), siz[x]));
		}
		if(s[x].si) {
			sort(s[x].begin(), s[x].end(), cmpe);
			ff(j, 1, s[x].si) s[x][j].y += s[x][j - 1].y;
		}
	}
}

void build() {
	int t = 1;
	fo(i, 2, n) if(a[i].x < a[t].x) t = i;
	e[n + 1].pb(t); e[t].pb(n + 1);
	dg(n + 1);
}

int Q, k;
P b[N]; int c[N];

void check_order() {
	db s = 0;
	fo(i, 2, k - 1) s += (b[i] - b[1]) ^ (b[i + 1] - b[1]);
	if(s < 0) {
		reverse(b + 1, b + k + 1);
		reverse(c + 1, c + k + 1);
	}
}

const db pi = acos(-1);

const db eps = 1e-11;

ll ef(vector<P> &s, db p) {
	int as = -1;
	for(int l = 0, r = s.si - 1; l <= r; ) {
		int m = l + r >> 1;
		if(s[m].x <= p) as = m, l = m + 1; else r = m - 1;
	}
	if(as == -1) return 0;
	return s[as].y;
}

ll solve(int x, db p, db q) {
	ll ans = 0;
	if(fa[x] > n) ans += siz[x];
	if(s[x].si == 0) return ans;
	if(p <= q) ans += ef(s[x], p - eps) + (s[x][s[x].si - 1].y - ef(s[x], q + eps)); else
		ans += ef(s[x], p - eps) - ef(s[x], q + eps);
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		e[x].pb(y); e[y].pb(x);
	}
	fo(i, 1, n) scanf("%lf %lf", &a[i].x, &a[i].y);
	build();
	scanf("%d", &Q);
	fo(ii, 1, Q) {
		scanf("%d", &k);
		fo(i, 1, k) {
			scanf("%d", &c[i]);
			b[i] = a[c[i]];
		}
		check_order();
		ll ans = 0;
		fo(i, 1, k) {
			ans += solve(c[i], ang(b[i], i == k ? b[1] : b[i + 1]), ang(b[i], i == 1 ? b[k] : b[i - 1]));
		}
		pp("%lld\n", ans);
	}
}