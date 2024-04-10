#include<set>
#include<cstdio>
#include<algorithm>
#define pp printf
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e5 + 5;

int n, Q, a[N], op, x, y, d[N];
ll b[N], c[N];

struct lian {
	int l[N], r[N], fi[N];
	void add(int x, int y) {
		l[y] = 0; r[y] = fi[x];
		l[fi[x]] = y;
		fi[x] = y;
	}
	void del(int x, int y) {
		if(y == fi[x]) fi[x] = r[y];
		r[l[y]] = r[y]; l[r[y]] = l[y];
		l[y] = r[y] = 0;
	}
} ss, dd;

const int M = 100;

multiset<ll> s[N], g;

void cj(int x) {
	dd.add(1, x);
	for(int y = ss.fi[x]; y; y = ss.r[y]) {
		g.erase(g.find(c[y]));
		c[y] -= b[x] / d[x];
		s[x].insert(c[y]);
	}
}

void sf(int x) {
	dd.del(1, x);
	s[x].clear();
	for(int y = ss.fi[x]; y; y = ss.r[y]) {
		c[y] += b[x] / d[x];
		g.insert(c[y]);
	}
}

void build() {
	fo(i, 1, n) d[i] = 2;
	fo(i, 1, n) d[a[i]] ++;
	fo(i, 1, n) c[i] = b[i] % d[i] + b[i] / d[i] + b[a[i]] / d[a[i]];
	fo(i, 1, n) c[a[i]] += b[i] / d[i];
	fo(i, 1, n) ss.add(a[i], i);
	fo(i, 1, n) g.insert(c[i]);
	fo(i, 1, n) if(d[i] > M) cj(i);
}

void xiu(int x, ll y) {
	if(d[a[x]] > M) {
		s[a[x]].erase(s[a[x]].find(c[x]));
		c[x] += y;
		s[a[x]].insert(c[x]);
	} else {
		g.erase(g.find(c[x]));
		c[x] += y;
		g.insert(c[x]);
	}
}
void gg(int x, int y) {	
	ll v = b[x] / (d[x] + y) - b[x] / d[x];
	if(v != 0) xiu(a[x], v);
	v = b[x] / d[x] + b[x] % d[x];
	d[x] += y;
	v = b[x] / d[x] + b[x] % d[x] - v;
	xiu(x, v);
}

ll fv(int x) {
	return d[a[x]] > M ? c[x] + b[a[x]] / d[a[x]] : c[x];
}

int main() {
	scanf("%d %d", &n, &Q);
	fo(i, 1, n) scanf("%lld", &b[i]);
	fo(i, 1, n) scanf("%d", &a[i]);
	build();
	fo(ii, 1, Q) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d %d", &x, &y);
			
			swap(a[x], y);
			
			if(d[y] > M) {
				s[y].erase(s[y].find(c[x]));
			} else {
				g.erase(g.find(c[x]));
				c[x] -= b[y] / d[y];
			}
			ss.del(y, x); xiu(y, -b[x] / d[x]);
			
			ll v = b[y] / (d[y] - 1) - b[y] / d[y];
			gg(y, -1);
			if(d[y] == M) {
				sf(y);
			} else
			if(d[y] < M) {
				for(int i = ss.fi[y]; i; i = ss.r[i])
					xiu(i, v);
			}
			
			y = a[x];
			if(d[y] > M) {
				s[y].insert(c[x]);
			} else {
				c[x] += b[y] / (d[y] + 1);
				g.insert(c[x]);
			}
			xiu(y, b[x] / d[x]);
			v = b[y] / (d[y] + 1) - b[y] / d[y];
			gg(y, 1);
			
			if(d[y] <= M + 1) {
				d[y] --;
				for(int i = ss.fi[y]; i; i = ss.r[i])
					 xiu(i, v);
				d[y] ++;
			}
			ss.add(y, x);
			if(d[y] == M + 1) {
				cj(y);
			}
		} else
		if(op == 2) {
			scanf("%d", &x);
			printf("%lld\n", fv(x));
		} else {
			ll mi = 1e18, mx = 0;
			for(x = dd.fi[1]; x; x = dd.r[x]) {
				ll z = b[x] / d[x];
				mi = min(mi, (*s[x].begin()) + z);
				mx = max(mx, (*s[x].rbegin()) + z);
			}
			if(g.size()) {
				mi = min(mi, *g.begin());
				mx = max(mx, *g.rbegin());
			}
			printf("%lld %lld\n", mi, mx);
		}
	}
}