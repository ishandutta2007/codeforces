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

const int maxn = 200100, maxm = 400100;
int n, m, s, t, ds, dt;
int fa[maxn];
int u[maxm], v[maxm];
int g[maxn][2];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", u + i, v + i);
		if(u[i] > v[i]) swap(u[i], v[i]);
	}
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	if(s > t) swap(s, t), swap(ds, dt);

	vector<int> ans;
	for(int i = 1; i <= m; ++i){
		if(u[i] != s && u[i] != t && v[i] != s && v[i] != t){
			int x = find(u[i]), y = find(v[i]);
			if(x != y){
				fa[x] = y;
				ans.pb(i);
			}
		}
	}

	int flag = 0;
	for(int i = 1; i <= m; ++i){
		if(u[i] == s && v[i] != t){
			g[find(v[i])][0] = i;
		}
		if(v[i] == s && u[i] != t){
			g[find(u[i])][0] = i;
		}
		if(u[i] == t && v[i] != s){
			g[find(v[i])][1] = i;
		}
		if(v[i] == t && u[i] != s){
			g[find(u[i])][1] = i;
		}
		if(u[i] == s && v[i] == t){
			flag = i;
		}
	}

	vector<pair<int, int> > cal;
	for(int i = 1; i <= n; ++i)
		if(find(i) == i && i != s && i != t){
			if(!g[i][0] && !g[i][1]) { printf("No\n"); return 0; }
			if(g[i][0] && !g[i][1]){
				ans.pb(g[i][0]);
				ds--;
			}else if(g[i][1] && !g[i][0]){
				ans.pb(g[i][1]);
				dt--;
			}else{
				cal.pb(mkp(g[i][0], g[i][1]));
			}
		}

	if(cal.empty() && !flag){
		printf("No\n");
		return 0;
	}

	if(cal.size()){
		auto t = *cal.rbegin();
		ans.pb(t.fi), ans.pb(t.se);
		cal.resize(cal.size() - 1);
		ds--, dt--;
	}else ans.pb(flag), ds--, dt--;

	if(ds < 0 || ds < 0 || ds + dt < (int)cal.size()){
		printf("No\n");
		return 0;
	}

	for(auto v : cal)
		if(ds) ans.pb(v.fi), ds--;
		else ans.pb(v.se);

	printf("Yes\n");
	for(auto x : ans) printf("%d %d\n", u[x], v[x]);
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