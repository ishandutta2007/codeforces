#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 2e5 + 101;

int n, me, q;
int e[N], f[N];

struct uf {
	int p[N], siz[N], color[N];
	vector <pair<int*, int>> v;
	
	uf() {
		rep(i, 1, N - 1) {
			p[i] = i;
			color[i] = 0;
			siz[i] = 1;
		}
	}
	
	int root(int x) {
		if (x == p[x]) return x;
		return root(p[x]);
	}
	
	int kolor(int x) {
		if (x == p[x]) return 0;
		return color[x] ^ kolor(p[x]);
	}
	
	bool unia(int x, int y) { // 1 - jest dwudzielny, 0 - nie jest
		int rootx = root(x), rooty = root(y);
		if (rootx == rooty) {
			if (kolor(x) == kolor(y)) return 0;
			return 1;
		}
		
		if (siz[rootx] > siz[rooty]) {
			swap(x, y);
			swap(rootx, rooty);
		}
		
		v.pb({&siz[rooty], siz[rooty]});
		v.pb({&color[rootx], color[rootx]});
		v.pb({&p[rootx], p[rootx]});
		
		color[rootx] = kolor(x) ^ kolor(y) ^ 1;
		siz[rooty] += siz[rootx];
		p[rootx] = rooty;
		return 1;
	}
	
	void roll(int sz) {
		while (ss(v) > sz) {
			*v.back().fi = v.back().se;
			v.pop_back();
		}
	}
} U;

int g[N];

void dziel(int l, int r, int optl, int optr) {
	if (l > r) return;
	int m = (l + r) / 2, sz = ss(U.v);
	
	rep(i, l, m - 1) U.unia(e[i], f[i]);
	per(i, max(m, optl), optr) {
		if (!U.unia(e[i], f[i]) || i == max(m, optl)) {
			g[m] = i;
			break;
		}
	}
	
	U.roll(sz);
	rep(i, g[m] + 1, optr)
		U.unia(e[i], f[i]);
	dziel(l, m - 1, optl, g[m]);
	
	U.roll(sz);
	rep(i, l, m)
		U.unia(e[i], f[i]);
	dziel(m + 1, r, g[m], optr);
	
	U.roll(sz);
}
	

int main() {	
	scanf ("%d%d%d", &n, &me, &q);
	rep(i, 1, me) {
		scanf ("%d%d", e + i,f + i);
	}
	int x = me;
	rep(i, 1, me) {
		if (!U.unia(e[i], f[i])) {
			x = i;
			break;
		}
	}
	U.roll(0);
	
	rep(i, x + 1, me) g[i] = me + 1;
	
	dziel(1, x, 1, me);
	
	while (q--) {
		int l, r;
		scanf ("%d%d", &l, &r);
		printf (r < g[l] ? "YES\n" : "NO\n");
	}
	return 0;
}