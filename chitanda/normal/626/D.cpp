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

int n;
int a[2016], cal[10001];
ll rnt[10001];
ll sum;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			cal[a[j] - a[i]]++;
	for(int i = 5000; i >= 1; i--) rnt[i] = rnt[i + 1] + cal[i];
	for(int i = 1; i <= 5000; i++)
		for(int j = 1; j <= 5000; j++)
			sum += (ll)cal[i] * cal[j] * rnt[i + j + 1];
	double tot = n * (n - 1) / 2;
	printf("%.10f\n", sum / tot / tot / tot);
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