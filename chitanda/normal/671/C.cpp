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

const int maxn = 200100;
set<pair<int, int> >S;
vector<int> g[maxn];
int n, a[maxn];
ll area;

void update(int x, int y){
	if(x > n) return;
	auto i = S.lower_bound({x, y});
	auto j = i; j--;
	if(j->se > y){
		area += (ll)(i->fi - x) * j->se;
		while(y < i->se){
			auto k = i;
			i++; if(i == S.end()) break;
			area += (ll)(i->fi - k->fi) * k->se;
			S.erase(k);
		}
		area -= (ll)(i->fi - x) * y;
		if(x < i->fi) S.emplace(x, y);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		g[a[i]].pb(i);
	}
	int m = *max_element(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = 0; i <= n + 1; i++) S.emplace(i, n - i + 1);

	for(int d = m; d >= 1; --d){
		vector<int> q;
		for(int i = d; i <= m; i += d)
			for(auto&& v : g[i]) q.pb(v);
		int s = q.size();
		if(s >= 2){
			sort(all(q));
			update(1, n - q[s - 2] + 1);
			update(q[0] + 1, n - q[s - 1] + 1);
			update(q[1] + 1, 0);
		}
		ans += area;
	}
	
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