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

int n, m, l[5010], r[5010];
int p[1001000], a[50010], f[50010], ans[5010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 1; i <= 1000000; i++) p[i] = p[i - 1] ^ i;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= m; i++) scanf("%d%d", l + i, r + i);
	for(int i = 1; i <= n; i++){
		int mx = 0;
		for(int j = i; j <= n; j++){
			int cnt = p[a[i]] ^ p[a[j]] ^ (a[i] < a[j] ? a[i] : a[j]);
			mx = max(mx, cnt);
			f[j] = mx;
		}
		for(int j = 1; j <= m; j++)
			if(l[j] <= i && r[j] >= i)
				ans[j] = max(ans[j], f[r[j]]);
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
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