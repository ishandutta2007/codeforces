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
#define M 1000000007

int n, k, ans;
int a[222], f[222][222][1023];

void add(int &a, int b) { a = (a + b) % M; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	f[0][0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			for(int p = 0; p <= k; p++)
				if(f[i][j][p]){
					int s = p + j * (a[i + 1] - a[i]);
					if(s > k) continue;
					if(j) add(f[i + 1][j - 1][s], (ll)f[i][j][p] * j % M);
					add(f[i + 1][j][s], (ll)f[i][j][p] * (j + 1) % M);
					add(f[i + 1][j + 1][s], f[i][j][p]);
				}
	for(int i = 0; i <= k; i++) add(ans, f[n][0][i]);
	printf("%d\n", ans);
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