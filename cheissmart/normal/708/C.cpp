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

const int INF = 1e9 + 7, N = 4e5 + 7;

vi G[N];
int sz[N], who[N], down[N], n;
bool ans[N];

void dfs(int u, int p = 0) {
	sz[u] = 1;
	int mx = 0;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		sz[u] += sz[v];
		down[u] = max(down[u], down[v]);
		if(sz[v] > mx) who[u] = v, mx = sz[v];
	}
	if(n - sz[u] > mx) {
		mx = n - sz[u];
		who[u] = p;
	}
	if(mx * 2 <= n) ans[u] = 1;
	if(sz[u] * 2 <= n)
		down[u] = sz[u];
}

void dfs2(int u, int p = 0, int up = 0) {
	if(ans[u] == 0) {
		if(who[u] == p) {
			if((n - sz[u] - up) * 2 <= n)
				ans[u] = 1;
		} else {
			if((sz[who[u]] - down[who[u]]) * 2 <= n)
				ans[u] = 1;
		}
	}
	vi c, smx;
	for(int v:G[u]) if(v != p) {
		c.PB(v);
		smx.PB(down[v]);
	}
	for(int i = SZ(smx) - 2; i >= 0; i--)
		smx[i] = max(smx[i], smx[i + 1]);
	int pmx = 0;
	for(int i = 0; i < SZ(c); i++) {
		int new_up = up;
		if((n - sz[c[i]]) * 2 <= n)
			new_up = max(new_up, n - sz[c[i]]);
		new_up = max(new_up, pmx);
		if(i + 1 < SZ(c)) new_up = max(new_up, smx[i + 1]);
		dfs2(c[i], u, new_up);
		pmx = max(pmx, down[c[i]]);
	}
}

signed main()
{
	IO_OP;

	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	dfs2(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];

}