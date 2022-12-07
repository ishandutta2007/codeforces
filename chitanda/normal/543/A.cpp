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

int n, m, b, mod;
int f[2][510][510], a[510];

void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m >> b >> mod;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	f[0][0][0] = 1;
	bool tag = 0;
	for(int i = 1; i <= n; ++i){
		tag ^= 1;
		memset(f[tag], 0, sizeof(f[tag]));
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k <= b; ++k){
				if(j && k >= a[i]) add(f[tag][j][k], f[tag][j - 1][k - a[i]]);
				add(f[tag][j][k], f[tag ^ 1][j][k]);
			}
	}
	int ans = 0;
	for(int i = 0; i <= b; ++i)
		add(ans, f[tag][m][i]);
	cout << ans;
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