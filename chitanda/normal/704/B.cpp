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

const int maxn = 5010;
int n, m, s, e;
int a[maxn], b[maxn], c[maxn], d[maxn], x[maxn];
ll f[maxn][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &s, &e);
	for(int i = 1; i <= n; ++i) scanf("%d", x + i);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), a[i] += x[i];
 	for(int i = 1; i <= n; ++i) scanf("%d", b + i), b[i] -= x[i];
	for(int i = 1; i <= n; ++i) scanf("%d", c + i), c[i] += x[i];
	for(int i = 1; i <= n; ++i) scanf("%d", d + i), d[i] -= x[i];
	
	memset(f, 127, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i)
		if(i != s && i != e){
			for(int j = 0; j <= n; ++j){
				int k;
				if((i > s && i > e) || (i < s && i < e)) k = 0;
				else k = s < e ? 1 : -1;
				
				k += j;
				
				if((j > 1 || (j > 0 && i == n)) || (k > 1 || (k > 0 && i == n)))
					f[i][j - 1] = min(f[i][j - 1], f[i - 1][j] + a[i] + c[i]);
				
				if(j > 0)
					f[i][j] = min(f[i][j], f[i - 1][j] + b[i] + c[i]);
				
				f[i][j + 1] = min(f[i][j + 1], f[i - 1][j] + b[i] + d[i]);
				
				if(k > 0)
					f[i][j] = min(f[i][j], f[i - 1][j] + a[i] + d[i]);
			}
		}else if(i == s){
			for(int j = 0; j <= n; ++j){
				int k = s < e ? 0 : -1;
				k += j;
				if((j > 0 && (k > 0 || i == n)) || j > 1)
					f[i][j - 1] = min(f[i][j - 1], f[i - 1][j] + c[i]);
				f[i][j] = min(f[i][j], f[i - 1][j] + d[i]);
			}
		}else if(i == e){
			for(int j = 0; j <= n; ++j){
				int k = s < e ? 1 : 0;
				k += j;
				if((k > 0 && (j > 0 || i == n)) || k > 1)
					f[i][j] = min(f[i][j], f[i - 1][j] + a[i]);
				f[i][j + 1] = min(f[i][j + 1], f[i - 1][j] + b[i]);
			}
		}
	printf("%lld\n", f[n][0]);
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