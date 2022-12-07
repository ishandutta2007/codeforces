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

const int maxn = 400100;
int n, root, u, v;
int size[maxn], top[maxn];
vector<int> g[maxn];

void dfs(int t, int fa){
	size[t] = 1;
	bool flag = 1;
	for(auto&& v : g[t])
		if(v != fa){
			dfs(v, t);
			size[t] += size[v];
			if(size[v] > n / 2) flag = 0;
		}
	if(n - size[t] > n / 2) flag = 0;
	if(flag){
		if(!root) root = t;
		else root = -1;
	}
}

void DFS(int t, int fa, int tp){
	size[t] = 1;
	top[t] = tp;
	for(auto&& v : g[t])
		if(v != fa){
			if(t == root) tp = v;
			DFS(v, t, tp);
			size[t] += size[v];
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}

	dfs(1, 0);
	if(root == -1){
		for(int i = 1; i <= n; ++i) printf("1 ");
	}else{
		DFS(root, 0, 0);
		int t1 = 0, t2 = 0;
		for(auto&& v : g[root]){
			if(size[v] > t1) t2 = t1, t1 = size[v];
			else if(size[v] > t2) t2 = size[v];
		}

		for(int i = 1; i <= n; ++i)
			if(i == root) printf("1 ");
			else{
				int tmp = size[top[i]] == t1 ? t2 : t1;
				if(n - tmp - size[i] > n / 2) printf("0 ");
				else printf("1 ");
			}
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