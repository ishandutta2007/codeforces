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

int n, m, k, ty, rc, a;
int sta[2][5001][2];

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	cin >> n >> m >> k;
	FOR(i, 1, k){
		scanf("%d%d%d", &ty, &rc, &a);
		sta[ty - 1][rc][0] = i;
		sta[ty - 1][rc][1] = a;
	}
	FOR(i, 1, n){
		FOR(j, 1, m){
			printf("%d ", sta[0][i][0] > sta[1][j][0] ? sta[0][i][1] : sta[1][j][1]);
		}
		printf("\n");
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