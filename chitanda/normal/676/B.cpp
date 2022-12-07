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
#define eps (1e-8)

int n, t, ans;
double f[20][20];

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	cin >> n >> t;
	f[1][1] = t; if(t >= 1) ans++;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= i; ++j){
			if(f[i - 1][j - 1] - 1 > eps) f[i][j] += (f[i - 1][j - 1] - 1) / 2;
			if(f[i - 1][j] - 1 > eps) f[i][j] += (f[i - 1][j] - 1) / 2;
			if(f[i][j] > 1 - eps) ans++;
		}
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