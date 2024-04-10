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

const int INF = 1e9 + 7, N = 2e5 + 7, Q = 5e4 + 7;

namespace bit {
	int bit[N];
	V<pi> undo;
	void add(int pos, int val, bool yes = true) {
		assert(pos > 0);
		if(yes) undo.EB(pos, val);
		for(; pos < N; pos += pos & -pos)
			bit[pos] += val;
	}
	int qry(int pos) {
		int res = 0;
		for(; pos; pos -= pos & -pos)
			res += bit[pos];
		return res;
	}
	void clear() {
		for(auto [pos, val] : undo)
			add(pos, -val, false);
		undo.clear();
	}
}

int a[N];
ll ans[N];
V<array<int, 3>> ql[Q]; // pos < e[0], val > e[1], op: e[2]
V<array<int, 3>> qr[Q]; // pos > e[0], val < e[1], op: e[2]
V<array<int, 3>> upd[Q]; // pos, val, op

void solve(int l, int r) {
	if(r - l == 1) {
		sort(ALL(ql[l])), sort(ALL(qr[l])), sort(ALL(upd[l]));
		return;
	}
	int m = (l + r) / 2;
	solve(l, m), solve(m, r);
	auto cal_ql = [&] (V<array<int, 3>>& q, V<array<int, 3>>& u) {
		for(int i = 0, j = 0; i < int(q.size()); i++) {
			while(j < int(u.size()) && u[j][0] < q[i][0]) {
				bit::add(u[j][1], u[j][2]);
				j++;
			}
			int qq = bit::qry(N - 1) - bit::qry(q[i][1]);
			if(q[i][2] > 0)
				ans[q[i][2]] += qq;
			else
				ans[-q[i][2]] -= qq;
		}
		bit::clear();
	};
	auto cal_qr = [&] (V<array<int, 3>>& q, V<array<int, 3>>& u) {
		for(int i = int(q.size()) - 1, j = int(u.size()) - 1; i >= 0; i--) {
			while(j >= 0 && u[j][0] > q[i][0]) {
				bit::add(u[j][1], u[j][2]);
				j--;
			}
			int qq = bit::qry(q[i][1] - 1);
			if(q[i][2] > 0)
				ans[q[i][2]] += qq;
			else
				ans[-q[i][2]] -= qq;
		}
		bit::clear();
	};
	cal_ql(ql[m], upd[l]);
	cal_qr(qr[m], upd[l]);
	#define MERGE(qq) {\
		V<array<int, 3>> aux(qq[l].size() + qq[m].size());\
		merge(ALL(qq[l]), ALL(qq[m]), aux.begin());\
		swap(aux, qq[l]);\
	}
	MERGE(ql)
	MERGE(qr)
	MERGE(upd)
}

signed main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		a[i] = i;
		upd[0].PB({i, a[i], 1});
	}
	for(int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		if(l > r) swap(l, r);
		auto go = [&] (int l, int r, int op) {
			assert(l < r);
			ql[i].PB({r, a[r], op * i});
			ql[i].PB({l + 1, a[r], -op * i});
			qr[i].PB({l, a[l], op * i});
			qr[i].PB({r - 1, a[l], -op * i});
		};
		if(a[l] < a[r]) ans[i]++;
		else if(a[l] > a[r]) ans[i]--;
		if(l < r) {
			go(l, r, -1);
			upd[i].PB({l, a[l], -1});
			upd[i].PB({r, a[r], -1});
			swap(a[l], a[r]);
			upd[i].PB({l, a[l], 1});
			upd[i].PB({r, a[r], 1});
			go(l, r, 1);
		}
	}

	solve(0, q + 1);

	for(int i = 1; i <= q; i++) {
		ans[i] += ans[i - 1];
		cout << ans[i] << '\n';
	}

}