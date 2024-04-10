#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int n, m, q, A[10][N];

int find(vi& p, int u) {
	return p[u] == u ? p[u] : p[u] = find(p, p[u]);
}
int unite(vi& p, int x, int y) {
	int rx = find(p, x), ry = find(p, y);
	if(rx == ry) return 0;
	p[rx] = ry;
	return 1;
}

struct node {
	int cnt, l, r;
	vi p;
	node() {}
	node(int j) {
		l = r = j;
		p = vi(n * 2);
		for(int i = 0; i < n * 2; i++) p[i] = i % n;
		cnt = n;
		for(int i = 1; i < n; i++)
			if(A[i][j] == A[i - 1][j])
				cnt -= unite(p, i, i - 1);
	}
} t[N * 4];

node operator + (node a, node b) {
	vi p(n * 4);
	auto mod_a = [&] (int u) {
		if(u < n) return u;
		return u + n;
	};
	auto mod_b = [&] (int u) {
		if(u < n) return u + 3 * n;
		return u;
	};
	for(int i = 0; i < 2 * n; i++)
		p[mod_a(i)] = mod_a(a.p[i]);
	for(int i = 0; i < 2 * n; i++)
		p[mod_b(i)] = mod_b(b.p[i]);
	int cnt = a.cnt + b.cnt;
	for(int i = 0; i < n; i++)
		if(A[i][a.r] == A[i][b.l]) {
			cnt -= unite(p, 2 * n + i, 3 * n + i);
		}
	for(int i = 0; i < n * 2; i++) { // reroot
		int pp = find(p, i);
		p[pp] = i;
		p[i] = i;
	}
	node c;
	c.l = a.l, c.r = b.r, c.cnt = cnt;
	c.p = vi(n * 2);
	for(int i = 0; i < n * 2; i++)
		c.p[i] = find(p, i);
	return c;
}

void build(int v = 1, int tl = 0, int tr = m) {
	if(tr - tl == 1) {
		t[v] = node(tl);
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

node qry(int l, int r, int v = 1, int tl = 0, int tr = m) {
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry(l, r, v * 2 + 1, tm, tr);
	else return qry(l, r, v * 2, tl, tm) + qry(l, r, v * 2 + 1, tm, tr);
}

signed main()
{
	IO_OP;

	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> A[i][j];
	build();
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << qry(l, r).cnt << '\n';
	}

}