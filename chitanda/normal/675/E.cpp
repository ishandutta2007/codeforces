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

int n, a[100100], c[100100];
ll dp[100100], ans;

void modify(int x, int v){
	for(; x <= n; x += x & -x) if(a[v] > a[c[x]]) c[x] = v;
}

int ask(int x){
	int ans = 0;
	for(; x; x -= x & -x) if(a[c[x]] > a[ans]) ans = c[x];
	return ans;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++) scanf("%d", a + i);
	modify(n, a[n] = n);
	for(int i = n - 1; i >= 1; i--){
		int m = ask(a[i]);
		ans += (dp[i] = dp[m] - (a[i] - m) + n - i);
		modify(i, i);
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