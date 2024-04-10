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

const int maxn = 300100;
int n, m, x, y, z, a, b, fa[maxn], dfn[maxn], low[maxn], tim;
bool tag[maxn];
vector<pair<int, int> > g[maxn], f[maxn];

inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v){
	int uu = find(u), vv = find(v);
	fa[uu] = vv;
}

void dfs(int t, int fa){
	dfn[t] = low[t] = ++tim;
	for(auto e : g[t])
		if(!dfn[e.fi]){
			dfs(e.fi, t);
			low[t] = min(low[t], low[e.fi]);
			if(low[e.fi] <= dfn[t]) merge(e.fi, t);
		}else if(e.fi != fa) low[t] = min(low[t], dfn[e.fi]);
}

void DFS(int t, int fa, bool flag){
	flag |= tag[t];
	if(find(b) == t) { printf("%s", flag ? "YES" : "NO"); exit(0); }
	for(auto e : f[t])
		if(e.fi != fa) DFS(e.fi, t, flag | e.se);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", &x, &y, &z);
		g[x].pb(mkp(y, z));
		g[y].pb(mkp(x, z));
	}
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) dfs(i, 0);
	for(int i = 1; i <= n; ++i)
		for(auto e : g[i])
			if(find(i) != find(e.fi)) f[find(i)].pb(mkp(find(e.fi), e.se));
			else tag[find(i)] |= e.se;
	DFS(find(a), 0, 0);
	printf("NO");
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