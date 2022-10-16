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

/* 
 * reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
 * verification: https://judge.yosupo.jp/submission/77860
 */
struct line {
	mutable ll m, b, p;
	bool operator < (const line& l) const { return m < l.m; }
	bool operator < (ll x) const { return p < x; }
	ll operator () (ll x) { return m * x + b; }
};

struct CHT : multiset<line, less<>> {
	// (for doubles, use oo = 1/.0, div(a,b) = a/b)
	static const ll oo = LLONG_MAX;
	ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // floored
	// updates x->p, determines if y is useless
	bool isect(iterator x, iterator y) {
		if(y == end()) { x -> p = oo; return false; }
		if(x -> m == y -> m) x -> p = x -> b > y -> b ? oo : -oo;
		else x -> p = div(y -> b - x -> b, x -> m - y -> m);
		return x -> p >= y -> p;
	}
	void add(ll m, ll b) {
		auto z = insert({m, b, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x) -> p >= y -> p) isect(x, erase(y));
	}
	ll qry(ll x) {
		if(empty()) throw;
		auto l = *lower_bound(x);
		return l(x);
	}
};

const int N = 1e5 + 7;

int a[N], b[N];
ll dp[N];
vi G[N];

CHT dfs(int u, int p = 0) {
	CHT hull;
	for(int v:G[u]) if(v != p) {
		auto tt = dfs(v, u);
		if(SZ(tt) > SZ(hull)) swap(tt, hull);
		for(auto [m, b, _] : tt)
			hull.add(m, b);
	}
	if(hull.size()) {
		dp[u] = -hull.qry(a[u]);
	}
	hull.add(-b[u], -dp[u]);
	return hull;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << dp[i] << " \n"[i == n];

}