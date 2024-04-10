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

const int INF = 1e9 + 7;
const ll oo = 1e18;

void solve() {
	int n, m, K;
	cin >> n >> m >> K;
	vi x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];

	V<map<int, int>> mp(n);
	int cnt = 0;

	auto get_id = [&] (int u, int v) {
		if(mp[u].count(v)) return mp[u][v];
		return mp[u][v] = cnt++;
	};

	V<array<int, 3>> edges;

	for(int i = 0; i < K; i++) {
		int a, b, c, d, h;
		cin >> a >> b >> c >> d >> h;
		a--, b--, c--, d--;
		int u = get_id(a, b), v = get_id(c, d);
		edges.PB({u, v, h});
	}
	get_id(0, 0);
	get_id(n - 1, m - 1);

	V<V<pi>> G(cnt);
	V<ll> d(cnt, oo);
	d[get_id(0, 0)] = 0;
	for(auto [u, v, h]:edges)
		G[u].EB(v, h);
	for(int i = 0; i < n; i++) {
		auto relax = [&] (int j, int k) {
			if(d[get_id(i, j)] + 1LL * abs(k - j) * x[i] < d[get_id(i, k)]) {
				d[get_id(i, k)] = d[get_id(i, j)] + 1LL * abs(k - j) * x[i];
			}
		};
		vi tt;
		for(auto [j, u]:mp[i]) tt.PB(j);
		for(int j = 1; j < SZ(tt); j++)
			relax(tt[j - 1], tt[j]);
		for(int j = SZ(tt) - 2; j >= 0; j--)
			relax(tt[j + 1], tt[j]);
		for(auto [j, u]:mp[i]) for(auto [v, w]:G[u])
			if(d[u] - w < d[v])
				d[v] = d[u] - w;
	}
	if(d[get_id(n - 1, m - 1)] > ll(1e17))
		cout << "NO ESCAPE" << '\n';
	else
		cout << d[get_id(n - 1, m - 1)] << '\n';
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