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
#define eps (1e-18)

typedef long double Double;
const int maxn = 800000;
const Double pi = atan2(Double(0),Double(-1));
int n, c, d, x, y;
Double ang[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> c >> d;
	FOR(i, 1, n){
		scanf("%d%d", &x, &y);
		Double xx = x - c, yy = y - d;
		ang[i] = atan2(yy, xx);
	}
	ll tot = (ll)n * (n - 1) * (n - 2) / 6;
	sort(ang + 1, ang + n + 1);
	FOR(i, 1, n) ang[i + n] = ang[i] + 2 * pi;
	int j = 1, l = 1, r = 1;
	FOR(i, 1, n){
		while(ang[j + 1] - ang[i] < pi + eps) j++;
		while(ang[l] - ang[i] < pi - eps) l++;
		while(ang[r + 1] - ang[i] < pi + eps) r++;
		tot -= (ll)(j - i) * (j - i - 1) / 2;
		tot += (ll)(r - l) * (r - l + 1) / 2;
	}
	cout << tot;
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