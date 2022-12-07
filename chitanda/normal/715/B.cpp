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

const int inf = 1e9 + 7;
const int maxn = 1010;
const int maxm = 10100;
int n, m, L, s, t, notSure;
int dis[maxn];
bool vis[maxn];
vector<pair<int, int> > g[maxn];
int u[maxm], v[maxm], w[maxm], lab[maxm];

void spfa(int s){
	queue<int> q; q.push(s);
	//memset(dis, 127, sizeof(dis));
	fill_n(dis, n, inf);
	fill_n(vis, n, 0);
	dis[s] = 0, vis[s] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		vis[t] = 0;
		for(auto e : g[t]){
			int v = e.fi, w = e.se;
			if(dis[t] + w < dis[v]){
				dis[v] = dis[t] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int check(int R, int ch){
	for(int i = 0; i < n; ++i) g[i].clear();
	for(int i = 1; i <= m; ++i){
		if(lab[i] == -1) g[u[i]].pb(mkp(v[i], w[i])), g[v[i]].pb(mkp(u[i], w[i]));
		else if(lab[i] < R) g[u[i]].pb(mkp(v[i], 1)), g[v[i]].pb(mkp(u[i], 1));
		else if(lab[i] == R) g[u[i]].pb(mkp(v[i], ch)), g[v[i]].pb(mkp(u[i], ch));
	}
	spfa(s);
	return dis[t];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", u + i, v + i, w + i);
		lab[i] = w[i] ? -1 : ++notSure;
	}

	if(check(0, inf) < L) printf("NO\n");
	else if(check(notSure, 1) > L) printf("NO\n");
	else{
		int l = 0, r = notSure;
		while(l + 1 < r){
			int mid = (l + r + 1) >> 1;
			if(check(mid, 1) <= L) r = mid;
			else l = mid;
		}
		int ans = r;

		l = 1, r = inf;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(check(ans, mid) <= L) l = mid;
			else r = mid;
		}
		printf("YES\n");

		//if(m == 4093) l++; //printf("%d\n", ans);
		for(int i = 1; i <= m; ++i){
			if(lab[i] == -1) printf("%d %d %d\n", u[i], v[i], w[i]);
			else if(lab[i] < ans) printf("%d %d %d\n", u[i], v[i], 1);
			else if(lab[i] == ans) printf("%d %d %d\n", u[i], v[i], l);
			else printf("%d %d %d\n", u[i], v[i], inf);
		}
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