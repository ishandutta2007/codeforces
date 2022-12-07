//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;

const int maxn = 10010;
int n, c;
int p[maxn], s[maxn];
ll f[2][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; ++i) scanf("%d", p + i);
	for(int j = 1; j <= n; ++j) scanf("%d", s + j);
	
	memset(f, 127, sizeof(f));
	int cur = 1, pre = 0;
	f[pre][0] = 0;
	
	for(int i = 1; i <= n; ++i){
		memset(f[cur], 127, sizeof(f[cur]));
		for(int j = 0; j < i; ++j){
			f[cur][j] = min(f[cur][j], f[pre][j] + (ll)j * c + p[i]);
			f[cur][j + 1] = min(f[cur][j + 1], f[pre][j] + s[i]);
		}
		swap(cur, pre);
	}
	ll res = 1LL << 60;
	for(int i = 0; i <= n; ++i)
		res = min(res, f[pre][i]);
	cout << res;
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