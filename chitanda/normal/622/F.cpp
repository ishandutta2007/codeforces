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

int n, k, ans;
int fac[1000100], res[1000100];

int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	FOR(i, 1, k + 2) fac[i] = (ll)fac[i - 1] * i % M;
	FOR(i, 1, k + 2) res[i] = (res[i - 1] + pow(i, k)) % M;
	if(n <= k + 2) { printf("%d\n", res[n]); return 0; }
	int tmp = 1;
	for(int i = 1; i <= k + 2; i++) tmp = (ll)tmp * (n - i) % M;
	for(int i = 1; i <= k + 2; i++){
		int tt = (ll)fac[i - 1] * fac[k + 2 - i] % M;
		if((k + 2 - i) & 1) tt = (M - tt) % M;
		int ta = (ll)tmp * pow(n - i, M - 2) % M * pow(tt, M - 2) % M;
		ans = (ans + (ll)ta * res[i] % M) % M;
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