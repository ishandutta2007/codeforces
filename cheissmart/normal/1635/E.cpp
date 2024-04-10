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

const int INF = 1e9 + 7, N = 2e5 + 7;

V<pi> G[N];
vi g[N];
int vis[N];

void dfs(int u, int c = 1) {
	vis[u] = c;
	for(int v:g[u]) {
		if(!vis[v]) 
			dfs(v, c ^ 3);
		else if(vis[v] == c) {
			cout << "NO" << '\n';
			exit(0);
		}
	}
}

int x[N], vis2[N];
vi order;

void dfs2(int u) {
	vis2[u] = 1;
	for(auto[v, op] : G[u]) {
		if(vis[u] == op) {
			if(!vis2[v])
				dfs2(v);
			else if(vis2[v] == 1) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
	order.PB(u);
	vis2[u] = 2;
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int op, u, v;
		cin >> op >> u >> v;
		G[u].EB(v, op), G[v].EB(u, op);
		g[u].PB(v), g[v].PB(u);
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		dfs(i);
	}
	// 1 -> left
	// 2 -> right

	for(int i = 1; i <= n; i++) if(vis2[i] == 0) {
		dfs2(i);
	}
	reverse(ALL(order));
	assert(SZ(order) == n);
	for(int i = 0; i < n; i++)
		x[order[i]] = i;
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << "LR"[vis[i] - 1] << " " << x[i] << '\n';

}