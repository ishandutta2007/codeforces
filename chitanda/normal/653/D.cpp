//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define eps (1e-10)

const int maxm = 2000, oo = 1000000;
int n, m, x, tot, S, T, inx, a[maxm], b[maxm], c[maxm];
int to[maxm],he[maxm], ne[maxm], cap[maxm], ln[maxm], ht[maxm], l, r;
int vis[maxm];

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
	ht[d] = maxm;
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
	cin >> n >> m >> x;
	FOR(i, 1, m) scanf("%d%d%d", a + i, b + i, c + i);
	double tl = 0, tr = 1000000;
	S = 1, T = n;
	FOR(test, 1, 60){
		double mid = (tl + tr) / 2;
		memset(he, 0, sizeof(he));
		tot = 1;
		FOR(i, 1, m)
			link(a[i], b[i], (int)min(c[i] / mid + eps, x + eps));
		if(dinic() >= x) tl = mid;
		else tr = mid;
	}
	printf("%.10f\n", tl * x);
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