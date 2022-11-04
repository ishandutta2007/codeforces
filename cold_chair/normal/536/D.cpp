#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2005, M = 2e5 + 5;

int n, m, S, T;
int x, y, z;
ll p[N];
int fi[N], nt[M], to[M], v[M], tot = 1;

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
	nt[++ tot] = fi[y], to[tot] = x, v[tot] = z, fi[y] = tot;
}

const ll inf = 1e18;

struct P {
	int x; ll y;
	P(int _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};


bool operator < (P a, P b) {
	return a.y > b.y;
}

priority_queue<P> q;

ll d1[N], d2[N];
int us[N];

void dij(int st, ll *dis) {
	fo(i, 1, n) dis[i] = inf, us[i] = 0;
	dis[st] = 0; q.push(P(st, 0));
	while(q.size()) {
		P b;
		while(q.size()) {
			b = q.top(); q.pop();
			if(us[b.x]) continue;
			break;
		}
		if(us[b.x]) break;
		us[b.x] = 1;
		for(int i = fi[b.x]; i; i = nt[i]) {
			int y = to[i]; ll z = b.y + v[i];
			if(z < dis[y]) {
				dis[y] = z;
				q.push(P(y, z));
			}
		}
	}
}

map<ll, int> cz; int cz0;
ll dd[N];

int n1, n2;
int uni(ll *d) {
	cz.clear();
	fo(i, 1, n) dd[i] = d[i];
	sort(dd + 1, dd + n + 1);
	int d0 = unique(dd + 1, dd + n + 1) - (dd + 1);
	fo(i, 1, d0) cz[dd[i]] = i;
	fo(i, 1, n) d[i] = cz[d[i]];
	return d0;
}

ll f[N][N], g[N][N];
ll s1[N][N], s2[N][N];
ll a1[N][N], a2[N][N];
int c1[N][N], c2[N][N];

int bz[N];

int main() {
	scanf("%d %d %d %d", &n, &m, &S, &T);
	fo(i, 1, n) scanf("%lld", &p[i]);
	fo(i, 1, m) {
		scanf("%d %d %d", &x, &y, &z);
		link(x, y, z);
	}
	dij(S, d1); dij(T, d2);
	n1 = uni(d1);
	n2 = uni(d2);
	fo(j, 0, n2) {
		fo(i, 1, n) if(d2[i] > j) {
			c1[d1[i]][j] = d1[i];
			s1[d1[i]][j] += p[i];
		}
		fo(i, 1, n1) s1[i][j] += s1[i - 1][j];
		fd(i, n1 - 1, 0) c1[i][j] = c1[i][j] ? i : c1[i + 1][j];
	}
	fo(j, 0, n1) {
		fo(i, 1, n) if(d1[i] > j) {
			c2[j][d2[i]] = d2[i];
			s2[j][d2[i]] += p[i];
		}
		fo(i, 1, n2) s2[j][i] += s2[j][i - 1];
		fd(i, n2 - 1, 0) c2[j][i] = c2[j][i] ? i : c2[j][i + 1];
	}
	fo(i, 0, n1 + 1) fo(j, 0, n2 + 1) a1[i][j] = a2[i][j] = -inf;
	fd(j, n2, 0) {
		fd(i, n1, 0) {
			if(c1[i + 1][j]) {
				f[i][j] = a1[c1[i + 1][j]][j] - s1[i][j];
			} 
			if(c2[i][j + 1]) {
				g[i][j] = a2[i][c2[i][j + 1]] - s2[i][j];
			}
			a1[i][j] = max(a1[i + 1][j], -g[i][j] + s1[i][j]);
			a2[i][j] = max(a2[i][j + 1], -f[i][j] + s2[i][j]);
		}
	}
	if(f[0][0] == 0) pp("Flowers\n"); else
		pp("%s\n", f[0][0] > 0 ? "Break a heart" : "Cry");
}