//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }

const int maxn = 100100;
int n, m, u, v, du[maxn], col[maxn];
vector<int> g[maxn];
vector<int> ans[3];

void dfs(int t, int c){
	if(col[t]){
		if(col[t] == c) return;
		else { printf("-1\n"); exit(0); }
	}
	col[t] = c;
	ans[c].pb(t);
	for(auto v : g[t]){
		dfs(v, 3 - c);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		du[u]++;
		du[v]++;
	}
	for(int i = 1; i <= n; ++i)
		if(du[i] && !col[i]){
			dfs(i, 1);
		}
	for(int t = 1; t <= 2; ++t){
		printf("%d\n", (int)ans[t].size());
		for(auto v : ans[t]) printf("%d ", v);
		printf("\n");
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