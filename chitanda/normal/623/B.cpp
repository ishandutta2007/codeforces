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

const int maxn = 1000100;
int n, x, y, a[maxn], tk;
ll ans = 1LL << 60, f[maxn], g[maxn];

void figure(int k, int tt){
	memset(f, 127, sizeof(f));
	memset(g, 127, sizeof(g));
	f[tk] = g[tk] = 0;
	ll tm = 0;
	for(int j = tk + 1; j <= n; j++){
		int t = a[j] % k;
		if(t <= 1 || t == k - 1){
			f[j] = f[j - 1] + y * (t != 0);
			g[j] = g[j - 1] + y * (t != 0);
		}
		tm = min(tm + x, f[j]);
		g[j] = min(g[j], tm);
	}
	ans = min(ans, g[n] + tt);
}

void work(){
	int li = (int)sqrt(a[1] + 1);
	for(int i = 1; i <= n; i++) if(a[i]) { tk = i; break; }
	int num = a[tk];
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, 0);
		}
	if(num > 1) figure(num, 0);
	num = a[tk] + 1;
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, y);
		}
	if(num > 1) figure(num, y);
	if(a[tk] <= 2) return;
	num = a[tk] - 1;
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, y);
		}
	if(num > 1) figure(num, y);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	work();
	reverse(a + 1, a + n + 1);
	work();
	ans = min(ans, (ll)y * n);
	cout << ans << endl;
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