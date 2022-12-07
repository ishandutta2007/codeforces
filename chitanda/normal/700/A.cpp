//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))

const double eps = 1e-10;

int n, k;
double l, v1, v2;

bool check(double d){
	int t = (n + k - 1) / k;
	double now1 = 0, now2 = 0, tnow = 0;
	for(int i = 1; i <= t; ++i){
		double tt = (now2 - now1) / (v1 + v2);
		double L = (v1 * v2 * (d - tnow) - v2 * l + now1 * v2) / (v1 - v2);
		if(L < -eps || L + now1 + tt * v1 > l + eps) return 0;
		now1 += (tt + L / v2) * v1;
		now2 -= tt * v2; now2 += L;
		tnow += tt + L / v2;
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k);
	double lt = 0, rt = 1. * l / v1;
	for(int i = 1; i <= 1000; ++i){
		double d = (lt + rt) / 2;
		if(check(d)) rt = d;
		else lt = d;
	}
	printf("%.8f\n", lt);
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