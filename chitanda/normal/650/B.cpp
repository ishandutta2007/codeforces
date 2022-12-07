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

int n, a, b, T, ans;
char s[500100];
int c[500100];

void work(int T){
	for(int i = 1; i < n; i++){
		c[i] = c[i - 1] + a + (s[i] == 'w') * b + 1;
	}
	T -= (s[0] == 'w') * b + 1;
	if(T < 0) return;
	ans = max(ans, 1);
	for(int i = n - 1; i >= 1; i--){
		T -= a + (s[i] == 'w') * b + 1;
		if(T < 0) break;
		ans = max(ans, n - i + 1);
		if(T < (n - i) * a) continue;
		int t = upper_bound(c + 1, c + n, T - (n - i) * a) - c; t--;
		ans = max(ans, min(n, t + (n - i + 1)));
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	cin >> n >> a >> b >> T;
	scanf("%s", s);
	work(T);
	reverse(s + 1, s + n);
	work(T);
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