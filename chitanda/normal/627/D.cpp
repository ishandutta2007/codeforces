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

const int maxn = 200010;
int n, k, x, y;
int ok[maxn], size[maxn], f[maxn], a[maxn];
bool up[maxn], ck;
vector<int> g[maxn];

void dfs(int x, int fa, int m){
	ok[x] = a[x] >= m; size[x] = 1;
	for(int i = 0, v; i < (int)g[x].size(); i++)
		if((v = g[x][i]) != fa){
			dfs(v, x, m);
			size[x] += size[v];
			ok[x] += ok[v];
		}
}

void DFS(int x, int fa, int m){
	int tt = 0, t1 = 0, t2 = 0;
	for(int i = 0, v; i < (int)g[x].size(); i++)
		if((v = g[x][i]) != fa){
			if(up[x] && ok[x] - ok[v] == size[x] - size[v]) up[v] = 1;
			DFS(v, x, m);
			if(a[x] < m) continue;
			if(size[v] == ok[v]) tt += ok[v];
			else{
				if(f[v] > t1) t2 = t1, t1 = f[v];
				else if(f[v] > t2) t2 = f[v];
			}
		}
	if(a[x] < m) return;
	if(tt + t1 + t2 + up[x] * (n - size[x]) + 1 >= k) ck = 1;
	f[x] = tt + t1 + 1;
}

int check(int m){
	memset(ok, 0, sizeof(ok));
	memset(up, 0, sizeof(up));
	memset(f, 0, sizeof(f));
	ck = 0;
	dfs(1, 0, m);
	up[1] = a[1] >= m;
	DFS(1, 0, m);
	return ck;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k;
	FOR(i, 1, n) scanf("%d", a + i);
	FOR(i, 2, n){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	int l = 1, r = 1000001;
	while(r - l > 1){
		int m = (l + r) >> 1;
		if(check(m)) l = m; else r = m;
	}
	cout << l;
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