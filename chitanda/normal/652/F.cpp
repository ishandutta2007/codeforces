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

const int maxn = 300100;
int n, m, s[maxn], res[maxn];
char d[maxn];
pair<int, int> o[maxn];
ll t;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%lld", &n, &m, &t);
	FOR(i, 0, n - 1) scanf("%d %c", s + i, d + i), s[i]--, o[i] = mkp(s[i], i);
	sort(o, o + n);
	ll nc = 0;
	vector<ll> p;
	FOR(i, 0, n - 1){
		int dir = d[i] == 'L' ? -1 : 1;
		ll pos = s[i] + dir * t;
		ll g = pos > 0 ? pos / m : (pos - m + 1) / m;
		(nc += g) %= n;
		pos = ((pos % m) + m) % m;
		p.pb(pos);
	}
	nc = ((nc % n) + n) % n;
	sort(all(p));
	FOR(i, 0, n - 1) res[o[i].se] = p[(i + nc) % n];
	FOR(i, 0, n - 1) printf("%d ", res[i] + 1);
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