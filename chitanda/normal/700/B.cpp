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
#define clean(a) memset(a, 0, sizeof(a))

const int maxn = 200100;
int n, k, root, w[maxn], size[maxn];
ll len[maxn];
vector<int> g[maxn];

void dfs(int t, int fa){
	size[t] = w[t];
	bool flag = 1;
	for(auto v : g[t])
		if(v != fa){
			dfs(v, t);
			size[t] += size[v];
			if(size[v] > k) flag = 0;
		}
	if(2 * k - size[t] > k) flag = 0;
	if(flag) root = t;
}

void DFS(int t, int fa){
	size[t] = w[t];
	for(auto v : g[t])
		if(v != fa){
			DFS(v, t);
			size[t] += size[v];
			len[t] += len[v] + size[v];
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= 2 * k; ++i){
		int u;
		scanf("%d", &u);
		w[u]++;
	}
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	dfs(1, 0);
	DFS(root, 0);
	printf("%lld\n", len[root]);
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