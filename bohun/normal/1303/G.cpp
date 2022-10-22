#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;

const int nax = 150000 + 111;
const int pod = (1 << 18);
const LL INF = 1e18;

struct line {
	LL a, b;
	line () {}
	line (LL a, LL b) : a(a), b(b) {}
	LL get(LL x) {
		return a * x + b;
	}
};

struct li {
	line t[2 * pod];
	
	void init() {
		for (int i = 1; i < 2 * pod; ++i)
			t[i] = {0, -INF};
	}
	
	vector <int> ind;
	
	void add(line cur, int u = 1, int l = 0, int r = pod - 1) {
		if (t[u].get(0) == -INF) {ind.pb(u); t[u] = cur; return;}
		if (l == r) {
			if (cur.get(l) > t[u].get(l)) t[u] = cur;
			return;
		}
		int m = (l + r) / 2;
		bool mid = (cur.get(m) > t[u].get(m));
		if (mid) swap(cur, t[u]);
		if (cur.get(l) > t[u].get(l)) add(cur, 2 * u, l, m);
		else add(cur, 2 * u + 1, m + 1, r);
	}
	
	LL query(int x, int u = 1, int l = 0, int r = pod - 1) {
		LL res = t[u].get(x);
		if (l == r) return res;
		int m = (l + r) / 2;
		if (x <= m) res = max(res, query(x, 2 * u, l, m));
		else res = max(res, query(x, 2 * u + 1, m + 1, r));
		return res;
	}
	
	void clear() {
		for (auto it : ind) 
			t[it] = {0, -INF};
		ind.clear();
	}	
} ja;

int n;
int a, b;
LL c[nax];	

vector <int> v[nax];

LL best;

bool used[nax];
int siz[nax];

void dfs1(int u, int p) {
	siz[u] = 1;
	for (int it : v[u])
		if (!used[it] && it != p) {
			dfs1(it, u);
			siz[u] += siz[it];
		}
}

int dfs2(int u, int p, int sz) {
	for (auto it : v[u]) 
		if (!used[it] && it != p && sz < 2 * siz[it])
			return dfs2(it, u, sz);
	return u;
}

vector <pair<LL, LL>> vec;

void dfs3(int u, int p, int h, LL s, LL s1, LL s2, LL s3) {
	s += c[u];
	s1 += c[u] * h;
	s2 += s3 + c[u];
	s3 += c[u];
	best = max(best, ja.query(h + 1) + s2);
	vec.pb({s, s1});
	for (int it : v[u])
		if (!used[it] && it != p)
			dfs3(it, u, h + 1, s, s1, s2, s3);
}
	

void dec(int u) {
	dfs1(u, 0);
	int x = dfs2(u, 0, siz[u]);
	
	ja.clear();
	ja.add(line(0, 0));
	
	for (auto it : v[x])
		if (!used[it]) {
			dfs3(it, x, 1, 0, 0, c[x], c[x]);
			for (auto i : vec) 
				ja.add({i.fi, i.se});
			vec.clear();
		}
	
	ja.clear();
	reverse(v[x].begin(), v[x].end());
	
	for (auto it : v[x])
		if (!used[it]) {
			dfs3(it, x, 1, 0, 0, c[x], c[x]);
			for (auto i : vec)
				ja.add(line(i.fi, i.se));
			vec.clear();
		}
	
	used[x] = 1;
	for (int it : v[x])
		if (!used[it])
			dec(it);
} 

int main() {
	ja.init();
	scanf ("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf ("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", c + i);
		best = max(best, c[i]);
	}
	dec(1);
	printf ("%lld", best);
	
	return 0;
}