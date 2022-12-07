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

int xt, yt, xm, ym, n, m;
char mp[1010][1010];
bool vis[1010 * 1010][4];
int dis[1010 * 1010][4];
const int xx[4] = {0, -1, 0, 1};
const int yy[4] = {-1, 0, 1, 0};
bool ook[1010][1010][4][4];

inline int p(int x, int y){
	return (x - 1) * m + y;
}

inline int getx(int t){
	return (t - 1) / m + 1;
}

inline int gety(int t){
	return t - m * (getx(t) - 1);
}

inline bool tto(int x, int y, int t, int k){
	if((k - t + 4) % 4 == 0){
		if(mp[x][y] == '+' || mp[x][y] == '-' || mp[x][y] == '<' || mp[x][y] == 'R' || mp[x][y] == 'U' || mp[x][y] == 'D') return 1;
	}else if((k - t + 4) % 4 == 1){
		if(mp[x][y] == '+' || mp[x][y] == '|' || mp[x][y] == '^' || mp[x][y] == 'R' || mp[x][y] == 'L' || mp[x][y] == 'D') return 1;
	}else if((k - t + 4) % 4 == 2){
		if(mp[x][y] == '+' || mp[x][y] == '-' || mp[x][y] == '>' || mp[x][y] == 'L' || mp[x][y] == 'U' || mp[x][y] == 'D') return 1;
	}else{
		if(mp[x][y] == '+' || mp[x][y] == '|' || mp[x][y] == 'v' || mp[x][y] == 'R' || mp[x][y] == 'U' || mp[x][y] == 'L') return 1;
	}
	return 0;
}

inline bool ok(int x, int y, int k, int t){
	int a = x + xx[t], b = y + yy[t];
	if(a < 1 || a > n) return 0;
	if(b < 1 || b > m) return 0;
	if(!tto(x, y, k, t)) return 0;
	if(!tto(a, b, k, t ^ 2)) return 0;
	return 1;
}

void spfa(int s){
	memset(dis, 127, sizeof(dis));
	dis[s][0] = 0;
	queue<pair<int, int> > q;
	q.push(mkp(s, 0));
	vis[s][0] = 1;
	while(!q.empty()){
		auto t = q.front(); q.pop();
		int x = getx(t.fi), y = gety(t.fi), k = t.se;
			if(dis[t.fi][(k + 1) % 4] > dis[t.fi][t.se] + 1){
				dis[t.fi][(k + 1) % 4] = dis[t.fi][t.se] + 1;
				if(!vis[t.fi][(k + 1) % 4]){
					vis[t.fi][(k + 1) % 4] = 1;
					q.push(mkp(t.fi, (k + 1) % 4));
				}
			}
		for(int i = 0; i < 4; ++i){
			if(ook[x][y][k][i])
				if(dis[p(x + xx[i], y + yy[i])][k] > dis[t.fi][k] + 1){
					dis[p(x + xx[i], y + yy[i])][k] = dis[t.fi][k] + 1;
					if(!vis[p(x + xx[i], y + yy[i])][k]){
						vis[p(x + xx[i], y + yy[i])][k] = 1;
						q.push(mkp(p(x + xx[i], y + yy[i]), k));
					}
				}
		}
		vis[t.fi][t.se] = 0;
	}
}

int getmin(int t){
	int ans = dis[t][0];
	for(int i = 1; i < 4; ++i) ans = min(dis[t][i], ans);
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%s", mp[i] + 1);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 4; ++k)
				for(int t = 0; t < 4; ++t)
					ook[i][j][k][t] = ok(i, j, k, t);
	scanf("%d%d", &xt, &yt);
	scanf("%d%d", &xm, &ym);
	spfa(p(xt, yt));
	int ans = getmin(p(xm, ym));
	if(ans < 1e9) cout << ans;
	else cout << -1;
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