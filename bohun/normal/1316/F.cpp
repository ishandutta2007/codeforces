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
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;	

const int nax = 3e5 + 111;
const int MOD = 1e9 + 7;
const int pod = (1 << 20);

LL pt(LL a, LL b) {
	if (!b) return 1;
	if (b & 1) return a * pt(a, b - 1) % MOD;
	return pt(a * a % MOD, b / 2);
}

int p2[nax];
vector <pair<int, int>> v;

struct nod {
	LL res, L, R, cnt;
} t[2 * pod];

void akt(int x, int c, int u = 1, int l = 0, int r = pod - 1) {
	if (l == r) {
		t[u].res = 0;
		t[u].L = (c == 1 ? v[l].fi : 0);
		t[u].R = (c == 1 ? v[l].fi : 0);
		t[u].cnt = (c == 1 ? 1 : 0);
		return;
	}
	int m = (l + r) / 2;
	if (x <= m) akt(x, c, 2 * u, l, m);
	if (m < x) akt(x, c, 2 * u + 1, m + 1, r);
	
	int pl = p2[t[2 * u].cnt];
	int pr = p2[t[2 * u + 1].cnt]; 
	
	t[u].res = (t[2 * u].res * pr + t[2 * u + 1].res * pl + t[2 * u].L * t[2 * u + 1].R) % MOD;
	t[u].cnt = (t[2 * u].cnt + t[2 * u + 1].cnt);
	t[u].L = (t[2 * u].L + t[2 * u + 1].L * pl) % MOD;
	t[u].R = (t[2 * u + 1].R + t[2 * u].R * pr) % MOD;
}

int n;
int p[nax];
int q;
int a[nax], b[nax], c[nax];

int daj(pair<int, int> x) {
	return (int) (lower_bound(v.begin(), v.end(), x) - v.begin());
}

int main() {	
	rep(i, 1, 2 * pod - 1) {
		t[i].res = t[i].L = t[i].R = t[i].cnt = 0LL;
	}
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", p + i);
		v.pb({p[i], i});
	}
	p2[0] = 1;
	rep(i, 1, nax - 1) p2[i] = p2[i - 1] * 2 % MOD;
	scanf ("%d", &q);
	rep(i, 1, q) {
		scanf ("%d%d", a + i, b + i);
		v.pb({b[i], -i});
	}
	sort(v.begin(), v.end());
	
	rep(i, 1, n) {
		int pos = daj(mp(p[i], i));
		c[i] = pos;
		akt(pos, 1);
	}
	
	int xd = pt(pt(2, MOD - 2), n);
	
	printf ("%lld\n", t[1].res * xd % MOD);
	rep(i, 1, q) {
		akt(c[a[i]], 0);
		c[a[i]] = daj(mp(b[i], -i));
		akt(c[a[i]], 1);
		printf ("%lld\n", t[1].res * xd % MOD);
	}
	
	
	return 0;
}