#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, p[20005], q[20005], vt[20005];
vector<int> T[100005];
int pre[100005][20], dep[100005];
int ver[100005][20], cnt;

void dfs(int v, int par)
{
	dep[v] = dep[par] + 1;
	pre[v][0] = par;
	rep1(i, 16) pre[v][i] = pre[pre[v][i - 1]][i - 1];
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == par) continue;
		dfs(u, v);
	}
}

int hdr[9000005], nxt[54000005], eto[54000005], ecnt;
void add_edge(int ru, int rv)
{
	nxt[ecnt] = hdr[ru];
	eto[ecnt] = rv;
	hdr[ru] = ecnt ++;
}
void add_edge(int u, int v, int wu, int wv)
{
	add_edge(u << 1 | !wu, v << 1 | wv);
	add_edge(v << 1 | !wv, u << 1 | wu);
}

void add_unite(int u, int& v)
{
	if(u == -1) return;
	else if(v == -1) {
		add_edge(u, cnt, 0, 1);
		v = cnt ++;
	} else {
		add_edge(u, v, 0, 0);
		add_edge(u, cnt, 0, 1);
		add_edge(v, cnt, 0, 1);
		v = cnt ++;
	}
}

void gpath(int v, int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 16; i >= 0; i --) if((dep[x] - dep[y]) >> i) {
		add_unite(v, ver[x][i]); x = pre[x][i];
	}
	if(x == y) return;
	for(int i = 16; i >= 0; i --) if(pre[x][i] != pre[y][i]) {
		add_unite(v, ver[x][i]); x = pre[x][i];
		add_unite(v, ver[y][i]); y = pre[y][i];
	}
	add_unite(v, ver[x][0]); add_unite(v, ver[y][0]);
}

int ans[9000005];
int vis[9000005], dfn[9000005], mind[9000005], tot;
bool ins[9000005];
int sta[9000005], tim[9000005], siz;
bool dfs1(int v)
{
	vis[v] = 1;
	sta[siz ++] = v;
	ins[v] = true;
	mind[v] = dfn[v] = tot ++;
	for(int i = hdr[v]; i != -1; i = nxt[i]) {
		int u = eto[i];
		if(!vis[u]) {
			if(!dfs1(u)) return false;
			mind[v] = min(mind[v], mind[u]);
		} else if(vis[u] == 1) mind[v] = min(mind[v], dfn[u]);
		else if(ins[u]) mind[v] = min(mind[v], mind[u]);
	}
	if(mind[v] == dfn[v]) {
		do {
			siz --; ins[sta[siz]] = false;
			if(ans[sta[siz] >> 1] == -1) {
				ans[sta[siz] >> 1] = sta[siz] & 1;
				tim[sta[siz] >> 1] = ~v;
			} else if(tim[sta[siz] >> 1] == ~v) return false;
		} while(sta[siz] != v);
	}
	vis[v] = -1;
	return true;
}

bool solve()
{
	rep(i, cnt) ans[i] = -1;
	rep(i, 2 * cnt) if(!vis[i] && !dfs1(i)) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1, 0);
	
	scanf("%d", &m);
	rep(i, m) scanf("%d%d%d%d", &p[i << 1], &q[i << 1], &p[i << 1 | 1] ,&q[i << 1 | 1]);
	
	rep(i, n + 1) rep(j, 17) ver[i][j] = -1;
	memset(hdr, -1, sizeof(hdr));
	
	rep(i, m) {
		vt[i << 1] = cnt ++; vt[i << 1 | 1] = cnt ++;
		add_edge(vt[i << 1], vt[i << 1 | 1], 1, 1);
	}
	
	rep(i, m) {
		gpath(vt[i << 1], p[i << 1], q[i << 1]);
		gpath(vt[i << 1 | 1], p[i << 1 | 1], q[i << 1 | 1]);
	}
	
	for(int i = 16; i >= 1; i --) rep(j, n + 1) {
		add_unite(ver[j][i], ver[j][i - 1]);
		add_unite(ver[j][i], ver[pre[j][i - 1]][i - 1]);
	}
	
	if(solve()) {
		printf("YES\n");
		rep(i, m) if(ans[vt[i << 1]]) printf("1\n");
		else printf("2\n");
	} else printf("NO\n");
	return 0;
}