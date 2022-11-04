#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int k, n, m;
int a[N];

struct nod {
	int ty, x, y;
} b[N];

vector<int> e[N][3];
#define pb push_back
#define si size()
#define re resize

int cmp(int x, int y) {
	return b[x].y > b[y].y;
}

struct P {
	ll x, y;
	P(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

bool operator < (P a, P b) {
	if(a.y == 0) return 0;
	if(b.y == 0) return 1;
	return (long double) a.x / a.y < (long double) b.x / b.y;
}

P c[N]; int d[N], d0;

int cmpd(int x, int y) {
	return c[y] < c[x];
}

int cmd2(int x, int y) {
	return b[x].ty < b[y].ty;
}

int main() {
	scanf("%d %d %d", &k, &n, &m);
	fo(i, 1, k) scanf("%d", &a[i]);
	fo(i, 1, n) {
		scanf("%d %d %d", &b[i].ty, &b[i].x, &b[i].y);
		b[i].ty --;
		e[b[i].x][b[i].ty].pb(i);
	}
	fo(i, 1, k) {
#define t0 e[i][0]
#define t1 e[i][1]
#define t2 e[i][2]
		fo(j, 0, 2) sort(e[i][j].begin(), e[i][j].end(), cmp);
		if(t0.si && b[t0[0]].y > a[i]) b[t0[0]].y -= a[i], t1.pb(t0[0]);
		sort(t1.begin(), t1.end(), cmp);
		int n1 = t1.si, n2 = t2.si;
		int l = 0, r = 0; ll s1 = a[i];
		fo(j, 1, n1 + n2) {
			ll s2 = l == n1 ? 0 : s1 + b[t1[l]].y;
			ll v = r == n2 ? 0 : b[t2[r]].y;
			if(l == n1 || (r < n2 && P(s2, s1) < P(v, 1))) {
				c[t2[r]] = P(v, 1);
				d[++ d0] = t2[r];
				r ++;
				continue;
			}
			c[t1[l]] = P(s2, s1);
			d[++ d0] = t1[l];
			l ++; s1 = s2;
		}
	}
	sort(d + 1, d + d0 + 1, cmpd);
	m = min(d0, m);
	sort(d + 1, d + m + 1, cmd2);
	pp("%d\n", m);
	fo(i, 1, m) pp("%d ", d[i]);
}