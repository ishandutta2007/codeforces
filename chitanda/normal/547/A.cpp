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

int m, h1, a1, x1, yy1, h2, a2, x2, y2;
int cnt[1001000];

pair<int, int> get(int h, int x, int y, int a){
	memset(cnt, -1, sizeof(cnt));
	cnt[h] = 0;
	int cyc = 0;
	for(int i = 1; i <= m; ++i){
		h = ((ll)x * h + y) % m;
		if(cnt[h] != -1) { cyc = i; break; }
		else cnt[h] = i;
	}
	if(cnt[a] == -1) { cout << -1; exit(0); }
	if(cnt[a] < cnt[h]) return mkp(cnt[a], 0);
	return mkp(cnt[a], cyc - cnt[h]);
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}//ax+by=d

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> m;
	cin >> h1 >> a1;
	cin >> x1 >> yy1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
	auto a = get(h1, x1, yy1, a1);
	auto b = get(h2, x2, y2, a2);
	ll x, y, d;
	exgcd(a.se, b.se, d, x, y);
	if(abs(a.fi - b.fi) % d != 0) { cout << -1; return 0; }
	x *= (b.fi - a.fi) / d;
	y *= (b.fi - a.fi) / d;
	ll k1 = b.se / d, k2 = a.se / d;
	if(x < 0){
		if(!k1) { cout << -1; return 0; }
		int t = ((-x - 1)/ k1) + 1;
		x += t * k1;
		y -= t * k2;
	}
	if(y > 0){
		if(!k2) { cout << -1; return 0; }
		int t = ((y - 1) / k2) + 1;
		x += t * k1;
		y -= t * k2;
	}
	if(x - k1 >= 0 && y + k2 <= 0){
		ll t = min(x / k1, -y / k2);
		x -= t * k1, y += t * k2;
	}
	cout << a.fi + x * a.se;
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