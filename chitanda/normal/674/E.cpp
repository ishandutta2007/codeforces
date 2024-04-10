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

const int maxn = 500100;
int ty, v, tot = 1, q, fa[maxn];
double f[maxn][61];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> q;
	for(int i = 1; i <= 60; i++) f[1][i] = 1;
	while(q--){
		scanf("%d%d", &ty, &v);
		if(ty == 1){
			tot++;
			fa[tot] = v;
			for(int i = 1; i <= 60; i++) f[tot][i] = 1;
			double a = 1, b;
			for(int i = 1, now = tot; i <= 60; i++, now = fa[now]){
				int tf = fa[now];
				b = f[tf][i];
				f[tf][i] = f[tf][i] / ((1 + a) / 2);
				f[tf][i] = f[tf][i] * ((1 + f[now][i - 1]) / 2);
				a = b;
			}
		}else{
			double ans = 0;
			for(int i = 1; i <= 60; i++) ans += 1 - f[v][i];
			printf("%.10f\n", ans);
		}
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