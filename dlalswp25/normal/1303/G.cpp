#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MX = (1LL) << 50;

struct LIN {
	ll a, b;
	LIN(ll _a = 0, ll _b = 0) : a(_a), b(_b) {}

	ll get(ll x) { return a * x + b; }
};

struct NODE {
	LIN l;
	int lft, rgt;
	NODE() : l(LIN(0, 0)), lft(0), rgt(0) {}
};

struct LiChao {
	vector<NODE> T;
	int id;

	LiChao() { T.resize(2); id = 1; }

	void upd(int idx, ll s, ll e, LIN x) {
		LIN lo = T[idx].l;
		LIN hi = x;
		if(lo.get(s) > hi.get(s)) swap(lo, hi);
		if(lo.get(e) < hi.get(e)) { T[idx].l = hi; return; }

		if(s == e) return;

		ll m = s + e >> 1;
		if(lo.get(m) < hi.get(m)) {
			T[idx].l = hi;
			if(!T[idx].rgt) { T.push_back(NODE()); T[idx].rgt = ++id; }
			upd(T[idx].rgt, m + 1, e, lo);
		}
		else {
			T[idx].l = lo;
			if(!T[idx].lft) { T.push_back(NODE()); T[idx].lft = ++id; }
			upd(T[idx].lft, s, m, hi);
		}
	}

	void add(LIN x) {
		upd(1, 0, MX, x);
	}

	ll _get(int idx, ll s, ll e, ll p) {
		if(!idx) return 0;
		if(p < s || e < p) return 0;
		ll ret = T[idx].l.get(p);
		ll m = s + e >> 1;
		return max(ret, max(_get(T[idx].lft, s, m, p), _get(T[idx].rgt, m + 1, e, p)));
	}

	ll get(ll x) {
		return _get(1, 0, MX, x);
	}
};

int N;
ll A[151515];
vector<int> adj[151515];

bool chk[151515];
int sz[151515];

struct TRE {
	LiChao up, dn;
	ll ans;
	int c;

	void dfs(int v, int p, int len, ll sp1, ll sum, ll sp2) {
		ans = max(ans, up.get(len) + sp1);
		ans = max(ans, dn.get(sum) + sp2);

		for(int i : adj[v]) {
			if(chk[i] || i == p) continue;
			dfs(i, v, len + 1, sp1 + (sum + A[c] + A[i]), sum + A[i], sp2 + len * A[i]);
		}
	}

	void dfs2(int v, int p, int len, ll sp1, ll sum, ll sp2) {
		dn.add(LIN((ll)len, sp1));
		up.add(LIN(sum, sp2));

		for(int i : adj[v]) {
			if(chk[i] || i == p) continue;
			dfs2(i, v, len + 1, sp1 + (sum + A[c] + A[i]), sum + A[i], sp2 + len * A[i]);
		}	
	}

	void init(int cen) {
		c = cen; ans = A[cen];
		for(int i : adj[cen]) {
			if(chk[i]) continue;
			dfs(i, cen, 2, 2 * A[c] + A[i], A[i], A[i]);
			dfs2(i, cen, 2, 2 * A[c] + A[i], A[i], A[i]);
		}
	}
}C[151515];

void dfs1(int v, int p) {
	sz[v] = 1;
	for(int i : adj[v]) {
		if(chk[i] || i == p) continue;
		dfs1(i, v);
		sz[v] += sz[i];
	}
}

void dnc(int v) {
	dfs1(v, 0);

	int n = sz[v];

	int bef = v, cen = v;
	while(1) {
		bool ok = false;
		for(int i : adj[cen]) {
			if(chk[i] || i == bef) continue;
			if(sz[i] * 2 >= n) {
				ok = true;
				bef = cen; cen = i;
				break;
			}
		}
		if(!ok) break;
	}

	C[cen].init(cen);

	chk[cen] = true;
	for(int i : adj[cen]) {
		if(chk[i]) continue;
		dnc(i);
	}	
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	dnc(1);
	ll ans = 0;
	for(int i = 1; i <= N; i++) ans = max(ans, C[i].ans);
	printf("%lld\n", ans);

	return 0;
}