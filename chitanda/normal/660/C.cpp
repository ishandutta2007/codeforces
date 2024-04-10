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

int n, k;
int a[300100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	int r = 0, cnt = 0;
	while(r < n && cnt + (a[r + 1] == 0) <= k) cnt += (a[++r] == 0);
	int ans = r; int ansl = 1, ansr = r;
	int l = 1;
	for(int i = r + 1; i <= n; ++i){
		cnt += a[i] == 0;
		while(cnt > k && l <= i)
			cnt -= (a[l++] == 0);
		if(i - l + 1 > ans){
			ans = max(ans, i - l + 1);
			ansl = l;
			ansr = i;
		}
	}
	printf("%d\n", ans);
	for(int i = ansl; i <= ansr; ++i) a[i] = 1;
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
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