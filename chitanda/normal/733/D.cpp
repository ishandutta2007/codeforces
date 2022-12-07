//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;

int n, x, y, z, ans, ansx, ansy;
map<pair<int, int>, int>mp, mpp;

void work(int x, int y, int z, int p, int q){
	int t = min(min(x, y), z);
	if(t > ans){
		ans = t;
		ansx = p, ansy = q;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d%d", &x, &y, &z);
		if(x > y) swap(x, y);
		if(x > z) swap(x, z);
		if(y > z) swap(y, z);

		if(mp.count(mkp(x, y))){
			int zz = mp[mkp(x, y)];
			work(x, y, zz + z, mpp[mkp(x, y)], i);
		}

		if(mp.count(mkp(x, z))){
			int yy = mp[mkp(x, z)];
			work(x, yy + y, z, mpp[mkp(x, z)], i);
		}

		if(mp.count(mkp(y, z))){
			int xx = mp[mkp(y, z)];
			work(xx + x, y, z, mpp[mkp(y, z)], i);
		}

		if(x > ans){
			ans = x;
			ansx = ansy = i;
		}
		
		if (ckmax(mp[mkp(x, y)], z)) mpp[mkp(x, y)] = i;
		if (ckmax(mp[mkp(x, z)], y)) mpp[mkp(x, z)] = i;
		if (ckmax(mp[mkp(y, z)], x)) mpp[mkp(y, z)] = i;
	}

	if(ansx == ansy) printf("1\n%d\n", ansx);
	else printf("2\n%d %d\n", ansx, ansy);
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