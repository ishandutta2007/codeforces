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

int t, n, m, k;
int f[31][31][31 * 31];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &t);
	memset(f, 127, sizeof(f));
	for(int i = 1; i <= 30; i++)
		for(int j = 1; j <= 30; j++){
			f[i][j][i * j] = f[i][j][0] = 0;
			for(int k = 1; k < i * j; k++){
				for(int p = 1; p < i; p++){
					if(p * j <= k) f[i][j][k] = min(f[i][j][k], f[i - p][j][k - p * j] + j * j);
					if((i - p) * j >= k) f[i][j][k] = min(f[i][j][k], f[i - p][j][k] + j * j);
				}
				for(int p = 1; p < j; p++){
					if(p * i <= k) f[i][j][k] = min(f[i][j][k], f[i][j - p][k - p * i] + i * i);
					if((j - p) * i >= k) f[i][j][k] = min(f[i][j][k], f[i][j - p][k] + i * i);
				}
			}
		}
	while(t--){
		cin >> n >> m >> k;
		cout << f[n][m][k] << endl;
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