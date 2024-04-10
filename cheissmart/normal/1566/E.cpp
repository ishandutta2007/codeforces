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

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];
int d[N], pa[N], dead[N];

void dfs(int u, int p = 0, int depth = 0) {
	d[u] = depth;
	pa[u] = p;
	auto it = find(ALL(G[u]), p);
	if(it != G[u].end())
		G[u].erase(it);
	for(int v:G[u]) {
		dfs(v, u, depth + 1);
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	vi p(n);
	iota(ALL(p), 1);
	sort(ALL(p), [&] (int a, int b) {
		return d[a] > d[b];
	});
	int ans = 0;
	for(int u:p) if(!dead[u]) {
		if(u == 1) {
			ans++;
			break;
		}
		int v = pa[u];
		if(v == 1) {
			for(int w:G[v]) if(!dead[w]) {
				ans++;
			}
			break;
		} else {
			ans--;
			for(int w:G[v]) if(!dead[w]) {
				dead[w] = 1;
				ans++;
			}
			dead[v] = 1;
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) {
		G[i].clear();
		dead[i] = 0;
	}
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