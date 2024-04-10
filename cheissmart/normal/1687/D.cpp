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

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	V<pi> ev;
	for(int i = 1; i < n; i++)
		ev.EB(a[i] - a[i - 1], i);
	sort(ALL(ev), greater<>());

	vi p(n); iota(ALL(p), 0);
	vi mx = p, sz(n, 1);

	function<int(int)> find = [&] (int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	};
	auto unite = [&] (int u, int v) {
		u = find(u), v = find(v);
		assert(u != v);
		if(sz[u] > sz[v]) swap(u, v);
		p[u] = v, sz[v] += sz[u], mx[v] = max(mx[v], mx[u]);
	};

	for(int x = 1; x <= a[n - 1]; x++) {
		if(1LL * x * x + x < a[0]) continue;
		// [x * x, x * x + x]
		ll l = max(0LL, 1LL * x * x - a[0]), r = 1LL * x * x - a[0] + x;
		ll L = l, R = r;

		while(SZ(ev) && ev.back().F < x) {
			unite(ev.back().S - 1, ev.back().S);
			ev.pop_back();
		}

		auto go = [&] (int i, int j) {
			ll he = a[i] + L, be = a[i] + R, y = sqrt(he);
			if(y * y + y < he) y++;
			he = max(he, y * y), be = min(be, y * y + y);
			he -= a[i], be -= a[i];
			l = max(l, he), r = min(r, be);

			he = a[j] + L, be = a[j] + R;
			he = max(he, y * y), be = min(be, y * y + y);
			he -= a[j], be -= a[j];
			l = max(l, he), r = min(r, be);
		};

		for(int i = 1; i < n;) {
			int j = mx[find(i)];
			go(i, j);
			i = j + 1;
		}

		if(l <= r) {
			cout << l << '\n';
			return 0;
		}
	}

}