#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define int ll

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
const ll oo = 1e18;

int n, k;

struct T {
	int lazy, mx, pos;
	T(int _pos = 0) {
		pos = _pos;
		mx = 0;	
		lazy = 0;
	}
};

T t[N * 4];
int a[N];

inline void pull(int v) {
	if(MP(t[v * 2].mx, t[v * 2].pos) > MP(t[v * 2 + 1].mx, t[v * 2 + 1].mx))
		t[v].mx = t[v * 2].mx, t[v].pos = t[v * 2].pos;
	else
		t[v].mx = t[v * 2 + 1].mx, t[v].pos = t[v * 2 + 1].pos;
}

inline void apply(int v, int val) {
	t[v].mx += val;
	t[v].lazy += val;
}

inline void push(int v) {
	apply(v * 2, t[v].lazy);
	apply(v * 2 + 1, t[v].lazy);
	t[v].lazy = 0;
}

void build(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = T(tl);
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	pull(v);
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = n) {
	if(l <= tl && tr <= r) {
		apply(v, val);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	if(l < tm) upd(l, r, val, v * 2, tl, tm);
	if(r > tm) upd(l, r, val, v * 2 + 1, tm, tr);
	pull(v);
}

vi G[N], s;
int p[N], tin[N], tout[N], d[N], tt;

void dfs(int u, int pa = 0) {
	s.PB(u);
	tin[u] = tt++;
	p[u] = pa;

	for(int v:G[u]) if(v != pa) {
		d[v] = d[u] + 1;
		dfs(v, u);
	}
	tout[u] = tt;
	
	if(tout[u] == tin[u] + 1) {
		upd(tin[u], tin[u] + 1, d[u]);
	} else {
		upd(tin[u], tin[u] + 1, -1);
	}

}

#define claim(x) if(!(x)) cout << "claim failed: " << __LINE__ << endl, exit(0);

int vis[N];

signed main()
{
	IO_OP;

	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}

	build();

	dfs(1);

	ll mx = -oo;
	int w = 0;
	for(int r = 1; r <= k; r++) {
		int mxd = t[1].mx, pos = t[1].pos;
		debug(mxd, pos);
		if(mxd >= 0) {
			w += mxd;
			int u = s[pos];
			upd(tin[u], tout[u], -1);
			claim(!vis[u]);
			vis[u] = 1;
			while(mxd--) {
				u = p[u];
				upd(tin[u], tout[u], -1);
				claim(!vis[u]);
				vis[u] = 1;
			}
		} else {
			w--;
			claim(r + w == n);
		}
		claim(w >= 0);
		int b = n - r - w;
		claim(b >= 0);
		auto f = [&] (int bb) {
			if(bb < 0 || bb > b) return oo;
			int ww = n - r - bb;
			claim(ww >= 0);
			return 1LL * ww * (r - bb);
		};
		ll mn = oo;
		mn = min(mn, f(0));
		mn = min(mn, f(b));
		mn = min(mn, f(n / 2));
		mn = min(mn, f(n / 2 + 1));
		mx = max(mx, mn);
	}
	cout << mx << '\n';
}