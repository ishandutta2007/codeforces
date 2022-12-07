//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 200100;
int n, q, x[maxn], y[maxn], fa[maxn][18], dfn[maxn], dp[maxn], tt, end[maxn], m, is[maxn];
ll fg[maxn][2];
int a[maxn], fath[maxn];
vector<int> g[maxn], v, f[maxn];

void dfs(int x){
	for(int i = 1; fa[x][i - 1]; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	dfn[x] = ++tt;
	dp[x] = dp[fa[x][0]] + 1;
	for(int i = 0; i < (int)g[x].size(); i++)
		if(g[x][i] != fa[x][0]){
			fa[g[x][i]][0] = x;
			dfs(g[x][i]);
		}
	end[x] = tt;
}

bool cmp(int a, int b) { return dfn[a] < dfn[b]; }

int lca(int x, int y){
	if(dp[x] > dp[y]) swap(x, y);
	ROF(i, 16, 0) if(dp[fa[y][i]] >= dp[x]) y = fa[y][i];
	if(x == y) return x;
	ROF(i, 16, 0) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void DFS(int x){
	is[x] = 0;
	fg[x][0] = fg[x][1] = 0;
	if(a[lower_bound(a + 1, a + m + 1, v[x]) - a] == v[x]) is[x] = 1, fg[x][0] = 1000000;
	ll t0 = 0, t1 = 0, tn = 0;
	for(int i = 0; i < (int)f[x].size(); i++){
		DFS(f[x][i]);
		int f0 = fg[f[x][i]][0], f1 = fg[f[x][i]][1];
		if(is[x]) fg[x][1] += min(f0,  f1 + ((is[f[x][i]] && dp[v[f[x][i]]] - dp[v[x]] == 1) ? 1000000 : 1));
		else{
			t1 = min(t0 + f1, t1 + f0);
			t0 += f0;
			tn += min(f0, f1);
		}
	}
	if(!is[x]) fg[x][0] = min(t0, tn + 1), fg[x][1] = min(t1, t0);
	fg[x][0] = min(fg[x][0], 1000000LL);
	fg[x][1] = min(fg[x][1], 1000000LL);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i, 1, n - 1){
		scanf("%d%d", &x[i], &y[i]);
		g[x[i]].pb(y[i]);
		g[y[i]].pb(x[i]);
	}
	dfs(1);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &m);
		v.clear();
		FOR(i, 1, m) scanf("%d", a + i), v.pb(a[i]);
		sort(a + 1, a + m + 1); a[m + 1] = 0;
		sort(v.begin(), v.end(), cmp);
		FOR(i, 1, m - 1) v.pb(lca(v[i - 1], v[i]));
		sort(v.begin(), v.end(), cmp);
		v.resize(unique(v.begin(), v.end()) - v.begin());
		int N = (int)v.size() - 1;
		f[0].clear();
		FOR(i, 1, N){
			int j = i - 1; f[i].clear();
			while(dfn[v[i]] > end[v[j]]) j = fath[j];
			fath[i] = j;
			f[j].pb(i);
		}
		DFS(0);
		int ans = min(fg[0][0], fg[0][1]);
		if(ans <= n) printf("%d\n", ans);
		else printf("-1\n");
	}
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/