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

const int maxn = 1010, maxm = 30010;
int n, m, s, t, tim;
int u[30010], v[30010], w[30010], uu[maxm], vv[maxm], ww[maxm], wp[maxm], id[maxm];
int fa[1010], use[30010], dfn[maxn], low[maxn];
vector<pair<int, int> > g[maxn];

inline int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	fa[x] = y;
}

void dfs(int t, int fa){
	dfn[t] = low[t] = ++tim;
	for(auto e : g[t]){
		int v = e.fi, id = e.se;
		if(!dfn[v]){
			dfs(v, id);
			low[t] = min(low[t], low[v]);
			//if(low[v] > dfn[t]) isg[id] = 1;
			if(low[v] <= dfn[t]) merge(v, t);
		}else{
			if (id != fa)	low[t] = min(low[t], dfn[v]);
		}
	}
}

bool cmp(int x, int y) { return ww[y] < ww[x]; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) scanf("%d%d%d", uu + i, vv + i, ww + i), wp[i] = i;
	sort(wp + 1, wp + m + 1, cmp);
	for(int i = 1; i <= m; ++i){
		int o = wp[i];
		u[i] = uu[o], v[i] = vv[o], w[i] = ww[o], id[i] = o;
		int x = find(u[i]), y = find(v[i]);
		if(x != y){
			fa[x] = y;
			use[i] = 1;
		}
	}
	if(find(s) != find(t)){
		printf("0\n0");
		return 0;
	}
	int ans = 2e9 + 100; vector<int> res;
	for(int i = 1; i <= m; ++i)
		if(use[i]){
			for(int j = 1; j <= n; ++j) g[j].clear(), fa[j] = j;
			for(int j = 1; j <= m; ++j)
				if(j != i){
					g[u[j]].pb(mkp(v[j], j));
					g[v[j]].pb(mkp(u[j], j));
				}
			tim = 0;
			memset(dfn, 0, sizeof(dfn));
			//memset(isg, 0, sizeof(isg));
			for(int j = 1; j <= n; ++j)
				if(!dfn[j]) dfs(j, 0);
			if(find(s) == find(t)) continue;
			int ta;
			for(int j = 1; j <= m; ++j){
				int x = find(u[j]), y = find(v[j]);
				if(x == y || j == i) continue;
				if(x != y){
					fa[x] = y;
					if(find(s) == find(t)) { ta = j; break; }
				}
			}
			if(find(s) != find(t)){
				if(ckmin(ans, w[i])){
					res.clear(); res.pb(id[i]);
				}
			}else{
				if(ckmin(ans, w[i] + w[ta])){
					res.clear(); res.pb(id[i]), res.pb(id[ta]);
				}
			}
		}
	/*
	if(ans == 17){
		for(int i = 30; i <= m; ++i) printf("%d %d %d\n", u[i], v[i], w[i]);
		return 0;
		}*/
	if(!res.size()){
		printf("-1");
	}else{
		printf("%d\n", ans);
		printf("%d\n", (int)res.size());
		for(auto v : res) printf("%d ", v);
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