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

struct edge{
	int x, y, xx, yy;
};
vector<edge> ans;

void solve(ll n){
	for(int i = 0; i < 37; ++i){
		ans.pb({1 + i, 4 + i, 2 + i, 4 + i});
		ans.pb({4 + i, 1 + i, 4 + i, 2 + i});
		if(i < 36){
			ans.pb({1 + i, 5 + i, 1 + i, 6 + i});
			ans.pb({5 + i, 1 + i, 6 + i, 1 + i});
		}
		if(i){
			ans.pb({i, 5 + i, 1 + i, 5 + i});
			ans.pb({5 + i, i, 5 + i, 1 + i});
		}
	}
	ans.pb({39, 40, 39, 41});
	ans.pb({40, 40, 40, 41});
	ans.pb({40, 40, 41, 40});
	ans.pb({40, 39, 41, 39});

	for(int i = 0; i <= 37; ++i){
		int x = n % 3;
		n /= 3;
		if(x < 2) ans.pb({1 + i, 3 + i, 1 + i, 4 + i});
		if(x < 1) ans.pb({3 + i, 1 + i, 4 + i, 1 + i});
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	ll n;
	cin >> n;
	solve(n);
	printf("%d %d\n", 41, 41);
	printf("%d\n", ans.size());
	for(auto e : ans) printf("%d %d %d %d\n", e.x, e.y, e.xx, e.yy);
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