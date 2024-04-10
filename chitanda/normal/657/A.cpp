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

int n, d, h;

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	cin >> n >> d >> h;
	if(d > 2 * h){
		printf("-1\n");
		return 0;
	}
	if(n > 2 && d == 1){
		printf("-1\n");
		return 0;
	}
	for(int i = 2; i <= h + 1; i++) printf("%d %d\n", i - 1, i);
	if(h < d){
		printf("%d %d\n", 1, h + 2);
		for(int i = h + 3; i <= d + 1; i++) printf("%d %d\n", i - 1, i);
		for(int i = d + 2; i <= n; i++) printf("%d %d\n", 1, i);
	}else{
		for(int i = h + 2; i <= n; i++) printf("%d %d\n", 2, i);
	}
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