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
inline ll ckmax(ll &a, ll b) { return a < b ? a = b, 1 : 0; }
inline ll ckmin(ll &a, ll b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))

const ll BOUND = (ll)1e18;
ll ansx, ansy, ansz;
ll high[4], low[4];

ll div2(ll n){
	return n >= 0 ? n / 2 : (n - 1) / 2;
}

pair<ll, ll> helper(ll *low, ll *high, ll d, ll x){
	auto l = max(max(low[0] - d + x, low[1] - d - x), -2 * BOUND);
	auto h = min(min(high[0] + d + x, high[1] + d - x), 2 * BOUND);
	return mkp(l, min(l + 1, h));
}

bool check(ll d){
	for(int i = 0; i < 4; ++i)
		if(low[i] - d > high[i] + d) return 0;
	
	ll x_low_1 = max(div2(low[1] - high[0] + 1) - d, -BOUND);
	ll x_high_1 = min(div2(high[1] - low[0]) + d, BOUND);
	ll x_low_2 = max(div2(low[3] - high[2] + 1) - d, -BOUND);
	ll x_high_2 = min(div2(high[3] - low[2]) + d, BOUND);
	ll x_low = max(x_low_1, x_low_2);
	ll x_high = min(x_high_1, x_high_2);
	if(x_low > x_high) return 0;
	x_high = min(x_high, x_low + 1);
	for(ll x = x_low; x <= x_high; ++x){
		auto sum_range = helper(low, high, d, x);
		auto sub_range = helper(low + 2, high + 2, d, x);
		for(ll sum = sum_range.fi; sum <= sum_range.se; ++sum)
			for(ll sub = sub_range.fi; sub <= sub_range.se; ++sub)
				if(~(sum - sub) & 1){
					ansx = x;
					ansy = (sum + sub) / 2;
					ansz = (sum - sub) / 2;
					return 1;
				}
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	int T, n;
	cin >>T;
	while(T--){
		cin >> n;			
		ll h = 0;
		memset(low, 128, sizeof(low));
		memset(high, 127, sizeof(high));
		for(int i = 0; i < n; ++i){
			ll x, y, z;
			cin >> x >> y >> z;
			ckmax(h, abs(x) + abs(y) + abs(z));
			ckmax(low[0], -x + y + z);
			ckmin(high[0], -x + y + z);
			ckmax(low[1], x + y + z);
			ckmin(high[1], x + y + z);
			ckmax(low[2], -x + y - z);
			ckmin(high[2], -x + y - z);
			ckmax(low[3], x + y - z);
			ckmin(high[3], x + y - z);
		}
		ll l = -1; h++;
		while(l + 1 < h){
			ll m = l + ((h - l) >> 1);
			if(check(m)) h = m;
			else l = m;
		}
		check(h);
		cout << ansx << ' ' << ansy << ' ' << ansz << '\n';
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