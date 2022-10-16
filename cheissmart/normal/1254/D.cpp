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
 
const int INF = 1e9 + 7, N = 150005, M = 998244353, K = 350;
 
int mul(int a, int b) {
	return int(1LL * a * b % M);
}
 
int inv(int i) {
	if(i == 1) return 1;
	return M - int(mul(M / i, inv(M % i)));
}
 
void sadd(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int madd(int a, int b) {
	sadd(a, b);
	return a;
}

vi G[N], g[N * 2];
int sz[N];
int new_node = 0;
 
void dfs(int u, int p = 0) {
	sz[u] = 1;
	map<int, int> mp;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		sz[u] += sz[v];
		if(mp.count(sz[v]) == 0) {
			mp[sz[v]] = new_node;
			g[u].PB(new_node++);
		}
		g[mp[sz[v]]].PB(v);
	}
}
 
int tin[N * 2], tout[N * 2], tt, top[N * 2], SZ[N * 2], p[N * 2];
 
void dfs_sz(int u) {
	SZ[u] = 1;
	for(int i = 0; i < int(g[u].size()); i++) {
		int v = g[u][i];
		p[v] = u;
		dfs_sz(v);
		SZ[u] += SZ[v];
		if(SZ[v] > SZ[g[u][0]])
			swap(g[u][0], g[u][i]);
	}
}

void dfs_hld(int u) {
	tin[u] = tt++;
	for(int i = 0; i < int(g[u].size()); i++) {
		int v = g[u][i];
		if(i == 0) top[v] = top[u];
		else top[v] = v;
		dfs_hld(v);
	}
	tout[u] = tt;
}

int val[N * 2], block[N * 2 / K + 1];

void add(int pos, int x) {
	sadd(val[pos], x);
	sadd(block[pos / K], x);
}

int qry(int l, int r) { // [l, r]
	if(l / K == r / K) {
		int res = 0;
		for(int i = l; i <= r; i++)
			sadd(res, val[i]);
		return res;
	}
	int res = 0;
	while(l % K != 0)
		sadd(res, val[l++]);
	while(r % K != K - 1)
		sadd(res, val[r--]);
	for(int b = l / K; b <= r / K; b++)
		sadd(res, block[b]);
	return res;
}

int qry(int u) {
	if(top[u] == 1)
		return qry(0, tin[u]);
	return madd(qry(p[top[u]]), qry(tin[top[u]], tin[u]));
}
 
int self[N];

signed main()
{
	IO_OP;
 
	int n, q;
	cin >> n >> q;
	new_node = n + 1;
 
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
 
	dfs(1);
	dfs_sz(1);
	top[1] = 1;
	dfs_hld(1);
 
	int invn = inv(n);
 
	while(q--) {
		int op, v;
		cin >> op >> v;
		if(op == 1) {
			int d;
			cin >> d;
			int x = mul(mul(d, sz[v]), invn);
			add(tin[1], x);
			add(tin[v], M - x);
			sadd(self[v], d);
			for(int u:g[v]) {
				assert(u > n);
				assert(g[u].size());
				int size = sz[g[u][0]];
				add(tin[u], mul(mul(d, n - size), invn));
			}
		} else {
			cout << madd(qry(v), self[v]) << '\n';
		}
	}
 
}