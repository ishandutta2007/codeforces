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

const int xx[] = {0, -1, 1, 0};
const int yy[] = {1, 0, 0, -1};

int c[510][510], col, flag[510 * 510], size[510 * 510], s[510][510];
int n, k, ans, res;
char a[510][510];

void dfs(int x, int y){
	c[x][y] = col;
	size[col]++;
	for(int i = 0; i < 4; ++i){
		int tx = x + xx[i], ty = y + yy[i];
		if(!c[tx][ty] && a[tx][ty] == '.') dfs(tx, ty);
	}
}

int calc(int x, int y){
	return s[x + k - 1][y + k - 1] - s[x - 1][y + k - 1] - s[x + k - 1][y - 1] + s[x - 1][y - 1];
}

void add(int x, int y){
	int t = c[x][y];
	if(!t) return;
	if(!flag[t]) res += size[t];
	flag[t]++;
}

void del(int x, int y){
	int t = c[x][y];
	if(!t) return;
	flag[t]--;
	if(!flag[t]) res -= size[t];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%s", a[i] + 1);
		for(int j = 1; j <= n; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '.');
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!c[i][j] && a[i][j] == '.') col++, dfs(i, j);

	for(int i = 1; i <= n - k + 1; ++i){
		res = 0;
		memset(flag, 0, sizeof(flag));
		for(int j = i - 1; j <= i + k; ++j)
			for(int l = 1; l <= k; ++l)
				add(j, l);
		for(int j = i; j < i + k; ++j) add(j, k + 1);
		ans = max(ans, res + k * k - calc(i, 1));
		for(int j = 2; j <= n - k + 1; ++j){
			for(int l = i; l < i + k; ++l){
				del(l, j - 2);
				add(l, j + k);
			}
			del(i - 1, j - 1);
			del(i + k, j - 1);
			add(i - 1, j + k - 1);
			add(i + k, j + k - 1);
			ans = max(ans, res + k * k - calc(i, j));
		}
	}
	printf("%d\n", ans);
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