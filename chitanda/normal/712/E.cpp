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

const int maxn = 100100;
typedef pair<double, double> PA;
double p[maxn];
PA tmp[maxn * 4];

#define l1 a.fi
#define l2 b.fi
#define r1 a.se
#define r2 b.se
PA merge(PA a, PA b){
	return mkp(l1 * l2 * r1 / (1 - r1 * (1 - l2)),
						 r2 * (1 - r1 * (1 - l2)) / (1 - r1 * (1 - l2 * r2)));
}

inline void update(int t){
	tmp[t] = merge(tmp[t << 1], tmp[t << 1 | 1]);
}

void build(int t, int l, int r){
	if(l == r){
		tmp[t] = mkp(1, p[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(t << 1, l, mid);
	build(t << 1 | 1, mid + 1, r);
	update(t);
}

void modify(int t, int l, int r, int x, double y){
	if(l == r){
		tmp[t].se = y;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(t << 1, l, mid, x, y);
	else modify(t << 1 | 1, mid + 1, r, x, y);
	update(t);
}

PA query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r) return tmp[t];
	int mid = (l + r) >> 1;
	if(y <= mid) return query(t << 1, l, mid, x, y);
	else if(x > mid) return query(t << 1 | 1, mid + 1, r, x, y);
	else return merge(query(t << 1, l, mid, x, y), query(t << 1 | 1, mid + 1, r, x, y));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	int n, q, x, y, ty, z;
	scanf("%d%d", &n, &q);
	
	for(int i = 1; i <= n; ++i) scanf("%d%d", &x, &y), p[i] = (double)x / y;
	build(1, 1, n);
	
	while(q--){
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d%d%d", &x, &y, &z);
			modify(1, 1, n, x, (double)y / z);
		}else{
			scanf("%d%d", &x, &y);
			auto res = query(1, 1, n, x, y);
			printf("%.8f\n", res.fi * res.se);
		}
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