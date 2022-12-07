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

int m, d;
char a[2010], b[2010];
int f[2010][2000][2];

bool check(char a[]){
	int p = 0, n = strlen(a + 1);
	FOR(i, 1, n){
		if(i & 1) { if(a[i] - '0' == d) return 0; }
		else if(a[i] - '0' != d) return 0;
		p = (p * 10 + a[i] - '0') % m;
	}
	return p == 0;
}

inline void add(int &a, int b) { a += b; if (a >= M) a -= M; }

int DP(char a[]){
	memset(f, 0, sizeof(f));
	int n = strlen(a + 1);
	f[0][0][1] = 1;
	FOR(i, 1, n){
		int x = a[i] - '0';
		for(int j = 0; j < m; j++){
			if(i & 1){
				FOR(k, 0, 9){
					if(k == d) continue;
					if(k <= x){
						add(f[i][(j * 10 + k) % m][0], f[i - 1][j][0]);
						if(k < x) add(f[i][(j * 10 + k) % m][0], f[i - 1][j][1]);
						if(k == x) add(f[i][(j * 10 + k) % m][1], f[i - 1][j][1]);
					}else add(f[i][(j * 10 + k) % m][0], f[i - 1][j][0]);
				}
			}else{
				add(f[i][(j * 10 + d) % m][0], f[i - 1][j][0]);
				if(x > d) add(f[i][(j * 10 + d) % m][0], f[i - 1][j][1]);
				if(x == d) add(f[i][(j * 10 + d) % m][1], f[i - 1][j][1]);
			}
		}
	}
	return f[n][0][0];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &m, &d);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	int ans = (DP(b) - DP(a) + M) % M;
	if(check(b)) ans = (ans + 1) % M;
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