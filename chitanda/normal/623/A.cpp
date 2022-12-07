//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 520;
int n, m, x, y, a[maxn][maxn], fa[maxn];
bool isb[maxn];
char s[maxn];

int find(int x) { if(fa[x] != x) fa[x] = find(fa[x]); return fa[x]; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;
	}
	for(int i = 1; i <= n; i++){
		bool ok = 1;
		for(int j = 1; j <= n; j++)
			if(i != j && !a[i][j]) ok = 0;
		if(ok) { isb[i] = 1; s[i] = 'b'; }
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j && !isb[i] && !isb[j] && a[i][j]){
				int x = find(i), y = find(j);
				fa[x] = y;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j && !isb[i] && !isb[j] && !a[i][j] && find(i) == find(j)){
				printf("No\n");
				return 0;
			}
	int t = 0, cal = 0;
	for(int i = 1; i <= n; i++) if(!isb[i]) t = find(i);
	for(int i = 1; i <= n; i++) if(!isb[i] && fa[i] == i) cal++;
	if(cal > 2) { printf("No\n"); return 0; }
	for(int i = 1; i <= n; i++)
		if(!isb[i]) { if(find(i) == t) s[i] = 'a'; else s[i] = 'c'; }
	printf("Yes\n%s", s + 1);
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