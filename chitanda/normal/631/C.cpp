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

const int maxn = 200100;
int n, m, top, t, r, a[maxn], b[maxn];
pair<int, int> q[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, n) scanf("%d", a + i);
	FOR(i, 1, m){
		scanf("%d%d", &t, &r);
		while(top && r >= q[top].fi) q[top--] = mkp(0, 0);
		if(!top || t != q[top].se) q[++top] = mkp(r, t);
	}
	sort(a + 1, a + q[1].fi + 1);
	for(int i = 1, l = 1, r = q[1].fi, tt = q[1].fi; i <= top; i++)
		if(q[i].se == 2){
			for(int j = 0; j < q[i].fi - q[i + 1].fi; j++) b[tt--] = a[l + j];
			l += q[i].fi - q[i + 1].fi;
		}else{
			for(int j = 0; j < q[i].fi - q[i + 1].fi; j++) b[tt--] = a[r - j];
			r -= q[i].fi - q[i + 1].fi;
		}
	for(int i = 1; i <= q[1].fi; i++) printf("%d ", b[i]);
	for(int i = q[1].fi + 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
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