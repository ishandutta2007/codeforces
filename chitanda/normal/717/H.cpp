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

const int maxn = 50010, maxm = 100100;
int n, m, a[maxn], b[maxn], c[maxm], u[maxm], v[maxm];
int T, t[maxn][20];

bool Try(){
	for(int i = 1; i <= n; ++i)
		b[i] = t[i][rand() % a[i]];
	for(int i = 1; i <= T; ++i)
		c[i] = rand() % 2;

	int cnt = 0;
	for(int i = 1; i <= m; ++i)
		if(c[b[u[i]]] != c[b[v[i]]]) cnt++;
	if(cnt < m / 2) return 0;
	for(int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
	for(int i = 1; i <= T; ++i) printf("%d%c", c[i] + 1, " \n"[i == T]);
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d", u + i, v + i);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		for(int j = 0; j < a[i]; ++j){
			scanf("%d", t[i] + j);
			T = max(t[i][j], T);
		}
	}
	while(!Try());
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