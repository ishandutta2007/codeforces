#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
PII E[200005];
int rt[200005];
vector<int> T[200005];
int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}
bool unite(int u, int v)
{
	u = root(u); v = root(v);
	if(u == v) return false;
	rt[v] = u;
	return true;
}
int par[200005][18], dep[200005], dat[200005];
void dfs0(int v, int p)
{
	dep[v] = dep[p] + 1;
	par[v][0] = p;
	rep1(i, 17) par[v][i] = par[par[v][i - 1]][i - 1];
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dfs0(u, v);
	}
}
int pp;
int lca(int u, int v)
{
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 17; i >= 0; i --) if(dep[par[u][i]] > dep[v]) u = par[u][i];
	if(dep[u] > dep[v]) {
		pp = u; u = par[u][0];
	}
	if(u == v) return u;
	for(int i = 17; i >= 0; i --) if(par[u][i] != par[v][i]) {
		u = par[u][i]; v = par[v][i];
	}
	pp = u;
	return par[u][0];
}
void dfs1(int v, int p)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dat[u] += dat[v];
		dfs1(u, v);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) scanf("%d%d", &E[i].first, &E[i].second);
	rep1(i, n) rt[i] = i;
	rep(i, m) {
		int u = E[i].first, v = E[i].second;
		if(unite(u, v)) {
			T[u].push_back(v); T[v].push_back(u);
		}
	}
	dfs0(1, 0);
	rep(i, m) {
		int u = E[i].first, v = E[i].second;
		if(dep[u] > dep[v]) swap(u, v);
		if(lca(u, v) != u) {
			dat[u] ++; dat[v] ++;
		} else {
			dat[v] ++; dat[pp] --; dat[1] ++;
		}
	}
	dfs1(1, 0);
	rep1(i, n) putchar(dat[i] == m ? '1' : '0');
	putchar('\n');
	return 0;
}