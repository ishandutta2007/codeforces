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

int n, q, x, ty, p[1001000];

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	int now1 = 0, now2 = 1;
	for(int i = 1; i <= q; ++i){
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d", &x);
			now1 += x; now1 %= n; if(now1 < 0) now1 += n;
			now2 += x; now2 %= n; if(now2 < 0) now2 += n;
		}else{
			now1 ^= 1;
			now2 ^= 1;
		}
	}
	for(int i = 0; i < n; i += 2, now1 = (now1 + 2) % n){
		p[now1] = i;
	}
	for(int i = 1; i < n; i += 2, now2 = (now2 + 2) % n){
		p[now2] = i;
	}
	for(int i = 0; i < n; ++i) printf("%d ", p[i] + 1);
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