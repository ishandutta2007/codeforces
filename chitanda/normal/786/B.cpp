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

const int maxn = 1000100;
const int maxp = maxn * 4 * 2;
int chu[maxp], ru[maxp];
vector<pair<int, int> > g[maxp];
int po[maxn];
int n, q, s;
ll dis[maxp];
bool vis[maxp];
int tot;

void build(int t, int l, int r){
	ru[t] = ++tot;
	chu[t] = tot += (l < r);
	if(t > 1){
		po[l] = ru[t];
		g[ru[t >> 1]].pb(mkp(ru[t], 0));
		g[chu[t]].pb(mkp(chu[t >> 1], 0));
	}
	if(l == r){
		return;
	}

	build(t << 1, l, (l + r) >> 1);
	build((t << 1) | 1, (l + r) / 2 + 1, r);
}

void query1(int t, int l, int r, int x, int y, int v, int w){
	if(x <= l && y >= r){
		g[po[v]].pb(mkp(ru[t], w));
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) query1(t << 1, l, mid, x, y, v, w);
	if(y > mid) query1((t << 1) | 1, mid + 1, r, x, y, v, w);
}

void query2(int t, int l, int r, int x, int y, int v, int w){
	if(x <= l && y >= r){
		g[chu[t]].pb(mkp(po[v], w));
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) query2(t << 1, l, mid, x, y, v, w);
	if(y > mid) query2((t << 1) | 1, mid + 1, r, x, y, v, w);
}

void spfa(int S){
	queue<int> q;
	memset(dis, 127, sizeof(dis));
	q.push(S);
	dis[S] = 0, vis[S] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
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
		vis[t] = 0;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &q, &s);
	build(1, 1, n);
	for(int i = 1; i <= q; ++i){
		int ty, v, u, w, l, r;
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d%d%d", &v, &u, &w);
			g[po[v]].pb(mkp(po[u], w));
		}else if(ty == 2){
			scanf("%d%d%d%d", &v, &l, &r, &w);
			query1(1, 1, n, l, r, v, w);
		}else{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			query2(1, 1, n, l, r, v, w);
		}
	}
	spfa(po[s]);
	for(int i = 1; i <= n; ++i){
		if(dis[po[i]] < (1LL << 60)) printf("%lld ", dis[po[i]]);
		else printf("-1 ");
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