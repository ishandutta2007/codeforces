#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 7;

vi G[N];
int p[N][20], d[N];

void dfs(int u, int pa = 0, int depth = 0) {
	p[u][0] = pa;
	d[u] = depth;
	for(int i = 1; i < 20; i++)
		p[u][i] = p[p[u][i - 1]][i - 1];
	for(int v:G[u]) if(v != pa)
		dfs(v, u, depth + 1);
}

int up(int u, int steps) {
	for(int i = 19; i >= 0; i--)
		if(steps >> i & 1)
			u = p[u][i];
	return u;
}

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	for(int i = 19; i >= 0; i--)
		if((d[v] - d[u]) >> i & 1)
			v = p[v][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i--) {
		if(p[v][i] != p[u][i])
			u = p[u][i], v=  p[v][i];
	}
	return p[u][0];
}

unordered_map<int, int> from_ch[N];
map<pi, int> from_ch2[N];
int cnt[N], psum[N], psum2[N];
ll ans = 0;

ll c2(int x) {
	return (ll) x * (x - 1) / 2;
}

void dfs2(int u, int p = 0) {
	for(int v:G[u]) if(v != p) {
		dfs2(v, u);
		psum[u] += psum[v];
		psum2[u] += psum2[v];
	}
	ans += (ll) cnt[u] * psum[u];
	ans -= c2(cnt[u]) + cnt[u];
	for(int v:G[u]) if(v != p) {
		ans -= (ll) from_ch[u][v] * psum2[v];
		ans += c2(from_ch[u][v]) + from_ch[u][v];
	}
	for(auto p:from_ch2[u])
		ans += c2(p.S);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	int m;
	cin >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		int l = lca(u, v);
		cnt[l]++;
		int u_rep = -1, v_rep = -1;
		if(u != l) u_rep = up(u, d[u] - d[l] - 1);
		if(v != l) v_rep = up(v, d[v] - d[l] - 1);
		if(u_rep != -1) from_ch[l][u_rep]++;
		if(v_rep != -1) from_ch[l][v_rep]++;
		if(u_rep != -1 && v_rep != -1) {
			if(u_rep > v_rep) swap(u_rep, v_rep);
			from_ch2[l][{u_rep, v_rep}]++;
		}
		psum[u]++, psum[v]++;
		psum[l]--, psum[p[l][0]]--;
		psum2[u]++, psum2[v]++, psum2[l] -= 2;
	}
	dfs2(1);
	cout << ans << '\n';

}