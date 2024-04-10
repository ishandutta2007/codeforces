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

const int INF = 1e9 + 7, N = 1e5 + 7;

struct Heap : priority_queue<int> {
	void push(int x) {
		 priority_queue<int>::push(x);
		 if(size() > 10) pop();
	}
	friend Heap operator + (Heap lhs, Heap rhs) {
		while(rhs.size()) lhs.push(rhs.top()), rhs.pop();
		return lhs;
	}
} tt[N][20];

vi G[N];
int p[N][20], d[N];

void dfs(int u, int pa = 0, int depth = 0) {
	d[u] = depth;	
	p[u][0] = pa;
	for(int j = 1; j < 20; j++) {
		p[u][j] = p[p[u][j - 1]][j - 1];
		tt[u][j] = tt[u][j - 1] + tt[p[u][j - 1]][j - 1];
	}
	for(int v:G[u]) if(v != pa)
		dfs(v, u, depth + 1);
}

Heap up(int u, int step) {
	assert(step <= d[u]);
	Heap res;
	for(int i = 19; i >= 0; i--)
		if(step >> i & 1)
			res = res + tt[u][i], u = p[u][i];
	return res;
}

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	assert(d[v] >= d[u]);
	for(int i = 0; i < 19; i++)
		if((d[v] - d[u]) >> i & 1)
			v = p[v][i];
	assert(d[u] == d[v]);
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	assert(p[u][0] == p[v][0]);
	return p[u][0];
}

signed main()
{
	IO_OP;

	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}

	for(int i = 1; i <= m; i++) {
		int u;
		cin >> u;
		tt[u][0].push(i);
	}

	dfs(1);

	while(q--) {
		int u, v, a;
		cin >> u >> v >> a;
		int l = lca(u, v);
		Heap res = up(u, d[u] - d[l]) + up(v, d[v] - d[l]) + tt[l][0];
		while(int(res.size()) > a) res.pop();
		cout << res.size();
		vi ans;
		while(res.size()) ans.PB(res.top()), res.pop();
		while(ans.size()) cout << ' ' << ans.back(), ans.pop_back();
		cout << '\n';
	}

}