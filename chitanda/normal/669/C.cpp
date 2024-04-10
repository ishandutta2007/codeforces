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

const int maxn = 110;
int n, m, q, ty, x, y, z;
int val[maxn][maxn];
pair<int, int> now[maxn][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			now[i][j] = mkp(i, j);
	for(int i = 1; i <= q; ++i){
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d", &x);
			auto t = now[x][1];
			for(int j = 1; j < m; ++j)
				now[x][j] = now[x][j + 1];
			now[x][m] = t;
		}else if(ty == 2){
			scanf("%d", &x);
			auto t = now[1][x];
			for(int j = 1; j < n; ++j)
				now[j][x] = now[j + 1][x];
			now[n][x] = t;
		}else{
			scanf("%d%d%d", &x, &y, &z);
			val[now[x][y].fi][now[x][y].se] = z;
		}
	}
	for(int i = 1; i <= n; printf("\n"), ++i)
		for(int j = 1; j <= m; ++j)
			printf("%d ", val[i][j]);
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