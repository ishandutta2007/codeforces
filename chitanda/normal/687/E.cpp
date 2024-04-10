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

const int maxn = 5010;
int n, m, top, tot, tim, u[maxn], v[maxn];
int sta[maxn], col[maxn], dfn[maxn], low[maxn];
bool ins[maxn], out[maxn];
vector<int> g[maxn];

void dfs(int t){
	sta[++top] = t; ins[t] = 1;
	dfn[t] = low[t] = ++tim;
	for(auto v : g[t])
		if(!dfn[v]){
			dfs(v);
			ckmin(low[t], low[v]);
		}else if(ins[v]) ckmin(low[t], dfn[v]);
	if(dfn[t] == low[t]){
		col[t] = ++tot;
		while(sta[top] != t) col[sta[top]] = tot, ins[sta[top--]] = 0;
		top--;
	}
}

int bfs(int T, int S){
	queue<int> q;
	vector<int> dis(n + 1, INT_MAX);	
	dis[S] = 1;
	q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(auto v : g[t])
			if(col[v] == col[t] && dis[v] == INT_MAX){
				dis[v] = dis[t] + 1;
				if(v == T) return dis[v];
				q.push(v);
			}
	}
	assert(1);
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", u + i, v + i);
		g[u[i]].pb(v[i]);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) dfs(i);
	for(int i = 1; i <= m; ++i)
		if(col[u[i]] != col[v[i]])
			out[col[u[i]]] = 1;
	vector<int> cyc(tot + 1, INT_MAX);
	for(int i = 1; i <= m; ++i)
		if(!out[col[u[i]]] && col[u[i]] == col[v[i]]){
			ckmin(cyc[col[u[i]]], bfs(u[i], v[i]));
		}
	int ans = n;
	for(int i = 1; i <= tot; ++i)
		if(!out[i]) ans += 1 + (cyc[i] == INT_MAX ? -1 : 998 * cyc[i]);
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