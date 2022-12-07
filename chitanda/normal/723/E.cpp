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

const int maxn = 210, maxe = maxn * maxn;
int T, n, m, u, v;
vector<pair<int, int> > g[maxn], ans;
bool used[maxe], du[maxn];


void dfs(int t){
	if(du[t] & 1){
		du[t] ^= 1;
		return;
	}
	for(auto e : g[t])
		if(!used[e.se]){
			ans.pb(mkp(t, e.fi));
			used[e.se] = 1;
			dfs(e.fi);
			break;
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) g[i].clear();
		memset(du, 0, sizeof(du));
		memset(used, 0, sizeof(used));
		
		for(int i = 1; i <= m; ++i){
			scanf("%d%d", &u, &v);
			g[u].pb(mkp(v, i));
			g[v].pb(mkp(u, i));
			du[u] ^= 1;
			du[v] ^= 1;
		}
		int res = n;
		for(int i = 1; i <= n; ++i)
			if(du[i] & 1) res--;
		
		ans.clear();
		while(1){
			int k = 0;
			for(int i = 1; i <= n; ++i)
				if(du[i] & 1) k = i;
			du[k] ^= 1;
			if(!k) break;
			dfs(k);
		}
		for(int i = 1; i <= n; ++i)
			dfs(i);
		printf("%d\n", res);
		for(auto v : ans) printf("%d %d\n", v.fi, v.se);
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