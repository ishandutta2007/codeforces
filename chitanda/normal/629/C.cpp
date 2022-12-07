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
#define M 1000000007

int n, m, f[2016][2016], g[2016][4016];
char s[100100];

void add(int &a, int b) { a += b; if(a >= M) a -= M; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int t = 0, tm = 0;
	for(int i = 1; i <= m; i++){ 
		t += s[i] == '(' ? 1 : -1;
		tm = min(tm, t);
	}
	f[0][0] = 1;
	if(abs(t) > 2000) { printf("0\n"); return 0; }
	for(int i = 1; i <= n - m; i++){
		for(int j = 0; j < i; j++)
			if(f[i - 1][j]){
				if(j) add(f[i][j - 1], f[i - 1][j]);
				add(f[i][j + 1], f[i - 1][j]);
				if(j + tm >= 0){
					add(g[i][j + t + 1], f[i - 1][j]);
					if(j + t > 0) add(g[i][j + t - 1], f[i - 1][j]);
				}
			}
		for(int j = 0; j < i + t; j++){
			if(j) add(g[i][j - 1], g[i - 1][j]);
			add(g[i][j + 1], g[i - 1][j]);
		}
	}
	int ans = g[n - m][0];
	if(t == tm) add(ans, f[n - m][-t]);
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