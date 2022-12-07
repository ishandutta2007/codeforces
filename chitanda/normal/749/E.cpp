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

int n, x;
ll c[100100];
int d[100100];

void add(int x, int y){
	for(; x <= n; x += x & -x) c[x] += y, d[x]++;
}

pair<ll, int> ask(int x){
	ll ans = 0; int cnt = 0;
	for(; x; x -= x & -x) ans += c[x], cnt += d[x];
	return mkp(ans, cnt);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	double ans = 0;
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		auto t = ask(x);
		ans += 1. * t.fi * (n - i + 1) / n / (n + 1);
		ans += i - 1 - t.se - 1. * ((ll)i * (i - 1) / 2 - t.fi) * (n - i + 1) / n / (n + 1);
		add(x, i);
	}

	printf("%.10f\n", ans);
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