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

char b[25][25];
int n, m, a[25][25], cost[25][25], flag[25][25];
int f[21][1 << 20];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%s", b[i] + 1);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", a[i] + j);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				if(j != k && b[j][i] == b[k][i]){
					cost[j][i] += a[k][i];
					flag[j][i] |= 1 << (k - 1);
				}
		
	memset(f, 127, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j < 1 << n; ++j){
			f[i][j] = min(f[i][j], f[i - 1][j]);
			for(int t = 0; t < n; ++t)
				if(!((j >> t) & 1)){
					int tt = 1 << t;
					ckmin(f[i][j | tt], f[i][j] + a[t + 1][i]);
					ckmin(f[i][j | flag[t + 1][i] | tt], f[i][j] + cost[t + 1][i]);
				}
		}
	printf("%d\n", f[m][(1 << n) - 1]);
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