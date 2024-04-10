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

const int INF = 1e9 + 7, M = 998244353;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	V<vi> G(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
	}
	vi order;

	V<bool> vis(n);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;
		for(int v:G[u]) if(!vis[v])
			dfs(v);
		order.PB(u);
	};

	for(int i = 0; i < n; i++) if(!vis[i])
		dfs(i);

	vi b = a;

	reverse(ALL(order));
	function<int(int)> go = [&] (int i) {
		if(i == n - 1) return a[order[i]] % M;
		if(!b[order[i]]) return go(i + 1);
		for(int j = n - 1; j >= i; j--) {
			if(b[order[j]]) {
				for(int k:G[order[j]]) {
					add(a[k], 1);
					b[k] = min(b[k] + 1, INF);
				}
				add(a[order[j]], M - 1);
				b[order[j]]--;
			}
		}
		for(int j:G[order[i]]) {
			add(a[j], a[order[i]]);
			b[j] = min(b[j] + b[order[i]], INF);
		}
		return (1 + go(i + 1)) % M;
	};
	cout << go(0) << '\n';
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