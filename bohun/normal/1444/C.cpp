#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using ll = long long;
using ld = long double;
using namespace std;

const int N = 5e5 + 500;

int n, m, k, e[N], GG[N];
vector <int> G[N];

int p[N], siz[N], color[N];

int find(int x) {
	if (p[x] == x) return x;
	return find(p[x]);
}

int C(int x) {
	if (x == p[x]) return 0;
	return color[x] ^ C(p[x]);
}

vector <pair<int*, int>> roll;

bool unite(int x, int y) {
	int repx = find(x), repy = find(y);
	if (repx == repy) {
		if (C(x) == C(y)) return 0;
		return 1;
	}
	if (siz[repx] > siz[repy]) {
		swap(x, y);
		swap(repx, repy);
	}
	int nC = 1 ^ C(x) ^ C(y);
	roll.pb(mp(&siz[repy], siz[repy]));
	roll.pb(mp(&p[repx], p[repx]));
	roll.pb(mp(&color[repx], color[repx]));
	color[repx] = nC;
	p[repx] = repy;
	siz[repy] += siz[repx];
	return 1;
}

vector <pair<pair<int, int>, pair<int, int>>> g;

int main() {
	scanf ("%d%d%d", &n, &m, &k);
	rep(i, 1, n) 
		scanf ("%d", e + i);
	rep(i, 1, n) {
		siz[i] = 1;
		p[i] = i;
		color[i] = 0;
	}
	rep(i, 1, m) {
		int a, b;
		scanf ("%d%d", &a, &b);
		if (e[a] > e[b]) swap(a, b);
		if (e[a] == e[b]) {
			if (GG[e[a]]) continue;
			if (!unite(a, b))  
				GG[e[a]] = 1;
		}
		else {
			g.pb(mp(mp(e[a], e[b]), mp(a, b)));
		}
	}
	sort(all(g));
	ll cnt = 0;
	rep(i, 1, k) cnt += !GG[i];
	ll res = cnt * (cnt - 1) / 2;
	//~ rep(i, 1, n) cat(GG[i]);
	
	for (int i = 0; i < sz(g);) {
		int j = i;
		while (j < sz(g) && g[i].fi == g[j].fi) j++;
		int idx = g[i].fi.fi, idy = g[i].fi.se;
		if (GG[idx] || GG[idy]) {
			i = j;
			continue;
		}
		res--;
		bool f = 1;
		int cur = sz(roll);
		//~ cat(idx);cat(idy);
		rep(w, i, j - 1) {
			f = unite(g[w].se.fi, g[w].se.se);
			if (!f) {
				//~ cat(g[w].se.fi);cat(g[w].se.se);
				break;
			}
		}
		if (f) res++;
		while (sz(roll) != cur) {
			*roll.back().fi = roll.back().se;
			roll.pop_back();
		}
		i = j;
	}
	printf ("%lld\n", res);
}