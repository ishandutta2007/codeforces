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

int n, m;
pair<pair<int, int>, pair<int, int> > edge[200100];
vector<pair<int, int> > g[200100];
int fa[200100][20], MAX[200100][20], dp[200100], fath[200100];
ll cost, ans[200100];

int find(int x) { return fath[x] == x ? x : fath[x] = find(fath[x]); }

void dfs(int x){
	for(int i = 1; fa[x][i - 1]; i++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
		MAX[x][i] = max(MAX[x][i - 1], MAX[fa[x][i - 1]][i - 1]);
	}dp[x] = dp[fa[x][0]] + 1;
	for(int i = 0; i < (int)g[x].size(); i++)
		if(g[x][i].fi != fa[x][0]){
			fa[g[x][i].fi][0] = x;
			MAX[g[x][i].fi][0] = g[x][i].se;
			dfs(g[x][i].fi);
		}
}

int lca(int x, int y){
	int ans = 0;
	if(dp[x] > dp[y]) swap(x, y);
	ROF(i, 17, 0)
		if(dp[fa[y][i]] >= dp[x]) ans = max(ans, MAX[y][i]),  y = fa[y][i];
	if(x == y) return ans;
	ROF(i, 17, 0) if(fa[x][i] != fa[y][i]){
		ans = max(ans, max(MAX[x][i], MAX[y][i]));
		x = fa[x][i], y = fa[y][i];
	}
	return max(ans, max(MAX[x][0], MAX[y][0]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, m) scanf("%d%d%d", &edge[i].se.fi, &edge[i].se.se, &edge[i].fi.fi), edge[i].fi.se = i;
	sort(edge + 1, edge + m + 1);
	FOR(i, 1, n) fath[i] = i;
	for(int i = 1; i <= m; i++){
		int x = edge[i].se.fi, y = edge[i].se.se;
		if(find(x) != find(y)){
			fath[fath[x]] = fath[y];
			cost += edge[i].fi.fi;
			g[x].pb(mkp(y, edge[i].fi.fi)), g[y].pb(mkp(x, edge[i].fi.fi));
		}
	}
	dfs(1);
	for(int i = 1; i <= m; i++){
		int x = edge[i].se.fi, y = edge[i].se.se;
		ans[edge[i].fi.se] = cost + edge[i].fi.fi -lca(x, y);
	}
	FOR(i, 1, m) cout << ans[i] << endl;
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