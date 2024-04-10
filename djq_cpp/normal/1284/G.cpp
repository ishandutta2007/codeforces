#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
char gr[25][25];
int v, t, ans;
bool hv[1005], bg[1005], ed[1005];
int hdr[1005], to[1000005], nxt[1000005], cnt;
void add_edge(int a, int b)
{
	to[cnt] = b; nxt[cnt] = hdr[a];
	hdr[a] = cnt ++;
}

vector<PII> G[1005];
int col[1005], vid[25][25], did[25][25], rid[25][25], eu[1005], ev[1005];

bool ct[1005];

bool vis[1005];
int pv[1005], pe[1005], dep[1005], rt[1005];
int root(int x)
{
	return x == rt[x] ? x : rt[x] = root(rt[x]);
}
void dfs(int x)
{
	vis[x] = true;
	rep(i, G[x].size()) if(!hv[G[x][i].second]) {
		int u = G[x][i].first;
		if(!vis[u]) {
			pv[u] = x; pe[u] = G[x][i].second; dep[u] = dep[x] + 1;
			dfs(u);
		} else if(dep[u] > dep[x]) {
			for(int j = root(u); j != root(x); j = root(j)) rt[j] = pv[j];
		}
	}
}

int que[1005], fr, rr, pre[1005];
bool inc()
{
	cnt = 0;
	rep(i, t) {
		bg[i] = ed[i] = false;
		hdr[i] = -1;
	}
	
	rep(i, t) bg[i] = !hv[i];
	rep(i, v) if(col[i]) {
		int sum = 0;
		rep(j, G[i].size()) sum += !hv[G[i][j].second];
		if(sum == 2) {
			rep(j, G[i].size()) if(!hv[G[i][j].second]) {
				bg[G[i][j].second] = false;
				rep(k, G[i].size()) if(hv[G[i][k].second])
				add_edge(G[i][k].second, G[i][j].second);
			}
		}
	}
	
	rep(i, v) {
		vis[i] = false; rt[i] = i;
	}
	dfs(0);
	
	rep(i, t) if(hv[i]) {
		int a = root(eu[i]), b = root(ev[i]);
		while(a != b) {
			if(dep[a] < dep[b]) swap(a, b);
			add_edge(pe[a], i);
			a = root(pv[a]);
		}
	} else if(root(eu[i]) == root(ev[i])) ed[i] = true;
	
	fr = rr = 0;
	rep(i, t) if(bg[i]) {
		que[rr ++] = i; vis[i] = true;
	} else vis[i] = false;
	while(fr < rr) {
		int x = que[fr ++];
		if(ed[x]) {
			while(!bg[x]) {
				hv[x] = !hv[x];
				x = pre[x];
			}
			hv[x] = true;
			return true;
		}
		for(int i = hdr[x]; i != -1; i = nxt[i]) {
			int u = to[i];
			if(!vis[u]) {
				que[rr ++] = u; vis[u] = true;
				pre[u] = x;
			}
		}
	}
	return false;
}


void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", gr[i]);
	
	ans = t = v = 0;
	rep(i, n * m) G[i].clear();
	rep(i, n) rep(j, m) if(gr[i][j] == 'O') {
		col[v] = (i || j) && !((i + j) & 1);
		vid[i][j] = v ++;
	} else vid[i][j] = -1;
	rep(i, n) rep(j, m - 1) if(gr[i][j] == 'O' && gr[i][j + 1] == 'O') {
		eu[t] = vid[i][j]; ev[t] = vid[i][j + 1];
		G[eu[t]].push_back(MP(ev[t], t));
		G[ev[t]].push_back(MP(eu[t], t));
		rid[i][j] = t ++;
	} else rid[i][j] = -1;
	rep(i, n - 1) rep(j, m) if(gr[i][j] == 'O' && gr[i + 1][j] == 'O') {
		eu[t] = vid[i][j]; ev[t] = vid[i + 1][j];
		G[eu[t]].push_back(MP(ev[t], t));
		G[ev[t]].push_back(MP(eu[t], t));
		did[i][j] = t ++;
	} else did[i][j] = -1;
	
	rep(i, v) if(col[i] && G[i].size() <= 1) {
		printf("NO\n"); return;
	}
	
	rep(i, t) hv[i] = false;
	while(inc()) ans ++;
	if(ans < t - v + 1) {
		printf("NO\n"); return;
	}
	printf("YES\n");
	rep(i, n) {
		rep(j, m) {
			putchar(gr[i][j]);
			putchar(j == m - 1 ? '\n' : (rid[i][j] != -1 && !hv[rid[i][j]] ? 'O' : ' '));
		}
		if(i < n - 1) rep(j, m) {
			putchar(did[i][j] != -1 && !hv[did[i][j]] ? 'O' : ' ');
			putchar(j == m - 1 ? '\n' : ' ');
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}