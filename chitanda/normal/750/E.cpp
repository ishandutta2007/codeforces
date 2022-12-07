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

const int maxn = 200100;

struct T{
	int a[6][6];
	T operator + (const T a) {
		T b;
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < 6; ++j){
				b.a[i][j] = 1e9;
				for(int k = 0; k < 6; ++k)
					b.a[i][j] = min(b.a[i][j], (*this).a[i][k] + a.a[k][j]);
			}
		return b;
	}
}dp[maxn * 4];

int n, q;
char s[maxn];

void build(int t, int l, int r){
	if(l == r){
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < 6; ++j)
				dp[t].a[i][j] = i == j ? 0 : 1e9;
		
		if(s[l] == '2'){
			dp[t].a[0][0] = 1;
			dp[t].a[0][1] = 0;
		}else if(s[l] == '0'){
			dp[t].a[1][1] = 1;
			dp[t].a[1][2] = 0;
		}else if(s[l] == '1'){
			dp[t].a[2][2] = 1;
			dp[t].a[2][3] = 0;
		}else if(s[l] == '6'){
			dp[t].a[3][3] = 1;
			dp[t].a[5][5] = 1;
			dp[t].a[3][4] = 0;
			dp[t].a[5][4] = 0;
		}else if(s[l] == '7'){
			dp[t].a[3][3] = 1;
			dp[t].a[3][5] = 0;
		}
						 
		return;
	}
	int mid = l + r >> 1;
	build(t << 1, l, mid);
	build((t << 1) + 1, mid + 1, r);
	dp[t] = dp[t << 1] + dp[(t << 1) + 1];
}

T query(int t, int l, int r, int x, int y){
	if (x <= l && y >= r) return dp[t];
	int mid = l + r >> 1;
	if (y <= mid) return query(t << 1, l, mid, x, y);
	if (x > mid) return query((t << 1) + 1, mid + 1, r, x, y);
	return query(t << 1, l, mid, x, y) + query((t << 1) + 1, mid + 1, r, x, y);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	build(1, 1, n);
	int l, r;
	while(q--){
		scanf("%d%d", &l, &r);
		int ans = query(1, 1, n, l, r).a[0][5];
		printf("%d\n", ans == 1e9 ? -1 : ans);
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