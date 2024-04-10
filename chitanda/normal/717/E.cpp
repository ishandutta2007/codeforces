//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;

int n, u, v;
int a[200100], f[200100];
vector<int> g[200100];
vector<int> ans;

void dfs(int t, int fa){
	for(auto v : g[t])
		if(v != fa){
			dfs(v, t);
			if(a[v] == 1) f[v] = 2;
			else f[v] = 1, a[t] = -a[t];
		}
}

void DFS(int t, int fa){
	for(auto v : g[t])
		if(v != fa){
			if(f[v] == 2) ans.pb(v), ans.pb(t);
			ans.pb(v);
			DFS(v, t);
			ans.pb(t);
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	bool flag = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(a[i] == -1) flag = 1;
	}
	if(!flag) { printf("1"); return 0; }
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	ans.pb(1);
	DFS(1, 0);
	if(a[1] == -1) ans.pop_back();
	for(auto v : ans) printf("%d ", v);
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