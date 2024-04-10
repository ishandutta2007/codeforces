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

const int delta_x[] = {-1, 0, 0, 1};
const int delta_y[] = {0, -1, 1, 0};
int T, x[4], y[4], xx[4], yy[4], x_low[2], x_high[2], y_low[2], y_high[2], X[2], Y[2];

void update_range(int &low, int &high, int dx, int x0, int max_t){
	if(dx < 0){
		low = max(low, x0 - max_t);
		high = min(high, x0);
	}else if(dx == 0){
		low = max(low, x0);
		high = min(high, x0);
	}else{
		low = max(low, x0);
		high = min(high, x0 + max_t);
	}
}

pair<int, int> solve(int *low, int *high){
	int range_l = max(1, low[1] - high[0]);
	int range_h = high[1] - low[0];
	return {range_l, range_h};
}

bool check(int max_t){
	for(int d0 = 0; d0 < 4; ++d0)
		for(int d1 = 0; d1 < 4; ++d1)
			for(int d2 = 0; d2 < 4; ++d2)
				for(int d3 = 0; d3 < 4; ++d3){
					int d[4] = {d0, d1, d2, d3};
					vector<int> c(4);
					iota(c.begin(), c.end(), 0);
					do{
						x_low[0] = x_low[1] = y_low[0] = y_low[1] = -1e9;
						x_high[0] = x_high[1] = y_high[0] = y_high[1] = 1e9;

						for(int i = 0; i < 4; ++i){
							int x_id = c[i] >> 1;
							int y_id = c[i] & 1;
							update_range(x_low[x_id], x_high[x_id], delta_x[d[i]], x[i], max_t);
							update_range(y_low[y_id], y_high[y_id], delta_y[d[i]], y[i], max_t);
						}
						
						bool valid = 1;
						valid &= x_low[0] <= x_high[0];
						valid &= x_low[1] <= x_high[1];
						valid &= y_low[0] <= y_high[0];
						valid &= y_low[1] <= y_high[1];
						if(!valid) continue;
						
						auto range_x = solve(x_low, x_high);
						auto range_y = solve(y_low, y_high);
						if(max(range_x.fi, range_y.fi) <= min(range_x.se, range_y.se)){
							int l = max(range_x.fi, range_y.fi);
							X[0] = max(x_low[0], x_low[1] - l);
							X[1] = X[0] + l;
							Y[0] = max(y_low[0], y_low[1] - l);
							Y[1] = Y[0] + l;
							for(int i = 0; i < 4; ++i){
								int x_id = c[i] >> 1;
								int y_id = c[i] & 1;
								xx[i] = X[x_id];
								yy[i] = Y[y_id];
							}
							return 1;
						}
					}while(next_permutation(c.begin(), c.end()));
				}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 4; ++i) scanf("%d%d", x + i, y + i);
		int l = -1, r = 1e9;
		while(l + 1 < r){
			int m = (l + r) >> 1;
			if(check(m)) r = m; else l = m;
		}
		if(check(r)){
			printf("%d\n", r);
			for(int i = 0; i < 4; ++i) printf("%d %d\n", xx[i], yy[i]);
		}else puts("-1");
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