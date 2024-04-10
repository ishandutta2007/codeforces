#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i ,x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 75;

int n, m, a, b;

struct nod {
	int x, y, z;
} c[N * N];

int f[N];

int F(int x) { return f[x] == x ? x : (f[x] = F(f[x]));}

void bin(int x, int y) {
	if(F(x) != F(y)) f[f[x]] = f[y];
}

int fi[N], to[N * N], nt[N * N], v[N * N], tot;

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
	nt[++ tot] = fi[y], to[tot] = x, v[tot] = z, fi[y] = tot;
}

void Init() {
	scanf("%d %d %d %d", &n, &m, &a, &b);
	fo(i, 1, n) f[i] = i;
	fo(i, 1, m) {
		scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].z);
		if(c[i].z == a) {
			bin(c[i].x, c[i].y);
		}
		link(c[i].x, c[i].y, c[i].z);
	}
}

int a2[21];

struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

P operator + (P a, P b) {
	return P(a.x + b.x, a.y + b.y);
}


const int inf = 1e9;

P t[N * N]; int t0;

int gv(P p) { return a * p.x + b * p.y;}

int cmpt(P p, P q) { return gv(p) < gv(q);}

int id[N][N];

int fid[N], fid0, siz[N];

P dis[1 << 18][N];

vector<P> d[N * N];

#define si size()
#define pb push_back

void gx(int s, int x, P p) {
	if(id[p.x][p.y] < id[dis[s][x].x][dis[s][x].y]) {
		dis[s][x] = p;
		d[id[p.x][p.y]].pb(P(s, x));
	}
}

int ans[N];

void work() {
	a2[0] = 1; fo(i, 1, 20) a2[i] = a2[i - 1] * 2;
	
	fo(i, 0, n) fo(j, 0, n) t[++ t0] = P(i, j);
	sort(t + 1, t + t0 + 1, cmpt);
	int ct = 0;
	fo(i, 1, t0) {
		if(i == 1 || gv(t[i - 1]) != gv(t[i])) ct ++;
		id[t[i].x][t[i].y] = ct;
	}
	
	fo(i, 1, n) siz[F(i)] ++;
	fo(i, 1, n) if(F(i) == i && siz[i] > 3) {
		fid[i] = ++ fid0;
	}
	fo(i, 1, n) fid[i] = fid[F(i)];
	
	ff(s, 0, a2[fid0]) fo(i, 1, n) dis[s][i] = P(n, n);
	
	int ss = 0;
	if(fid[1]) ss |= a2[fid[1] - 1];
	dis[ss][1] = P(0, 0);
	d[id[0][0]].pb(P(ss, 1));
	
	fo(i, 1, n) ans[i] = inf;
	fo(i, 1, ct) {
		ff(_j, 0, d[i].si) {
			P w = d[i][_j];
			
			int s = w.x, x = w.y;
			
			if(id[dis[s][x].x][dis[s][x].y] < i) continue;
			
			ans[x] = min(ans[x], gv(dis[s][x]));
			
			for(int k = fi[x]; k; k = nt[k]) {
				int y = to[k], z = v[k];
				if(z == b) {
					if(F(x) == F(y)) continue;
					if(fid[y] && (s >> (fid[y] - 1) & 1)) continue;
				}
				int ns = s;
				if(fid[y]) ns |= a2[fid[y] - 1];
				P p = dis[s][x];
				//if(y == 3) pp("%d %d %d %d\n", p.x, p.y, s, x);
				if(z == a) p.x ++; else p.y ++;
				gx(ns, y, p);
			}
		}
	}
	fo(i, 1, n) pp("%d ", ans[i]);
}

int main() {
	Init();	
	work();
}