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
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define eps (1e-9)

int n, a[200100], ansi, ansk;
ll s[200100];
double ans = 0;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 0, r = min(i - 1, n - i) + 1;
		while(l + 1 < r){
			int k = (l + r) >> 1;
			ll sum = s[n] - s[n - k] + s[i] - s[i - k - 1];
			if ((ll)(a[n - k + 1] + a[i - k]) * (2 * k + 1) >= sum * 2) l = k;
			else r = k;
		}
		double ave = 1. * (s[n] - s[n - l] + s[i] - s[i - l - 1]) / (2 * l + 1) - a[i];
		if(ave > ans){
			ans = ave;
			ansi = i;
			ansk = l;
		}
	}
	if(fabs(ans) < eps) printf("1\n%d", a[1]);
	else{
		printf("%d\n%d", ansk * 2 + 1, a[ansi]);
		for(int i = 1; i <= ansk; i++) printf(" %d %d", a[ansi - i], a[n - i + 1]);
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