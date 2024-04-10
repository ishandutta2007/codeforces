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

const int INF = 1e9 + 7;

int lg(ll x) {
	return 63 - __builtin_clzll(x);
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	V<bool> op(m);
	V<ll> x(m), y(m), cuts({0, 1LL << n});
	for(int i = 0; i < m; i++) {
		string s;
		cin >> s >> x[i] >> y[i];
		if(s == "block") {
			op[i] = 0;
			y[i]++;
			cuts.PB(x[i]);
			cuts.PB(y[i]);
		} else {
			op[i] = 1;
		}
	}

	sort(ALL(cuts));
	cuts.resize(unique(ALL(cuts)) - cuts.begin());

	int N = int(cuts.size()) - 1;
	for(int i = 0; i < N; i++) {
		ll l = cuts[i], r = cuts[i + 1] - 1;
		if(l != r) {
			int k = lg(l ^ r);
			cuts.PB(r >> k << k);
		}
	}

	sort(ALL(cuts));
	cuts.resize(unique(ALL(cuts)) - cuts.begin());


	N = int(cuts.size()) - 1;

	V<vi> G(N);

	auto add_edge = [&] (int i, int j, int k) {
		ll d = 1LL << k;
		ll l1 = cuts[i], r1 = cuts[i + 1] - 1;
		ll l2 = cuts[j], r2 = cuts[j + 1] - 1;
		l1 = max(l1, l2 - d), r1 = min(r1, r2 - d);
		if(l1 > r1) return;
		// check if any number in [l1, r1] has k-th bit = 0
		l1 >>= k, r1 >>= k;
		if(l1 == r1 && l1 % 2 == 1)
			return;
		G[i].PB(j);
		G[j].PB(i);
	};

	for(int k = 0; k < n; k++) {
		ll d = 1LL << k;
		for(int i = 0, j = 0; i < N; i++) {
			while(j < N && cuts[j + 1] - 1 < cuts[i] + d)
				j++;
			while(j < N && cuts[j + 1] - 1 <= cuts[i + 1] - 1 + d) {
				add_edge(i, j, k);
				j++;
			}
			if(j < N)
				add_edge(i, j, k);
		}
	}

	vi p(N), sz(N, 1);
	iota(ALL(p), 0);
	function<int(int)> find = [&] (int u) -> int {
		return p[u] == u ? u : p[u] = find(p[u]);
	};

	auto unite = [&] (int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(sz[x] > sz[y])
			swap(x, y);
		p[x] = y;
		sz[y] += sz[x];
	};

	V<bool> active(N, true);
	for(int i = 0; i < m; i++) if(op[i] == 0) {
		int j = int(lower_bound(ALL(cuts), x[i]) - cuts.begin());
		while(j < N && cuts[j] < y[i]) {
			active[j++] = false;			
		}
	}

	for(int i = 0; i < N; i++) if(active[i])
		for(int j:G[i]) if(active[j])
			unite(i, j);

	V<bool> ans(m);

	for(int i = m - 1; i >= 0; i--) {
		if(op[i] == 0) {
			int j = int(lower_bound(ALL(cuts), x[i]) - cuts.begin());
			while(j < N && cuts[j] < y[i]) {
				assert(!active[j]);
				for(int k:G[j]) if(active[k])
					unite(j, k);
				active[j++] = true;
			}
		} else {
			int u = int(upper_bound(ALL(cuts), x[i]) - cuts.begin()) - 1;
			int v = int(upper_bound(ALL(cuts), y[i]) - cuts.begin()) - 1;
			ans[i] = find(u) == find(v);
		}
	}

	for(int i = 0; i < m; i++) if(op[i])
		cout << ans[i] << '\n';

}