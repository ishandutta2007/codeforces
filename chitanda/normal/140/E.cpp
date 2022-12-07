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
#define clean(a) memset(a, 0, sizeof(a))

const int maxn = 1001000, maxl = 5100;
int n, m, p;
int l[maxn], a[maxl][maxl], fac[maxl], rfac[maxl], g[maxl], f[maxl];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &p);
	
	a[0][0] = 1;
	for(int i = 1; i <= 5000; ++i)
		for(int j = 1; j <= min(5000, m); ++j)
			a[i][j] = (a[i - 1][j - 1] + (ll)a[i - 1][j] * (j - 1)) % p;
	rfac[0] = fac[0] = 1;
	for(int i = 1; i <= min(5000, m); ++i){
		rfac[i] = (ll)rfac[i - 1] * (m - i + 1) % p;
		fac[i] = (ll)fac[i - 1] * i % p;
	}

	int sum = 1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", l + i);
		int cnt = 0;
		for(int j = 1; j <= l[i]; ++j){
			g[j] = ((ll)sum * a[l[i]][j] % p * rfac[j] % p - (j <= l[i - 1] ? (ll)f[j] * a[l[i]][j] % p * fac[j] % p : 0) + p) % p;
			(cnt += g[j]) %= p;
		}
		memcpy(f, g, sizeof(int) * (l[i] + 1));
		sum = cnt;
	}

	printf("%d\n", sum);
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