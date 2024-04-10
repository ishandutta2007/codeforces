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

int ans, n, x, y;
vector<int> f, g[500100];

void dfs(int t, int fa, int dp){
	if(g[t].size() == 1) f.pb(dp);
	FOR(i, 0, (int)g[t].size() - 1)
		if(g[t][i] != fa) dfs(g[t][i], t, dp + 1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	FOR(i, 0, (int)g[1].size() - 1){
		f.clear();
		dfs(g[1][i], 1, 1);
		sort(f.begin(), f.end());
		FOR(i, 1, (int)f.size() - 1)
			f[i] = max(f[i], f[i - 1] + 1);
		ans = max(ans, f[f.size() - 1]);
	}
	printf("%d\n", ans);
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