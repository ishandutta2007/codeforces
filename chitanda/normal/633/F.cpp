//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

typedef set<pair<ll, int> > myset;
const int maxn = 100100;
int n, a[maxn], x, y;
ll f[maxn][2], up[maxn], ans;
myset q[maxn];
vector<int> g[maxn];

void dfs(int x, int fa){
	ll t1 = 0, t2 = 0;
	for(int i = 0, v; i < (int)g[x].size(); i++)
		if((v = g[x][i]) != fa){
			dfs(v, x);
			if(f[v][0] > t1) t2 = t1, t1 = f[v][0];
			else if(f[v][0] > t2) t2 = f[v][0];
			f[x][1] = max(f[x][1], f[v][1]);
			q[x].insert(mkp(-f[v][0], v));
		} 
	f[x][0] = t1 + a[x];
	f[x][1] = max(f[x][1], t1 + t2 + a[x]);
}

void DFS(int x, int fa){
	q[x].insert(mkp(-up[x], fa));
	ll t1 = 0, t2 = 0;
	for(int i = 0, v; i < (int)g[x].size(); i++)
		if((v = g[x][i]) != fa){
			q[x].erase(mkp(-f[v][0], v));
			    myset::iterator it = q[x].begin();
			ll cnt = -(*it).fi; it++;
			if(it != q[x].end()) cnt += -(*it).fi;
			ans = max(ans, cnt + a[x] + f[v][1]);
			up[v] = -(*q[x].begin()).fi + a[x];
			q[x].insert(mkp(-f[v][0], v));
			DFS(v, x);
			if(f[v][1] > t1) t2 = t1, t1 = f[v][1];
			else if(f[v][1] > t2) t2 = f[v][1];
		}
	ans = max(ans, t1 + t2);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) scanf("%d", a + i);
	FOR(i, 2, n){
		scanf("%d%d", &x, &y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1, 0);
	DFS(1, 0);
	cout << ans;
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