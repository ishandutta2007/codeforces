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

const int INF = 1e9 + 7, N = 5e5 + 7;
const ll oo = 1e18;

int a[N], b[N], c[N];
ll up[N], p[N], down[N];
ll dp[N], aux[N];
namespace ST {
	ll st[N][20];
	void build(int n) {
	    for(int i = 1; i <= n ;i++)
	        st[i][0] = up[i] - p[i - 1];
	    for(int j = 1; j < 20; j++)
	        for(int i = 1;i + (1 << j) - 1 <= n; i++)
	            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	ll qry(int l, int r) {
		int d = r - l + 1;
		int k = 32 - __builtin_clz(d) - 1;
		return max(st[l][k], st[r-(1<<k)+1][k]);
	}
}

V<array<int, 3>> clear_up(V<array<int, 3>>&ev, int L, int R) {
	int mnk = INF;
	V<array<int, 3>> res;
	for(auto [l, r, k] : ev) {
		if(l == L && r == R - 1) mnk = min(mnk, k);
		else res.PB({l, r, k});
	}
	if(mnk != INF) res.PB({L, R - 1, mnk});
	return res;
}

void solve(V<array<int, 3>> ev, int L, int R) {
	ev = clear_up(ev, L, R);
	if(R - L == 1) {
		for(auto [l, r, k] : ev) {
			assert(l == L && r == L);
			dp[L] = max(dp[L], up[L] - p[L - 1] - k);
		}
		return;
	}
	int m = (L + R) / 2;
	V<array<int, 3>> evl, evr, evm;
	for(auto [l, r, k] : ev) {
		if(r < m) evl.PB({l, r, k});
		else if(l >= m) evr.PB({l, r, k});
		else evm.PB({l, r, k}), evl.PB({l, m - 1, k}), evr.PB({m, r, k});
	}
	solve(evl, L, m), solve(evr, m, R);

	for(int i = m; i < R; i++) aux[i] = -oo;

	for(auto[l, r, k] : evm) {
		assert(l < m && r >= m);
		ll x = ST::qry(l, m - 1) - k;
		aux[r] = max(aux[r], x);
	}
	for(int i = R - 1; i >= m; i--) {
		dp[i] = max(dp[i], aux[i]);
		if(i - 1 >= m) aux[i - 1] = max(aux[i - 1], aux[i]);
	}
}

int n, q;

ll t[N * 4];

inline void apply(int v, ll val) {
	t[v] = max(t[v], val);
}

inline void push(int v) {
	apply(v * 2, t[v]);
	apply(v * 2 + 1, t[v]);
}

void build(int v = 1, int tl = 1, int tr = n + 1) {
	if(tr - tl == 1) {
		t[v] = dp[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	t[v] = -oo;
}

ll qry(int pos, int v = 1, int tl = 1, int tr = n + 1) {
	if(tr - tl == 1) {
		assert(tl == pos);
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	if(pos < tm) return qry(pos, v * 2, tl, tm);
	else return qry(pos, v * 2 + 1, tm, tr);
}

void upd(int l, int r, ll val, int v = 1, int tl = 1, int tr = n + 1) {
	if(l <= tl && tr <= r) {
		apply(v, val);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	if(l < tm) upd(l, r, val, v * 2, tl, tm);
	if(r > tm) upd(l, r, val, v * 2 + 1, tm, tr);
}

signed main()
{
	IO_OP;

	memset(dp, 0xc0, sizeof dp);

	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		cin >> a[i], up[i] = up[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i], p[i] = p[i - 1] + b[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = n; i >= 1; i--)
		down[i] = down[i + 1] + c[i];

	ST::build(n);

	V<array<int, 3>> ev;
	for(int i = 0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		ev.PB({l, r, k});
	}

	solve(ev, 1, n + 1);

	build();

	sort(ALL(ev));
	for(auto[l, r, k]:ev) if(l > 1) {
		upd(l, r + 1, qry(l - 1) - k);
	}
	ll ans = -oo;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, qry(i) + down[i] + p[i]);
	}
	cout << ans << '\n';
}