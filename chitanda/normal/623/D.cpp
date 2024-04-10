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

typedef pair<long double, int> mp;
int n;
long double p[110], g[110];
priority_queue<mp> q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d", &n);
	double now = 1;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		p[i] /= 100;
		g[i] = p[i];
		now *= p[i];
		q.push(mkp(1 - p[i], i));
	}
	long double ans = n;
	for(int round = 1; round <= 3000000; round++){
		mp t = q.top(); q.pop();
		int k = t.se;
		ans += t.fi * now * round;
		now /= g[k];
		g[k] = g[k] + (1 - g[k]) * p[k];
		now *= g[k];
		q.push(mkp(p[k] * (1 - g[k]) / g[k], k));
	}
	double tt = ans;
	printf("%.10f\n", tt);
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