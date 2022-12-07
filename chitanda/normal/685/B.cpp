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

const int maxn = 300100;
int n, q, p[maxn], x, cen[maxn], size[maxn];
vector<int> g[maxn];

void dfs(int t){
	size[t] = 1;
	int max_son = 0;
	for(auto v : g[t]){
		dfs(v);
		size[t] += size[v];
		if(size[v] > size[max_son]) max_son = v;
	}
	if(!max_son) return(void)(cen[t] = t);
	cen[t] = cen[max_son];
	while(size[t] > size[cen[t]] * 2) cen[t] = p[cen[t]];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++i){
		scanf("%d", p + i);
		g[p[i]].pb(i);
	}
	dfs(1);
	for(int i = 1; i <= q; ++i){
		scanf("%d", &x);
		printf("%d\n", cen[x]);
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