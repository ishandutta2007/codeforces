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

const ll inf = 1LL << 60;
int N, M, k, x, y;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}//ax+by=d

ll work(int a, int b){
	if(a == N || b == M) return inf;
	int a1 = N, a2 = M;
	int b1 = a, b2 = b;
	int c = b2 - b1;
	ll x, y, d;
	exgcd(a1, a2, d, x, y);
	if(c % d != 0){
		return inf;
	}
	x *= c / d, y *= c / d;
	if(x < 0){
		ll k = a2 / d;
		ll tt = ((-x) + (k - 1)) / k;
		x += k * tt;
	}
	if(y > 0){
		ll k = a1 / d;
		ll tt = (y + (k - 1)) / k;
		y -= k * tt;
	}
	ll k1 = a2 / d, k2 = a1 / d;
	ll tt = min(x / k1, (-y) / k2);
	x -= k1 * tt, y += k2 * tt;
	ll tim = a1 * x + b1;
	return tim;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &N, &M, &k);
	N *= 2, M *= 2;
	
	while(k--){
		scanf("%d%d", &x, &y);
		ll ans = min(min(work(x, y), work(x, M - y)),
									min(work(N - x, y), work(N - x, M - y)));
		printf("%lld\n", ans < inf ? ans : -1);
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