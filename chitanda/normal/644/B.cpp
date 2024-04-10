//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

int n, b, t, d;
ll ans[200100];
queue<pair<pair<ll, ll>, int> > q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	cin >> n >> b;
	ll T = 0;
	FOR(i, 1, n){
		scanf("%d%d", &t, &d);
		while(q.size() && max(T, q.front().fi.fi) + q.front().fi.se <= t)
			ans[q.front().se] = T = max(T, q.front().fi.fi) + q.front().fi.se, q.pop();
		if(q.size() <= b) q.push(mkp(mkp(t, d), i)); else ans[i] = -1;
	}
	while(q.size())
		ans[q.front().se] = T = max(T, q.front().fi.fi) + q.front().fi.se, q.pop();
	FOR(i, 1, n) printf("%I64d ", ans[i]);
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