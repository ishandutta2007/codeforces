#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e5 + 100;
const int pod = (1 << 17);
const int P = 37;
const int P2 = 39;
const int MOD = 1e9 + 9;

void add(pair<int, int> &a, pair<int, int> b) {
	a.fi += b.fi;
	a.se += b.se;
	if (a.fi >= MOD) a.fi -= MOD;
	if (a.se >= MOD) a.se -= MOD;
}

int n, m, k;
char s[N];
int t[N];

pair <int, int> hasz[2 * pod];
int lazy[2 * pod];
int qw[11][18];
int qw2[11][18];
int pp[2 * pod];
int pp2[2 * pod];

void akt(int u, int p) {
	p--;
	int x = 2 * u, y = 2 * u + 1;
	hasz[u].fi = (hasz[x].fi + (LL) hasz[y].fi * pp[1 << p] % MOD) % MOD;
	hasz[u].se = (hasz[x].se + (LL) hasz[y].se * pp2[1 << p] % MOD) % MOD;
}

void build(int u = 1, int l = 0, int r = pod - 1, int p = 17) {
	if (l == r) return;
	int m = (l + r) / 2;
	build(2 * u, l, m, p - 1);
	build(2 * u + 1, m + 1, r, p - 1);
	akt(u, p);
} 

void push(int u, int p) {
	if (!lazy[u]) return;
	int x = 2 * u, y = 2 * u + 1;
	hasz[x] = {qw[lazy[u]][p - 1], qw2[lazy[u]][p - 1]};
	lazy[x] = lazy[u];
	hasz[y] = {qw[lazy[u]][p - 1], qw2[lazy[u]][p - 1]};
	lazy[y] = lazy[u];
	lazy[u] = 0;
}

void ustaw(int x, int y, int z, int u = 1, int l = 0, int r = pod - 1, int p = 17) {
	if (x <= l && r <= y) {
		hasz[u] = {qw[z][p], qw2[z][p]};
		lazy[u] = z;
		return;
	}
	push(u, p);
	int m = (l + r) / 2;
	if (x <= m) ustaw(x, y, z, 2 * u, l, m, p - 1);
	if (m < y) ustaw(x, y, z, 2 * u + 1, m + 1, r, p - 1);
	akt(u, p);
}

pair <int, int> query(int x, int y, int u = 1, int l = 0, int r = pod - 1, int p = 17) {
	if (x <= l && r <= y) {
		//printf ("-- %d %d %d %d %lld\n", l, r, hasz[u].fi, pp[l - x], (LL) pp[l - x] * hasz[u].fi % MOD);
		return {(LL) pp[l - x] * hasz[u].fi % MOD, (LL) pp2[l - x] * hasz[u].se % MOD};
	}
	push(u, p);
	int m = (l + r) / 2;
	pair <int, int> res = {0, 0};
	if (x <= m) add(res, query(x, y, 2 * u, l, m, p - 1));
	if (m < y) add(res, query(x, y, 2 * u + 1, m + 1, r, p - 1));
	return res;
}	

int main() {
	pp[0] = 1;
	pp2[0] = 1;
	rep(i, 1, 2 * pod - 1) {
		pp[i] = (LL) pp[i - 1] * P % MOD;
		pp2[i] = (LL) pp2[i - 1] * P2 % MOD;
	}
	scanf ("%d%d%d", &n, &m, &k);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		t[i] = (s[i] - '0') + 1;
		hasz[i + pod] = {t[i], t[i]};
	}
	rep(i, 1, 10) {
		qw[i][0] = i;
		qw2[i][0] = i;
		rep(j, 1, 17) 
			qw[i][j] = (qw[i][j - 1] + (LL) qw[i][j - 1] * pp[1 << (j - 1)] % MOD) % MOD;
		rep(j, 1, 17)
			qw2[i][j] = (qw2[i][j - 1] + (LL) qw2[i][j - 1] * pp2[1 << (j - 1)] % MOD) % MOD;
	}
	build();
	rep(i, 1, m + k) {
		int a, b, c, d;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		if (a == 1) {
			ustaw(b, c, d + 1);
		}
		if (a == 2) {
			int h = (c - b + 1) - d;
			//cat(query(b, b + h - 1).fi);
			//cat(query(c - h + 1, c).fi);
			if (query(b, b + h - 1) == query(c - h + 1, c)) printf ("YES\n");
			else printf ("NO\n");
		}
	}
	
	return 0;
}