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

int n, m, l;
int a[1000100], b[1000100];

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, n){
		scanf("%d", a + i);
		if(a[i] <= m) b[a[i]]++;
	}
	ROF(i, m, 1)
		for(int j = i + i; j <= m; j += i)
			b[j] += b[i];
	FOR(i, 1, m)
		if(b[i] > b[l]) l = i;
	if(!l) { printf("1 0\n"); return 0; }
	int g = 1;
	FOR(i, 1, n) if(l % a[i] == 0) g = (ll)g * a[i] / gcd(g, a[i]);
	printf("%d %d\n", g, b[l]);
	FOR(i, 1, n) if(l % a[i] == 0) printf("%d ", i);
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