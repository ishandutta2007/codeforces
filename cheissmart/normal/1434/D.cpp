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

const int INF = 1e9 + 7, N = 5e5 + 7;

int yes[N];
V<pi> G[N];

pi farthest(int u, int p = -1) {
	pi ans = {0, u};
	for(pi e:G[u]) if(e.F != p) {
		pi tt = farthest(e.F, u);
		tt.F++;
		ans = max(ans, tt);
	}
	return ans;
}

int n;

struct seg {
	/*
	    NOTE: remember to call build function
	*/
	struct T {
		bool flip;
		int ans0, ans1;
		T(int val = 0) {
			flip = 0;
			ans0 = val;
			ans1 = 0;
		}
	};

	T t[N * 4];
	int a[N];

	inline T add(T x, T y) {
		T z;
		z.ans0 = max(x.ans0, y.ans0);
		z.ans1 = max(x.ans1, y.ans1);
		return z;
	}

	inline void pull(int v) {
		t[v] = add(t[v * 2], t[v * 2 + 1]);
	}

	inline void apply(int v) {
		t[v].flip ^= 1;
		swap(t[v].ans0, t[v].ans1);
	}

	inline void push(int v) {
		if(t[v].flip) {
			apply(v * 2);
			apply(v * 2 + 1);
			t[v].flip = 0;
		}
	}

	void build(int v = 1, int tl = 0, int tr = n) {
		if(tr - tl == 1) {
			t[v] = T(a[tl]); // set one
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm, tr);
		pull(v);
	}
	void upd(int l, int r, int v = 1, int tl = 0, int tr = n) {
		if(l <= tl && tr <= r) {
			apply(v);
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		if(l < tm) upd(l, r, v * 2, tl, tm);
		if(r > tm) upd(l, r, v * 2 + 1, tm, tr);
		pull(v);
	}

};

struct DS {
	int tin[N], tout[N], down[N], tm;
	seg t;
	void dfs(int u, int p = -1, int depth = 0) {
		tin[u] = tm++;
		t.a[tin[u]] = depth;
		for(pi e:G[u]) if(e.F != p) {
			int v = e.F, id = e.S;
			down[id] = v;
			dfs(v, u, depth + 1);
		}
		tout[u] = tm;
	}
	DS(int root) {
		tm = 0;
		dfs(root);
		t.build();
	}
	void flip(int edge) {
		int u = down[edge];
		t.upd(tin[u], tout[u]);
	}
	int qry() {
		return t.t[1].ans0;
	}
};

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v >> yes[i];
		G[u].EB(v, i);
		G[v].EB(u, i);
	}
	int r1 = farthest(1).S, r2 = farthest(r1).S;

	DS d1(r1), d2(r2);
	auto flip = [&](int edge) {
		d1.flip(edge);
		d2.flip(edge);
	};

	for(int i = 0; i < n - 1; i++)
		if(yes[i]) flip(i);
	int m;
	cin >> m;
	while(m--) {
		int i;
		cin >> i;
		i--;
		flip(i);
		cout << max(d1.qry(), d2.qry()) << '\n';
	}
}