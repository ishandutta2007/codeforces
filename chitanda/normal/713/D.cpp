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

int b[1010][1010][10][10];
int lg[1010];
int n, m, x;

int ask(int x1, int x2, int y1, int y2){
	int p = lg[x2 - x1 + 1], q = lg[y2 - y1 + 1];
	return max(max(b[x1][y1][p][q], b[x2 - (1 << p) + 1][y2 - (1 << q) + 1][p][q]), max(b[x1][y2 - (1 << q) + 1][p][q], b[x2 - (1 << p) + 1][y1][p][q]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%d", &x);
			if(x) b[i][j][0][0] = min(b[i - 1][j][0][0], min(b[i][j - 1][0][0], b[i - 1][j - 1][0][0])) + 1;
		}

	for(int p = 1; p < 10; ++p)
		for(int i = 1; i + (1 << p) - 1 <= n; ++i)
			for(int j = 1; j <= m; ++j)
				b[i][j][p][0] = max(b[i][j][p - 1][0], b[i + (1 << (p - 1))][j][p - 1][0]);

	for(int p = 0; p < 10; ++p)
		for(int q = 1; q < 10; ++q)
			for(int i = 1; i + (1 << p) - 1 <= n; ++i)
				for(int j = 1; j + (1 << q) - 1 <= m; ++j)
					b[i][j][p][q] = max(b[i][j][p][q - 1], b[i][j + (1 << (q - 1))][p][q - 1]);

	for(int i = 2; i <= 1000; ++i) lg[i] = lg[i >> 1] + 1;

	int T, x1, x2, y1, y2;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(ask(x1 + mid - 1, x2, y1 + mid - 1, y2) >= mid) l = mid;
			else r = mid;
		}
		printf("%d\n", l);
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