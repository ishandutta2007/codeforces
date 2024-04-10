#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], pos[N], l[N], r[N];
V<pi> aux[N];

int n;

namespace DS {
	struct node {
		ll m, b, lz_m, lz_b;
		node() { m = b = lz_m = lz_b = 0; }
	} t[N * 4];
	void apply(int v, ll m, ll b, int tl, int tr) {
		t[v].lz_m += m, t[v].lz_b += b;
		t[v].m += m * (tr - tl);
		t[v].b += b * (tr - tl);
	}
	void push(int v, int tl, int tr) {
		int tm = (tl + tr) / 2;
		apply(v * 2, t[v].lz_m, t[v].lz_b, tl, tm);
		apply(v * 2 + 1, t[v].lz_m, t[v].lz_b, tm, tr);
		t[v].lz_m = t[v].lz_b = 0;
	}
	void pull(int v) {
		t[v].m = t[v * 2].m + t[v * 2 + 1].m;
		t[v].b = t[v * 2].b + t[v * 2 + 1].b;
	}
	void add(int l, int r, int m, int b, int v = 1, int tl = 0, int tr = n) {
		if(l <= tl && tr <= r) {
			apply(v, m, b, tl, tr);
			return;
		}
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		if(l < tm) add(l, r, m, b, v * 2, tl, tm);
		if(r > tm) add(l, r, m, b, v * 2 + 1, tm, tr);
		pull(v);
	}
	ll qry(int l, int r, int x, int v = 1, int tl = 0, int tr = n) {
		if(l <= tl && tr <= r)
			return t[v].m * x + t[v].b;
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		ll res = 0;
		if(l < tm) res += qry(l, r, x, v * 2, tl, tm); 
		if(r > tm) res += qry(l, r, x, v * 2 + 1, tm, tr);
		return res;
	}
}


signed main()
{
	IO_OP;

	int q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		l[i] = i - 1;
		while(l[i] != -1 && a[l[i]] < a[i]) l[i] = l[l[i]];
	}
	for(int i = n - 1; i >= 0; i--) {
		r[i] = i + 1;
		while(r[i] != n && a[r[i]] < a[i]) r[i] = r[r[i]];
	}

	for(int i = 1; i * (i + 1) <= n; i++)
		for(int j = i + 1; i * j <= n; j++)
			aux[i * j].EB(pos[i], pos[j]);

	V<array<int, 4>> ev;

	for(int i = 1; i <= n; i++) {
		int xl = l[pos[i]] + 1, yr = r[pos[i]] - 1;
		V<pi> tt, stk;
		for(auto[xr, yl]:aux[i]) {
			if(xr > yl) swap(xr, yl);
			xr = min(xr, pos[i]), yl = max(yl, pos[i]);
			assert(xr < yl);
			if(xl <= xr && yl <= yr)
				tt.EB(xr, yl);
		}
		sort(ALL(tt), [&] (pi x, pi y) {
			x.S *= -1, y.S *= -1;
			return x < y;
		});
		for(auto [xr, yl]:tt) {
			while(SZ(stk) && stk.back().S >= yl)
				stk.pop_back();
			stk.EB(xr, yl);
		}
		for(auto [xr, yl]:stk) {
			assert(xl <= xr);
			ev.PB({xl, 1, yl, yr + 1});
			ev.PB({xr + 1, -1, yl, yr + 1});
			debug(xl, xr, yl, yr);
			xl = xr + 1;
		}
	}

	V<ll> ans(q);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r, l--, r--;
		ev.PB({l - 1, i * 2 + 2, l, r + 1}); // -
		ev.PB({r, i * 2 + 3, l, r + 1}); // +
	}
	sort(ALL(ev));
	for(auto[x, op, l, r] : ev) {
		if(op < 2) {
			assert(l < r);
			DS::add(l, r, op, -op * x + op);
		} else {
			int i = (op - 2) / 2, sign = op & 1 ? 1 : -1;
			assert(l < r);
			ans[i] += sign * DS::qry(l, r, x);
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';

}