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

int n, k, c[510];
bool f[2][510][510];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	f[0][0][0] = 1;
	bool tag = 0;
	for(int i = 1; i <= n; ++i){
		tag ^= 1;
		memset(f[tag], 0, sizeof(f[tag]));
		scanf("%d", c + i);
		for(int j = 0; j <= k; ++j){
			for(int t = 0; t <= j; ++t){
				if(f[tag ^ 1][j][t] == 1){
					f[tag][j][t] = 1;
					if(j + c[i] <= k){
						f[tag][j + c[i]][t] = 1;
						f[tag][j + c[i]][t + c[i]] = 1;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= k; ++i)
		if(f[tag][k][i]) ans++;
	printf("%d\n", ans);
	for(int i = 0; i <= k; ++i)
		if(f[tag][k][i]) printf("%d ", i);
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