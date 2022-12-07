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

int n;
double p[20][20], ans;
double f[20][1 << 18];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> p[i][j];
	n--;

	for(int i = 0; i < n; ++i)
		f[i][0] = p[0][i + 1];
	for(int i = 1; i < 1 << n; ++i)
		for(int j = 0; j < n; ++j)
			if(!((1 << j) & i)){
				for(int k = 0; k < n; ++k)
					if((1 << k) & i)
						f[j][i] = max(f[j][i], p[j + 1][k + 1] * f[j][i ^ (1 << k)] + p[k + 1][j + 1] * f[k][i ^ (1 << k)]);
			}
	if(!n) ans = 1;
	for(int i = 0; i < n; ++i)
		ans = max(ans, f[i][((1 << n) - 1) ^ (1 << i)]);
	printf("%.8f\n", ans);
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