#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct fwt
{
	int dat[300005];
	void add(int id, int val)
	{
		for(; id <= 300000; id += id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
	int query(int l, int r)
	{
		return l > r ? 0 : query(r) - query(l - 1);
	}
}tre;

int n, m, par[300005], x[300005], y[300005];
vector<int> T[300005];
int dfn[300005], dfo[300005], tot;
void dfs(int v, int p)
{
	dfn[v] = ++ tot;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dfs(u, v);
	}
	dfo[v] = tot;
}

vector<int> hv[300005];

vector<PII> chv[300005];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &par[i]); T[par[i]].push_back(i);
	}
	dfs(1, -1);
	rep(i, m) {
		scanf("%d%d", &x[i], &y[i]);
		if(x[i] == par[y[i]] || y[i] == par[x[i]]) {
			printf("-1\n"); return 0;
		}
		if(dfn[x[i]] > dfn[y[i]]) swap(x[i], y[i]);
		if(dfo[x[i]] >= dfo[y[i]]) hv[dfn[x[i]]].push_back(i);
		else hv[0].push_back(i);
	}
	
	rep1(i, n) {
		rep(j, T[i].size()) chv[i].push_back(MP(dfo[T[i][j]], T[i][j]));
		sort(chv[i].begin(), chv[i].end());
	}
	
	int ans = 0;
	for(int i = n; i >= 1; i --) rep(j, hv[i].size()) {
		int cur = hv[i][j];
		int z = lower_bound(chv[x[cur]].begin(), chv[x[cur]].end(), MP(dfn[y[cur]], -1))->second;
		if(tre.query(dfn[z], dfo[z]) > tre.query(dfn[y[cur]], dfo[y[cur]])) continue;
		tre.add(dfn[z], 1); ans ++;
	}
	rep(i, hv[0].size()) {
		int cur = hv[0][i];
		if(tre.query(dfn[x[cur]], dfo[x[cur]]) + tre.query(dfn[y[cur]], dfo[y[cur]]) == ans) {
			ans ++; break;
		}
	}
	printf("%d\n", ans);
	return 0;
}