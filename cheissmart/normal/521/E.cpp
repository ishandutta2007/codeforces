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

vi G[N];
bool vis[N];
int d[N], p[N];
pi mark[N];

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	while(d[v] > d[u]) v = p[v];
	while(u != v) u = p[u], v = p[v];
	return u;
}

void print(vi& path) {
	cout << SZ(path);
	for(int v:path) cout << " " << v ;
	cout << '\n';
}

vi walk(int u, int v) {
	vi path;
	while(u != v) path.PB(u), u = p[u];
	path.PB(v);
	return path;
}

void gogo(int u1, int v1, int u2, int v2) {
	int x = lca(u1, u2), y = d[v1] < d[v2] ? v2 : v1;
	vi path1 = walk(u1, v1), path2 = walk(u2, v2), path3 = walk(x, y);
	reverse(ALL(path3));
	auto fix = [&] (vi& cycle) {
		rotate(cycle.begin(), find(ALL(cycle), path3[0]), cycle.end());
		cycle.PB(-1);
		cycle.erase(find(ALL(cycle), path3.back()) + 1, cycle.end());
	};
	fix(path1), fix(path2);
	cout << "YES\n";
	print(path1), print(path2), print(path3);
	exit(0);
}

void dfs(int u, int pa = 0) {
	p[u] = pa;
	vis[u] = true;
	for(int v:G[u]) if(v != pa) {
		if(!vis[v]) {
			d[v] = d[u] + 1;
			dfs(v, u);
		} else if(d[v] < d[u]) {
			int k = u;
			while(k != v) {
				if(mark[k] == MP(0, 0))
					mark[k] = {u, v};
				else
					gogo(u, v, mark[k].F, mark[k].S);
				k = p[k];
			}
		}
	}
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	for(int i = 1; i <= n; i++) if(!vis[i])
		dfs(i);

	cout << "NO\n";
}