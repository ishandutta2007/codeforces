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

const ll oo = 1LL << 58;
int n, k, a[200100], ans, ok[200100];
ll cal[200100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	cin >> n >> k;
	ll tot = 0;
	for(int i = 0; i <= n; i++){
		scanf("%d", a + i);
		if(tot % 2 != 0) continue;
		tot /= 2;
		cal[i] = tot;
		ok[i] = 1;
		tot += a[i];
	}
	ll cnt = 0;
	for(int i = n; i >= 0; i--){
		if(abs(cnt) < oo) cnt = cnt * 2;
		if(ok[i]){
			if(i != n || cal[i] != 0){
				if(abs(cal[i] + cnt) <= k) ans++;
			}
		}
		if(abs(cnt) < oo) cnt = cnt + a[i];
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