#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
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

const int INF = 1e9 + 7, N = 15005;

void cmin(int& a, int b) {
	a = min(a, b);
}

void cmax(int& a, int b) {
	a = max(a, b);
}

struct Seg {
	int n;
	struct node {
		int val;
		node() { val = INF; }
	};
	V<node> t;
	Seg(int _n) {
		n = _n;
		t = V<node>(n * 4);
	}
	void apply(int v, int val) {
		cmin(t[v].val, val);
	}
	void push(int v) {
		apply(v * 2, t[v].val);
		apply(v * 2 + 1, t[v].val);
	}
	void upd(int l, int r, int val) {
		upd(l, r, val, 1, 0, n);
	}
	void upd(int l, int r, int val, int v, int tl, int tr) {
		if(l <= tl && tr <= r) {
			apply(v, val);
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		if(l < tm)
			upd(l, r, val, v * 2, tl, tm);
		if(r > tm)
			upd(l, r, val, v * 2 + 1, tm, tr);
	}
	int qry(int pos) {
		return qry(pos, 1, 0, n);
	}
	int qry(int pos, int v, int tl, int tr) {
		if(tr - tl == 1)
			return t[v].val;
		push(v);
		int tm = (tl + tr) / 2;
		if(pos < tm)
			return qry(pos, v * 2, tl, tm);
		else 
			return qry(pos, v * 2 + 1, tm, tr);
	}
};

void solve() {
	int n;
	cin >> n;
	vi a(n), pos(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	reverse(ALL(a));
	for(int i = 0; i < n; i++)
		pos[a[i]] = i;

	vi dpl, dpr;
	auto go = [&](int len) {
		int ans = 0;
		for(int i = len; ; i++) {
			bool yes = false;
			V<V<array<int, 4>>> ev(n);
			auto add_event = [&] (int pos, int l, int r, int op, int val) {
				if(pos >= n) return;
				if(l >= r) return;
				ev[pos].PB({l, r, op, val});
			};
			for(int j = 0; j < n; j++) {
				if(dpl[j] != INF || dpr[j] != -INF) yes = true;
				if(dpl[j] != INF) {
					// for all pos >= pos[j] + 1, val < j, cmin(ndpl[val], dpl[j])
					add_event(pos[j] + 1, 0, j, 0, dpl[j]);
					// for all pos >= pos[j] + i, val > dpl[j], cmax(ndpr[val], j)
					add_event(pos[j] + i, dpl[j] + 1, n, 1, j);
				}
				if(dpr[j] != -INF) {
					// for all pos >= pos[j] + 1, val > j, cmax(ndpr[val], dpr[j])
					add_event(pos[j] + 1, j + 1, n, 1, dpr[j]);
					// for all pos >= pos[j] + i, val < dpr[j], cmin(ndpl[val], j)	
					add_event(pos[j] + i, 0, dpr[j], 0, j);
				}
			}
			Seg segl(n), segr(n);
			for(int j = 0; j < n; j++) {
				for(auto e:ev[j]) {
					int l = e[0], r = e[1], val = e[3];
					if(e[2] == 0) { // dpl min with 
						segl.upd(l, r, val);
					} else { // dpr max with
						segr.upd(l, r, -val);
					}
				}
				dpl[a[j]] = segl.qry(a[j]);
				dpr[a[j]] = -segr.qry(a[j]);
			}
			if(!yes) break;
			ans = i;
		}
		return ans;
	};
	int ans = 0;

	dpl = vi(n, INF), dpr = vi(n, -INF);
	dpr[a[0]] = dpl[a[0]] = a[0];
	cmax(ans, go(1));

	dpl = vi(n, INF), dpr = vi(n, -INF);
	for(int i = 0; i < n; i++)
		dpl[i] = dpr[i] = i;
	cmax(ans, go(2) - 1);

	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}