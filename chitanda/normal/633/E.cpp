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

const int maxn = 1000100;
int n, k;
int v[maxn], c[maxn], get[maxn], MAX[maxn][20], MIN[maxn][20], p[maxn];

int getmax(int l, int r){
	int k = get[r - l + 1];
	return max(MAX[l][k], MAX[r - (1 << k) + 1][k]);
}

int getmin(int l, int r){
	int k = get[r - l + 1];
	return min(MIN[l][k], MIN[r - (1 << k) + 1][k]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k;
	FOR(i, 1, n) scanf("%d", v + i), MAX[i][0] = (v[i] *= 100);
	FOR(i, 1, n) scanf("%d", c + i), MIN[i][0] = c[i];
	FOR(kk, 1, 19)
		FOR(i, 1, n)
		if(i + (1 << kk) - 1 <= n){
			MAX[i][kk] = max(MAX[i][kk - 1], MAX[i + (1 << (kk - 1))][kk - 1]);
			MIN[i][kk] = min(MIN[i][kk - 1], MIN[i + (1 << (kk - 1))][kk - 1]);
		}
	FOR(i, 0, 19) get[1 << i] = i;
	FOR(i, 3, n) if(!get[i]) get[i] = get[i - 1];
	FOR(i, 1, n){
		if(v[i] >= c[i]) { p[i] = c[i]; continue; }
		int l = i, r = n + 1;
		while(r - l > 1){
			int m = (l + r) >> 1;
			if(getmax(i, m) < getmin(i, m)) l = m; else r = m;
		}
		p[i] = max(getmax(i, l), getmin(i, r));
	}
	sort(p + 1, p + n + 1);
	double t = 1. * k / n, ans = 0;
	FOR(i, 1, n){
		if(i > 1) t = t * (n - k - i + 2) / (n - i + 1);
		ans += t * p[i];
	}
	printf("%.8f\n", ans);
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