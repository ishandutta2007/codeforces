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

int n, m, ans;
int use[7];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	int t1 = 0, b1 = 1, t2 = 0, b2 = 1;
	while(b1 < n) t1++, b1 *= 7;
	while(b2 < m) t2++, b2 *= 7;
	t1 = max(t1, 1);
	t2 = max(t2, 1);
	if(t1 + t2 > 7){
		printf("0");
		return 0;
	}
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			memset(use, 0, sizeof(use));
			int ii = i, jj = j;
			for(int tt = 1; tt <= t1; ++tt){
				use[ii % 7]++;
				ii /= 7;
			}
			for(int tt = 1; tt <= t2; ++tt){
				use[jj % 7]++;
				jj /= 7;
			}
			bool flag = 1;
			for(int tt = 0; tt < 7; ++tt)
				if(use[tt] > 1) flag = 0;
			ans += flag;
		}
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