//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

int n, k, s, tans, ans, f[151][151 * 151], g[151][151 * 151], a[151];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k >> s;
	FOR(i, 1, n){
		scanf("%d", a + i);
		if(i <= k) tans += a[i];
	}
	s = min(n * n, s);
	memset(f, 128, sizeof(f));
	memset(f[0], 0, sizeof(f[0]));
	for(int i = 1; i <= k; i++)
		for(int j = i; j; j--)
			for(int p = s; p >= k - i; p--)
				f[j][p] = max(f[j][p], f[j - 1][p - (k - i)] + a[i]);
	memset(g, 127, sizeof(g));
	memset(g[0], 0, sizeof(g[0]));
	for(int i = k + 1; i <= n; i++)
		for(int j = i - k; j; j--)
			for(int p = s; p >= i - k; p--)
				g[j][p] = min(g[j][p], g[j - 1][p - (i - k)] + a[i]);
	for(int i = 1; i <= s; i++)
		for(int j = 1; j <= min(k, n - k); j++)
			if(f[j][s - i] >= 0)
				ans = min(ans, g[j][i] - f[j][s - i]);
	cout << ans + tans;
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