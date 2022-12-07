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

const int maxn = 100010;
int n, k, f[maxn], g[maxn], tminf[maxn], tming[maxn];
int ans;
char s[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i){
		f[i] = f[i - 1], g[i] = g[i - 1];
		if(s[i] == 'a'){
			f[i]++;
			tminf[f[i]] = i;
		}else{
			g[i]++;
			tming[g[i]] = i;
		}
		ans = max(i - tminf[max(0, f[i] - k)], ans);
		ans = max(i - tming[max(0, g[i] - k)], ans);
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