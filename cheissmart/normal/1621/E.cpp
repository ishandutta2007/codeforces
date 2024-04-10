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

const int INF = 1e9 + 7, N = 1e5 + 7;

struct node {
	int mn, lz;
	node() {
		mn = lz = 0;
	}
} t[N * 4];

void apply(int v, int val) {
	t[v].mn += val;
	t[v].lz += val;
}

void push(int v) {
	apply(v * 2, t[v].lz);
	apply(v * 2 + 1, t[v].lz);
	t[v].lz = 0;
}

void pull(int v) {
	t[v].mn = min(t[v * 2].mn, t[v * 2 + 1].mn);
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = N) {
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

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		upd(0, a[i] + 1, 1);
	}
	V<pi> op;
	vi undo;
	for(int i = 0; i < m; i++) {
		int k;
		ll sum = 0;
		cin >> k;
		vi x(k);
		for(int j = 0; j < k; j++) {
			cin >> x[j];
			sum += x[j];
		}
		int old = (sum + k - 1) / k;
		upd(0, old + 1, -1);
		undo.PB(old);
		for(int j = 0; j < k; j++) {
			sum -= x[j];
			int nw = (sum + k - 2) / (k - 1);
			op.EB(old, nw);
			sum += x[j];
		}
	}
	for(auto [x, y]:op) {
		upd(0, x + 1, 1);
		upd(0, y + 1, -1);
		if(t[1].mn >= 0) cout << 1;
		else cout << 0;
		upd(0, x + 1, -1);
		upd(0, y + 1, 1);
	}
	cout << '\n';

	for(int i = 0; i < n; i++)
		upd(0, a[i] + 1, -1);
	for(int x:undo)
		upd(0, x + 1, 1);
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