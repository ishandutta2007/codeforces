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
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 300100;
const long double pi = acos(-1.0);
int n, m, x, y, z;
struct seg{
	long double x, y, ang;
	seg(long double _x = 0., long double _y = 0., long double _a = 0.) : x(_x), y(_y), ang(_a) {}
}rmq[maxn * 8];

void update(int t){
	rmq[t] = seg(rmq[ls].x + rmq[rs].x * cos(rmq[ls].ang) - rmq[rs].y * sin(rmq[ls].ang), rmq[ls].y + 
							 rmq[rs].x * sin(rmq[ls].ang) + rmq[rs].y * cos(rmq[ls].ang), rmq[ls].ang + rmq[rs].ang);
}

void build(int t, int l, int r){
	if(l == r){
		rmq[t] = seg(1, 0, 0);
		return;
	}
	build(L);
	build(R);
	update(t);
}

void modify(int t, int l, int r, int x, int y){
	if(l == r){
		rmq[t].x += y * cos(rmq[t].ang);
		rmq[t].y += y * sin(rmq[t].ang);
		return;
	}
	if(x <= mid) modify(L, x, y);
	else modify(R, x, y);
	update(t);
}

void change(int t, int l, int r, int x, int y){
	if(l == r){
		long double cl = sqrt(pow(rmq[t].x, 2) + pow(rmq[t].y, 2));
		rmq[t].ang -= y * pi / 180;
		rmq[t].x = cl * cos(rmq[t].ang);
		rmq[t].y = cl * sin(rmq[t].ang);
		return;
	}
	if(x <= mid) change(L, x, y);
	else change(R, x, y);
	update(t);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1) modify(1, 1, n, y, z);
		else change(1, 1, n, y, z);
		printf("%.10f %.10f\n", (double)rmq[1].x, (double)rmq[1].y);
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