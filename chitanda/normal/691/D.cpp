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

const int maxn = 1000100;
int n, m, per[maxn], a[maxn], b[maxn], ans[maxn], vis[maxn];
vector<int> g[maxn];
vector<int> p, q;

void dfs(int t){
	vis[t] = 1;
	p.pb(t), q.pb(per[t]);
	for(auto v : g[t])
		if(!vis[v]) dfs(v);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", per + i);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", a + i, b + i);
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			p.clear();
			q.clear();
			dfs(i);
			sort(all(p));
			sort(all(q));
			reverse(all(q));
			for(int i = 0; i < p.size(); ++i)
				ans[p[i]] = q[i];
		}
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
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