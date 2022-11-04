#pragma GCC optimize(3) 
#include<queue>
#include<cstdio>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 2e5 + 5;

int n, m, b, g, x, d, sum;

struct nod {
	int c, l, x;	
} a[N]; int a0;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}
void exgcd(int a, int b, int &x, int &y) {
	if(!b) { x = a; y = 0; return;}
	int X, Y; exgcd(b, a % b, X, Y);
	x = Y; y = X - (a / b) * Y;
}

int solve(int a, int b, int c) {
	int d = gcd(a, gcd(b, c));
	a /= d; b /= d; c /= d;
	int x, y; exgcd(a, b, x, y);
	x = (ll) x * c % b;
	x = (x + b)	% b;
	return x;
}

int cmp(nod a, nod b) {
	return a.c < b.c;	
}

int fi[N * 6], nt[N * 8], to[N * 8], tot;
ll v[N * 8];

void link(int x, int y, ll z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
}

int td = 1;

struct nod2 {
	int a, s;
} t[N]; int t0;

int cmp2(nod2 a, nod2 b) {return a.a < b.a;}

void ins(int n, int m, int x) {
	t[++ t0].s = x;
	x -= x % d;
	int a = solve(m, n, x);
	t[t0].a = a;
}

const int M = 4171391;
struct Hash{
	int h[M], h2[M];
	int a(int x) {
		x ++; int y = x % M;
		while(h[y] != 0 && h[y] != x) y = (y + 1) % M;
		if(!h[y]) h[y] = x, h2[y] = ++ td;
		return h2[y];
	}
} b1, b2;

void gg(Hash &b, int n, int m) {
	#define num(v) (b.a(v))
	#define la(v) (((v - m) % n + n) % n)
	#define nt(v) ((v + m) % n)
	sort(t + 1, t + t0 + 1, cmp2);
	fo(i, 1, t0) link(1, num(t[i].s), t[i].s);
	fo(i, 1, t0) {
		link(num(t[i].s), num(nt(t[i].s)), m);
		link(num(la(t[i].s)), num(t[i].s), m);
	}
	fo(i, 2, t0) if(t[i - 1].a + 1 < t[i].a)
		link(num(nt(t[i - 1].s)), num(la(t[i].s)), (ll) (t[i].a - t[i - 1].a - 2) * m);
	if((n / d - (t[t0].a - t[1].a) - 2) > 0)
		link(num(nt(t[t0].s)), num(la(t[1].s)), (ll) (n / d - (t[t0].a - t[1].a) - 2) * m);
}

struct ds {
	ll y; int x;
} w[N * 6];
bool operator < (ds a, ds b) {return a.y > b.y;}
priority_queue<ds> q;
bool bz[N * 6];

void dij() {
	fo(i, 2, td) w[i].y = 9e18;
	fo(i, 1, td) w[i].x = i;
	q.push(w[1]);
	while(!q.empty()) {
		ds b = q.top(); q.pop();
		if(bz[b.x] || b.y > w[b.x].y) continue;
		bz[b.x] = 1;
		for(int i = fi[b.x]; i; i = nt[i])
			if(v[i] + b.y < w[to[i]].y)
				w[to[i]].y = v[i] + b.y, q.push(w[to[i]]);
	}
}

int xg[N], xc[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	d = gcd(n, m);
	scanf("%d", &b);
	fo(i, 1, b) {
		scanf("%d", &x);
		a[++ a0].x = x; a[a0].c = x % d; a[a0].l = 1;
	}
	scanf("%d", &g);
	fo(i, 1, g) {
		scanf("%d", &x);
		a[++ a0].x = x; a[a0].c = x % d; a[a0].l = 2;
	}
	sort(a + 1, a + a0 + 1, cmp);
	int la = 1;
	td = 1;
	fo(i, 2, a0 + 1) if(i > a0 || a[i].c != a[i - 1].c)  {
		sum ++;
		t0 = 0;
		fo(j, la, i - 1){
			 ins(n, m, a[j].x % n);
			 if(a[j].l == 1) xg[++ xg[0]] = a[j].x;
		}
		gg(b1, n, m);
		t0 = 0;
		fo(j, la, i - 1) {
			ins(m, n, a[j].x % m);
			 if(a[j].l == 2) xc[++ xc[0]] = a[j].x;
		}
		gg(b2, m, n);
		la = i;		
	}
	if(sum < d) { printf("-1\n"); return 0;	}
	dij();
	fo(i, 1, xg[0]) w[b1.a(xg[i])].y = 0;
	fo(i, 1, xc[0]) w[b2.a(xc[i])].y = 0;
	ll ans = 0;
	fo(i, 1, td) ans = max(ans, w[i].y);
	printf("%I64d", ans);
}