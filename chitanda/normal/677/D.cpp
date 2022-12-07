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

const int maxn = 333;
const int xx[4] = {0, 0, 1, -1};
const int yy[4] = {1, -1, 0, 0};
int n, m, p, a[maxn][maxn], inx;
int vis[maxn][maxn], dp[maxn][maxn], dis[maxn][maxn];
vector<pair<int, int> >q[maxn * maxn];

inline bool ok(int x, int y) { return x > 0 && x <= n && y > 0 && y <= m; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &p);
	memset(dp, 127, sizeof(dp));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%d", a[i] + j);
			q[a[i][j]].pb(mkp(i, j));
			if(a[i][j] == 1) dp[i][j] = i - 1 + j - 1;
		}
	for(int i = 1; i < p; ++i){
		int l = q[i].size();
		if(l <= n){
			for(auto u : q[i + 1])
				for(auto v : q[i])
					ckmin(dp[u.fi][u.se], dp[v.fi][v.se] + abs(u.fi - v.fi) + abs(u.se - v.se));
		}else{
			memset(dis, 127, sizeof(dis));
			inx++;
			queue<pair<int, int> > que;
			for(auto v : q[i]){
				dis[v.fi][v.se] = dp[v.fi][v.se];
				que.push(v);
			}
			while(!que.empty()){
				auto t = que.front(); que.pop();
				for(int i = 0; i < 4; ++i){
					int x = t.fi + xx[i], y = t.se + yy[i];
					if(ok(x, y) && ckmin(dis[x][y], dis[t.fi][t.se] + 1)){
						if(vis[x][y] < inx){
							vis[x][y] = inx;
							que.push(mkp(x, y));
						}
					}
				}
				vis[t.fi][t.se] = 0;
			}
			for(auto v : q[i + 1])
				dp[v.fi][v.se] = dis[v.fi][v.se];
		}
	}
	for(auto v : q[p]) cout << dp[v.fi][v.se];
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