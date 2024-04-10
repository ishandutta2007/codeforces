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

const int maxn = 200100;
int n, m, S;
int w[maxn], c[maxn], u[maxn], v[maxn], a[maxn], fa[maxn];
bool tag[maxn];
int f[maxn][19], dp[maxn];
pair<int, int> g[maxn][19];
vector<pair<int, int> > gt[maxn];
vector<int> edges;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int t){
	for(int i = 1; f[t][i - 1]; ++i){
		f[t][i] = f[f[t][i - 1]][i - 1];
		g[t][i] = max(g[t][i - 1], g[f[t][i - 1]][i - 1]);
	}
	for(auto e : gt[t]){
		int v = e.fi, p = e.se;
		if(v == f[t][0]) continue;
		dp[v] = dp[t] + 1;
		f[v][0] = t;
		g[v][0] = mkp(w[p], p);
		dfs(v);
	}
}

pair<int, int> work(int u, int v){
	pair<int, int> tmax = mkp(0, 0);
	if(dp[u] > dp[v]) swap(u, v);
	for(int i = 17; i >= 0; --i)
		if(dp[f[v][i]] >= dp[u]) tmax = max(tmax, g[v][i]), v = f[v][i];
	if(u == v) return tmax;
	for(int i = 17; i >= 0; --i)
		if(f[u][i] != f[v][i]){
			tmax = max(tmax, max(g[u][i], g[v][i]));
			u = f[u][i], v = f[v][i];
		}
	tmax = max(tmax, max(g[u][0], g[v][0]));
	return tmax;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%d", w + i);
	for(int i = 1; i <= m; ++i) scanf("%d", c + i);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d", u + i, v + i), a[i] = i;
	scanf("%d", &S);
	sort(a + 1, a + m + 1, [](const int &x, const int &y) { return w[x] < w[y]; });
	
	for(int i = 1; i <= n; ++i) fa[i] = i;
	ll sum = 0; int c_min = -1;
	for(int i = 1; i <= m; ++i){
		int x = u[a[i]], y = v[a[i]];
		int xx = find(x), yy = find(y);
		if(xx != yy){
			gt[x].pb(mkp(y, a[i]));
			gt[y].pb(mkp(x, a[i]));
			fa[xx] = yy;
			sum += w[a[i]];
			if(c_min == -1 || c[a[i]] < c[c_min]) c_min = a[i];
			edges.pb(a[i]);
		}else tag[i] = 1;
	}
	
	dfs(1);
	
	ll ans = sum - S / c[c_min];
	int del = c_min, add = c_min;
	for(int i = 1; i <= m; ++i){
		if(!tag[i]) continue;
	  auto tw = work(u[a[i]], v[a[i]]);
		ll tmp = sum - tw.fi + w[a[i]] - S / c[a[i]];
		if(tmp < ans){
			ans = tmp;
			del = tw.se;
			add = a[i];
		}
	}
	
	printf("%lld\n", ans);
	for(auto v : edges)
		if(v != del) printf("%d %d\n", v, w[v]);
	printf("%d %d\n", add, w[add] - S / c[add]);
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