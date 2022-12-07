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

const int maxn = 200010, oo = 1e9;
int n, b, q, x, y, tot = 1, inx, vis[maxn], ln[maxn], ht[maxn], l, r, S, T;
int to[maxn], he[maxn], ne[maxn], cap[maxn];
pair<int, int> a[maxn];

void link(int u, int v, int c){
	to[++tot] = v, ne[tot] = he[u], he[u] = tot, cap[tot] = 0;
	to[++tot] = u, ne[tot] = he[v], he[v] = tot, cap[tot] = c;
}

bool bfs(){
	for(ln[l = r = 1] = S, vis[S] = ++inx, ht[S] = 1; l <= r; l++)
		for(int j = he[ln[l]]; j; j = ne[j])
			if(vis[to[j]] < inx && cap[j ^ 1]){
				vis[to[j]] = inx, ht[to[j]] = ht[ln[l]] + 1, ln[++r] = to[j];
				if(to[j] == T) return 1;
			}
	return 0;
}

int dfs(int f, int d){
	if(!f || d == S) return f;
	int flow = 0, k;
	for(int j = he[d]; j; j = ne[j])
		if(vis[to[j]] == inx && ht[to[j]] == ht[d] - 1 && (k = dfs(min(f, cap[j]), to[j]))){
			f -= k, flow += k;
			cap[j] -= k, cap[j ^ 1] += k;
			if(!f) return flow;
		}
	ht[d] = maxn;
	return flow;
}

int dinic(){
	int maxflow = 0;
	while(bfs()) maxflow += dfs(oo, T);
	return maxflow;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> b >> q;
	a[++q] = mkp(b, n);
	for(int i = 1; i <= q; i++) scanf("%d%d", &a[i].fi, &a[i].se);
	sort(a + 1, a + q + 1);
	S = q + 6, T = q + 7;
	FOR(i, 1, q){
		if(a[i].se - a[i - 1].se < 0) { printf("unfair"); return 0; }
		link(S, i, a[i].se - a[i - 1].se);
		for(int j = 0; j < 5; j++)
			link(i, q + j + 1, (a[i].fi + 4 - j) / 5 - (a[i - 1].fi + 4 - j) / 5);
	}
	FOR(i, 0, 4) link(q + i + 1, T, n / 5);
	if(dinic() == n) printf("fair");
	else printf("unfair");
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