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
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 300100;
int n;
ll t[maxn], w[maxn];
vector<ll> qt;
vector<pair<ll, ll> > q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld%lld", t + i, w + i);
		w[i] -= t[i] - 1;
		q.pb(mkp(t[i], i));
		qt.pb(t[i]);
	}
	sort(all(q));
	sort(all(qt));
	reverse(all(q));
	qt.erase(unique(all(qt)), qt.end());
	reverse(all(qt));

	int i = 0;
	int ans = n;
	priority_queue<ll> L, R;
	ll now = 0;
	qt.pb(0);
	for(auto tt : qt){
		while(i < n && q[i].fi > tt){
			if(q[i].se != 1){
				R.push(-w[q[i].se]);
				while(L.size() && -R.top() < L.top()){
					ll lt = L.top(); L.pop();
					ll rt = -R.top(); R.pop();
					now -= lt - rt;
					L.push(rt); R.push(-lt);
				}
			}
			i++;
		}
		if(tt > t[1]) continue;
		while(R.size() && now - R.top() <= t[1] - tt){
			ll rt = -R.top(); R.pop();
			now += rt;
			L.push(rt);
		}
		ans = min(ans, (int)R.size() + 1);
	}
	printf("%d\n", ans);
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