#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100020
#define M 200200
#define LL long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pll pair<LL, LL>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define ls (i << 1)
#define rs (ls | 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define pii pair<int, int>

int fa[N], sz[N];
vector<int> g[N];

int n, m, q;

int find(int x) {
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
int dp[N][3], G[N], mx[N];
vector<int> d[N];
vector<LL> sum[N];
bool cmp(int i, int j) {
	return i > j;
}
void dfs(int u, int p) {
	for(auto v: g[u]) {
		if(v == p) continue;
		dfs(v, u);
		dp[u][2] = dp[v][0] + 1;
		sort(dp[u], dp[u] + 3, cmp);
	}
}
void dfs2(int u, int p) {
	for(auto v: g[u]) {
		if(v == p) continue;
		int t;
		if(dp[u][0] == dp[v][0] + 1) t = dp[u][1];
		else t = dp[u][0];
		G[v] = max(G[u] + 1, t + 1);
		dfs2(v, u);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		sz[find(v)] += sz[find(u)];
		fa[find(u)] = find(v);
		

	}
	for(int i = 1; i <= n; ++i) {
		if(fa[i] == i) {
			dfs(i, 0);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(fa[i] == i) dfs2(i, 0);
	}
	for(int i = 1; i <= n; ++i) {
		d[i].pb(0);
		sum[i].pb(0);
	}
	for(int i = 1; i <= n; ++i) {
		int x = find(i);
		mx[x] = max(mx[x], max(dp[i][0], G[i]));
		int t = max(dp[i][0], G[i]);
		d[x].pb(t);
		sum[x].pb(0);
	}
	for(int i = 1; i <= n; ++i) {
		sort(d[i].begin(), d[i].end());
		if(fa[i] == i) {
			for(int j = 1; j < sum[i].size(); ++j) {
				sum[i][j] = sum[i][j - 1] + d[i][j];
			}
		}

	}
	map<pii, double> ans;

	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x == y) {
			puts("-1");
			continue;
		}
		if(sz[x] > sz[y]) swap(x, y);
		if(ans.count(mp(x, y))) {
			printf("%.10lf\n", ans[mp(x, y)]);
			continue;
		}
		LL res = 0;
		int k = max(mx[x], mx[y]);
		bool fst = 1;
		for(auto v: d[x])
		{
			if(fst)
			{
				fst = 0;
				continue;
			}
			int p = lower_bound(d[y].begin(), d[y].end(), k - 1 - v) - d[y].begin();
			p = max(p, 1);
			res += sum[y][sum[y].size() - 1] - sum[y][p - 1] + 1LL * (v + 1) * (sum[y].size() - p);
			res += 1LL * (p - 1) * k;
		}
		double res2 = res * 1.0 / sz[x] / sz[y];
		ans[mp(x, y)] = res2;
		printf("%.12lf\n", res2);
	}
	return 0;
}