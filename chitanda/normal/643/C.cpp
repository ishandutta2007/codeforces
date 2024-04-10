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

const int maxn = 200100;
int n, k, t[maxn], l, r, que[maxn];
ll s[maxn];
long double c[maxn], p[maxn], f[maxn][51], g[maxn][51];

long double xielv(int i, int j, int k){
	return (g[i][k] - g[j][k]) / (s[i] - s[j]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		scanf("%d", t + i);
		s[i] = s[i - 1] + t[i];
		c[i] = c[i - 1] + 1. * s[i] / t[i];
		p[i] = p[i - 1] + 1. / t[i];
	}
	for(int i = 1; i <= n; i++){
		f[i][1] = c[i];
		g[i][1] = s[i] * p[i];
	}
	for(int kk = 1; kk < k; kk++){
		que[l = r = 1] = 0;
		for(int i = 1; i <= n; i++){
			while(l < r && xielv(que[l + 1], que[l], kk) < p[i]) l++;
			f[i][kk + 1] = f[que[l]][kk] + c[i] - c[que[l]] - s[que[l]] * (p[i] - p[que[l]]);
			g[i][kk + 1] = f[i][kk + 1] - c[i] + s[i] * p[i];
			while(l < r && xielv(i, que[r], kk) < xielv(i, que[r - 1], kk)) r--;
			que[++r] = i;
		}
	}
	printf("%.10f\n", (double)f[n][k]);
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