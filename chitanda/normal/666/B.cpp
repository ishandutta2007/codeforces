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

const int maxn = 3010, oo = 1e6;
int n, m, u, v, ans, a, b, c, d;
bool vis[maxn];
vector<int> g[maxn];
int dist[maxn][maxn];
vector<pair<int, int> > ft[maxn], gt[maxn];

void spfa(int S){
	dist[S][S] = 0;
	queue<int> q;
	q.push(S);
	memset(vis, 0, sizeof(vis));
	vis[S] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(auto v : g[t])
			if(dist[S][t] + 1 < dist[S][v]){
				dist[S][v] = dist[S][t] + 1;
				if(!vis[v]){
					q.push(v);
					vis[v] = 1;
				}
			}
		vis[t] = 0;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
	}
	memset(dist, 127, sizeof(dist));
	for(int i = 1; i <= n; i++) spfa(i);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j != i && dist[j][i] < oo) ft[i].pb(mkp(dist[j][i], j));
			if(j != i && dist[i][j] < oo) gt[i].pb(mkp(dist[i][j], j));
		}
		sort(all(ft[i]));
		reverse(all(ft[i]));
		sort(all(gt[i]));
		reverse(all(gt[i]));
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j && dist[i][j] < oo)
				for(int k = 0; k < 3 && k < ft[i].size(); k++) 
					for(int l = 0; l < 3 && l < gt[j].size(); l++)
						if(ft[i][k].se != j && gt[j][l].se != i && ft[i][k].se != gt[j][l].se){
							int dis = ft[i][k].fi + dist[i][j] + gt[j][l].fi;
							if(dis > ans){
								ans = dis;
								a = ft[i][k].se;
								b = i;
								c = j;
								d = gt[j][l].se;
							}
						}
	printf("%d %d %d %d\n", a, b, c, d);
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