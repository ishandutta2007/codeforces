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

int n, m, u, v, ans;
vector<int> g[100100], f;
int a[100100];
bool flag, in[100100];

void dfs(int t){
	for(auto v : g[t]){
		if(a[v] != a[t] && a[v] != v) flag = 0;
		dfs(v);
	}
}

void DFS(int t){
	for(auto v : g[t]){
		DFS(v);
	}
	if(a[t] == t) ans++, f.pb(t);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	flag = 1;
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		in[v] = 1;
	}
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i)
		if(!in[i]) dfs(i);
	if(!flag) { printf("-1"); return 0; }
	for(int i = 1; i <= n; ++i)
		if(!in[i]) DFS(i);
	printf("%d\n", ans);
	for(auto v : f) printf("%d\n", v);
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