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
#define eps (1e-10)

typedef long double ld;
ld pi = acos(-1), d;
struct node{
	ld x, y, r;
	void get() { cin >> x >> y >> r; }
}a, b;

ld sqr(ld x) { return x * x; }
ld dis(node a, node b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

ld get(node a, node b){
	ld ang = acos((sqr(b.r) + sqr(d) - sqr(a.r)) / (2 * b.r * d));
	ld s = ang * sqr(b.r);
	ld t = sqr(b.r) * sin(ang) * cos(ang);
	return s - t;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	a.get(), b.get();
	if(a.r < b.r) swap(a, b);
	d = dis(a, b);
	if(a.r + b.r <= d) cout << 0;
	else if(a.r >= d + b.r) printf("%.10f\n", float(pi * sqr(b.r)));
	else printf("%.10f\n", float(get(a, b) + get(b, a)));
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