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

const int maxn = 100100;
int n, m, x, y, fa[maxn][18], size[maxn], dp[maxn];
double up[maxn], down[maxn];
vector<int> g[maxn];

void dfs(int x){
	size[x] = 1; dp[x] = dp[fa[x][0]] + 1;
	for(int i = 1; fa[x][i - 1]; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int i = 0; i < (int)g[x].size(); i++)
		if(g[x][i] != fa[x][0]){
			int v = g[x][i];
			fa[v][0] = x;
			dfs(v);
			size[x] += size[v];
			down[x] += (size[v] - 1) * down[v];
		}
	if(size[x] > 1) down[x] = down[x] / (size[x] - 1) + 1;
}

void DFS(int x){
	for(int i = 0; i < (int)g[x].size(); i++)
		if(g[x][i] != fa[x][0]){
			int v = g[x][i];
			up[v] = ((n - size[x]) * up[x] + down[x] * (size[x] - 1) - (size[v] - 1) * down[v] - size[v]) / (n - size[v]) + 1;
			DFS(v);
		}
}

int lca(int x, int y){
	ROF(i, 16, 0) if(dp[fa[y][i]] >= dp[x]) y = fa[y][i];
	if(x == y) return x;
	ROF(i, 16, 0) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	DFS(1);
	FOR(i, 1, m){
		scanf("%d%d", &x, &y);
		if(dp[x] > dp[y]) swap(x, y);
		int z = lca(x, y); double ans;
		if(z == x){
			int xx = y; ROF(i, 16, 0) if(dp[fa[xx][i]] > dp[x]) xx = fa[xx][i];
			ans = dp[y] - dp[x] + down[y] * (size[y] - 1) / size[y] + up[xx];
		}else	ans = dp[x] + dp[y] - 2 * dp[z] + down[x] * (size[x] - 1) / size[x] + down[y] * (size[y] - 1) / size[y] + 1;
		printf("%.8f\n", ans);
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