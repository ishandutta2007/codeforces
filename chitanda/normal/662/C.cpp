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

int n, m, dp[21][1 << 20], cnt[1 << 20], ans, col[100000];
char s[100010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j++)
			col[j] |= (s[j] == '1') << i;
	}
	for(int i = 0; i < m; i++) dp[0][col[i]]++;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < (1 << n); j++){
			if(i > 1) dp[i][j] += (i - 2 - n) * dp[i - 2][j];
			for(int p = 0; p < n; p++)
				dp[i][j] += dp[i - 1][j ^ (1 << p)];
			dp[i][j] /= i;
		}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < (1 << n); j++)
			cnt[j] += dp[i][j] * min(i, n - i);
	ans = cnt[0];
	for(int i = 1; i < (1 << n); i++) ans = min(ans, cnt[i]);
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