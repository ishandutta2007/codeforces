#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define pp printf
#define ll long long
#define ul unsigned long long
using namespace std;

const int N = 1e5 + 5;

const int M = N * 667;

int t[M][2], c[2], siz[M], tt, z[M], rt;

ul rd = 19260817;
ul rad() {
	rd *= 1000000007;
	return rd;
}
#define x0 t[x][0]
#define x1 t[x][1]
int xin(int &x) {
	if(!x) return 0;
	z[++ tt] = z[x]; siz[tt] = siz[x];
	t[tt][0] = t[x][0]; t[tt][1] = t[x][1];
	return x = tt;
}
void upd(int x) {
	if(x) siz[x] = siz[x0] + siz[x1] + 1;
}
void split(int x, int k) {
	if(k == siz[x]) {c[0] = x; c[1] = 0; return;}
	if(!k) { c[0] = 0; c[1] = x; return;}
	int z = k > siz[x0];
	split(xin(t[x][z]), k - z * (siz[x0] + 1));
	t[x][z] = c[!z]; c[!z] = x; upd(x);
}
int merge(int a, int b) {
	if(!a || !b) return a + b;
	if(rad() % (siz[a] + siz[b]) < siz[a]) {
		t[a][1] = merge(xin(t[a][1]), b);
		upd(a); return a;
	} else {
		t[b][0] = merge(a, xin(t[b][0]));
		upd(b); return b;
	}
}

int d[N];

void dg(int x) {
	if(!x) return;
	dg(x0); d[++ d[0]] = z[x]; dg(x1);
}

int fen(int x, int y) {
	int R = rt;
	split(xin(rt), x - 1);
	split(c[1], y - x + 1);
	rt = R;
	return c[0];
}

int n, m, st; ll tim;

int f[N];

int bz[N];

int dfs(int x, int y) {
	if(x > y) return 0;
	int m = x + y >> 1;
	z[++ tt] = d[m]; int p = tt;
	t[p][0] = dfs(x, m - 1);
	t[p][1] = dfs(m + 1, y);
	upd(p);
	return p;
}

int main() {
	srand(time (0));
	scanf("%d %d", &n, &m);
	fo(i, 1, n) d[i] = i;
	rt = dfs(1, n);
	fo(t, 1, n - 1) {
//		pp("%d %d\n", dep[rt], t);
		int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
		c0 = fen(1 + t, min(m + t, n));
		if(m + t > n) c1 = fen(1, (m + t) % n);
		if(m + 1 - t < 1) c2 = fen(m + 1 - t + n, n);
		c3 = fen(max(1, m + 1 - t), n - t);
		rt = merge(c0, c1);
		c2 = merge(c2, c3);
		rt = merge(rt, c2);
		if(t % 5000 == 0) {
			d[0] = 0; dg(rt);
			rt = dfs(1, n);
		}
	}
	d[0] = 0; dg(rt);
	fo(i, 1, n) f[i] = d[i];
//	fo(i, 1, n) pp("%d ", f[i]); pp("\n");
	scanf("%d %I64d", &st, &tim);
	int x = st;
	fd(i, tim % n, 1) {
		if(x <= m) x = (x + i - 1) % n + 1; else
		x = (x - i), x <= 0 ? x += n : 0;
	}
	ll c = tim / n;
	for(ll i = 1; i <= c; i ++) {
		if(bz[x]) {
			i = i + (c - i) / (i - bz[x]) * (i - bz[x]);
			while(i <= c) i ++, x = f[x];
			break;
		}
		bz[x] = i; x = f[x];
	}
	pp("%d\n", x);
}