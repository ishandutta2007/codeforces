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

const int maxn = 2501;
int n, a[maxn][maxn], d[maxn], from[maxn];
vector<int> g[maxn];
bool xuan[maxn];

void no() { printf("NOT MAGIC"); exit(0); }

void dfs(int start, int t, int fa, int dist){
	if(dist != a[start][t]) no();
	for(int i = 0; i < (int)g[t].size(); i++)
		if(g[t][i] != fa) dfs(start, g[t][i], t, max(dist, a[t][g[t][i]]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) FOR(j, 1, n) scanf("%d", a[i] + j);
	FOR(i, 1, n) if(a[i][i]) no();
	FOR(i, 1, n) FOR(j, 1, n) if(a[i][j] != a[j][i]) no();
	FOR(i, 2, n) d[i] = a[1][i], from[i] = 1; xuan[1] = 1;
	FOR(i, 2, n){
		int k = 0;
		FOR(j, 2, n) if(!xuan[j] && (!k || d[j] < d[k])) k = j;
		xuan[k] = 1;
		g[from[k]].pb(k);
		g[k].pb(from[k]);
		FOR(j, 2, n) if(!xuan[j] && a[k][j] < d[j]) d[j] = a[k][j], from[j] = k;
	}
	FOR(i, 1, n) dfs(i, i, 0, 0);
	printf("MAGIC\n");
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