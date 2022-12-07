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

const int oo = 1e9, maxn = 200, maxe = 2000;
int e = 1, to[maxe], ne[maxe], he[maxn], cap[maxe], cost[maxe];
int d[maxn], vis[maxn], ln[maxn * 5], l, r, S, T, fl[maxn], inx, from[maxn];
int ans;

void link(int x, int y, int v, int c){
	to[++e] = y, ne[e] = he[x], he[x] = e, cap[e] = 0, cost[e] = c;
	to[++e] = x, ne[e] = he[y], he[y] = e, cap[e] = v, cost[e] = -c;
}

bool spfa(){
	memset(d, 127, sizeof(d));
	d[S] = 0, fl[S] = oo;
	for(vis[ln[l = r = 1] = S] = ++inx; l <= r; vis[ln[l++]] = 0){
		for(int j = he[ln[l]]; j; j = ne[j])
			if(cap[j ^ 1] && d[to[j]] > d[ln[l]] + cost[j]){
				d[to[j]] = d[ln[l]] + cost[j];
				fl[to[j]] = min(fl[ln[l]], cap[j ^ 1]);
				from[to[j]] = j;
				if(vis[to[j]] < inx){
					vis[to[j]] = inx;
					ln[++r] = to[j];
				}
			}
	}
	if(d[T] > oo) return 0;
	int f = fl[T]; ans += f * d[T];
	for(int t = T; t != S; t = to[from[t] ^ 1])
		cap[from[t]] += f, cap[from[t] ^ 1] -= f;
	return 1;
}

void init(){
	e = 1;
	memset(he, 0, sizeof(he));
}

int n, m, cnt[maxn], u[maxn], v[maxn], c[maxn], f[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d%d", u + i, v + i, c + i, f + i);
		cnt[u[i]] -= f[i];
		cnt[v[i]] += f[i];
	}
	S = n + 1, T = n + 2;
	for(int i = 1; i <= n; ++i)
		if(cnt[i] > 0) link(S, i, cnt[i], 0);
		else link(i, T, -cnt[i], 0);

	ans = 0;
	link(n, 1, oo, 0);
	for(int i = 1; i <= m; ++i){
		if(f[i] <= c[i]){
			link(u[i], v[i], c[i] - f[i], 1);
			link(u[i], v[i], oo, 2);
			link(v[i], u[i], f[i], 1);
		}else{
			ans += f[i] - c[i];
			link(u[i], v[i], oo, 2);
			link(v[i], u[i], f[i] - c[i], 0);
			link(v[i], u[i], c[i], 1);
		}
	}

	while(spfa());

	printf("%d\n", ans);
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