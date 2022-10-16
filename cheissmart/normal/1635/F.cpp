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

const int INF = 1e9 + 7, N = 3e5 + 7;
const ll oo = 8e18;

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;
	vi x(n), w(n);
	for(int i = 0; i < n; i++)
		cin >> x[i] >> w[i];

	V<vi> ev(n);
	V<V<pi>> qq(n);

	auto add_ev = [&] (int i, int j) { ev[i].PB(j); };

	vi stk;
	for(int i = 0; i < n; i++) {
		while(SZ(stk) && w[stk.back()] >= w[i]) {
			add_ev(stk.back(), i);
			stk.pop_back();
		}
		if(SZ(stk)) add_ev(stk.back(), i);
		stk.PB(i);
	}

	V<ll> ans(q);

	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		qq[l].EB(r, i);
	}

	auto cost = [&] (int i, int j) {
		assert(j > i);
		return 1LL * (x[j] - x[i]) * (w[i] + w[j]);
	};

	V<ll> bit(n, oo);

	auto upd = [&] (int pos, ll val) {
		assert(pos);
		for(; pos < n; pos += pos & -pos)
			bit[pos] = min(bit[pos], val);
	};
	auto qry = [&] (int pos) {
		ll res = oo;
		for(; pos; pos -= pos & -pos)
			res = min(res, bit[pos]);
		return res;
	};

	for(int i = n - 1; i >= 0; i--) {
		for(int j:ev[i])
			upd(j, cost(i, j));
		for(auto[j, qi]:qq[i])
			ans[qi] = qry(j);
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';

}