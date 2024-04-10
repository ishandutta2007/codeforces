#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 400005;

void cmax(int& a, int b) {
	a = max(a, b);
}
void cmin(int& a, int b) {
	a = min(a, b);	
}

vi G[N], g[N];

int scc_cnt = 0;
int vis[N], low[N], scc[N], tt = 0;
vi stk;

void dfs(int u) {
	stk.PB(u);
	low[u] = vis[u] = ++tt;
	for(int v:G[u]) {
		if(!vis[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(!scc[v]) {
			low[u] = min(low[u], vis[v]);
		}
	}
	if(low[u] == vis[u]) {
		scc_cnt++;
		int k;
		do {
			k = stk.back(), stk.pop_back();
			scc[k] = scc_cnt;
		} while(k != u);
	}
}

signed main()
{
	IO_OP; 

	int n, m;
	cin >> n >> m;
	V<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	vi b(m);
	for(int i = 0; i < m; i++)
		cin >> b[i];
		
	V<vi> id(n, vi(m, -1)), down(n, vi(m, -1));
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '#') {
				id[i][j] = cnt++;
			}
		}
	}
	
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			if(id[i][j] != -1) down[i][j] = i;
			else if(i + 1 < n) down[i][j] = down[i + 1][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) if(id[i][j] != -1) {
			if(i - 1 >= 0 && id[i - 1][j] != -1)
				G[id[i][j]].PB(id[i - 1][j]);
			if(j + 1 < m && down[i][j + 1] != -1)
				G[id[i][j]].PB(id[down[i][j + 1]][j + 1]);
			if(j - 1 >= 0 && down[i][j - 1] != -1)
				G[id[i][j]].PB(id[down[i][j - 1]][j - 1]);
			if(i + 1 < n && down[i + 1][j] != -1)
				G[id[i][j]].PB(id[down[i + 1][j]][j]);
		}	
	}
	
	for(int i = 0; i < cnt; i++) if(!vis[i])
		dfs(i);

	for(int i = 0; i < cnt; i++)
		for(int j:G[i]) if(scc[i] != scc[j])
			g[scc[i]].PB(scc[j]);
			
	vi mn(scc_cnt + 1, INF), mx(scc_cnt + 1, -INF);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) if(id[i][j] != -1) {
			cmax(mx[scc[id[i][j]]], j);
			cmin(mn[scc[id[i][j]]], j);
		}
	}
	for(int i = scc_cnt; i >= 1; i--) {
		for(int j:g[i]) {
			cmax(mx[j], mx[i]);
			cmin(mn[j], mn[i]);
		}
	}
	
	V<pi> segs;
	for(int j = 0; j < m; j++) {
		int aux = 0;
		for(int i = n - 1; i >= 0; i--) {
			int u = id[i][j];
			if(u == -1) continue;
			aux++;
			if(aux == b[j]) {
				int l = mn[scc[u]], r = mx[scc[u]];
				segs.EB(l, r);
				break;			
			}
		}
	}
	
	sort(ALL(segs));
	reverse(ALL(segs));
	int ans = 0, p = INF;
	for(auto[l, r]:segs) {
		if(r < p) {
			ans++;
			p = l;
		}
	}
	cout << ans << '\n';
}