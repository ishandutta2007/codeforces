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

const int maxn = 100100;
int n, k;
int x[maxn], y[maxn];
vector<int> wy;
vector<pair<int, int>> wx;
ll ans[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		wx.pb(mkp(x[i], i << 1));
		wx.pb(mkp(x[i] + k, (i << 1) | 1));
		wy.pb(y[i]);
		wy.pb(y[i] + k);
	}
	sort(all(wy));
	wy.erase(unique(all(wy)), wy.end());
	sort(all(wx));
	int l = wy.size();
	vector<pair<int, int>> mark(l + 1);
	for(int i = 0, j; i < (int)wx.size(); i = j){
		j = i;
		while(j < (int)wx.size() && wx[j].fi == wx[i].fi){
			int delta = wx[j].se & 1 ? -1 : 1;
			int id = wx[j].se >> 1;
			int begin = lower_bound(all(wy), y[id]) - wy.begin();
			for(int p = begin; p < l && wy[p] < y[id] + k; ++p){
				if(mark[p].fi)
					ans[mark[p].fi] += (ll)(wy[p + 1] - wy[p]) * (wx[i].fi - mark[p].se);
				mark[p].fi += delta;
				mark[p].se = wx[i].fi;
			}
			j++;
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
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