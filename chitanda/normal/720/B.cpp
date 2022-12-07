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

const int maxn = 310000, maxe = 1000000, oo = 1e9;
int e = 1, inx, vis[maxn], ln[maxn], ht[maxn], l, r, S, T, pp;
int to[maxe], ne[maxe], he[maxn], cap[maxe];

void link(int x, int y, int v){
	to[++e] = y, ne[e] = he[x], he[x] = e, cap[e] = 0;
	to[++e] = x, ne[e] = he[y], he[y] = e, cap[e] = v;
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
	ht[d] = maxn + 1;
	return flow;
}

int dinic(){
	int maxflow = 0;
	while(bfs()) maxflow += dfs(oo, T);
	return maxflow;
}


void init(){
	memset(he, 0, sizeof(he));
	e = 1;
}

bool ins[10010];
vector<pair<int, int> > g[100100];
int tag[100100], used[100100];
int from[10010], ed[10010];

void DFS(int t, int fa){
	ins[t] = 1;
	used[t] = 1;
	for(auto e : g[t]){
		int v = e.fi, i = e.se;
		if(v != fa){
			if(ins[v]){
				int cnt = 1, now = t;
				++pp; link(pp, i, 1); tag[i] ++;
				do{
					link(pp, ed[now], 1);
					tag[ed[now]]++;
					cnt++;
					now = from[now];
				}while(now != v);
				link(S, pp, cnt - 1);
			}else if(!used[v]){
				from[v] = t;
				ed[v] = i;
				DFS(v, t);
			}
		}
	}
	ins[t] = 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	pp = m + m; S = 3 * m + 1, T = S + 1;
	for(int i = 1; i <= m; ++i){
		int u, v, co;
		scanf("%d%d%d", &u, &v, &co);
		link(i, co + m, 1);
		link(i + m, T, 1);
		g[u].pb(mkp(v, i));
		g[v].pb(mkp(u, i));
	}

	DFS(1, 1);
	for(int i = 1; i <= m; ++i)
		if(!tag[i]) link(S, i, 1);

	printf("%d\n", dinic());
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