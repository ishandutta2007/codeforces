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

int n, k;
double p[20], f[1 << 20], ans[20];

void calc(){
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i = 1; i < 1 << n; ++i){
		double tmp = 0; int tot = 0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j)){
				tmp += p[j];
				tot++;
			}
		if(tot > k) continue;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j)){
				if(fabs(p[j]) < 1e-6) continue;
				double ret = 1 - tmp + p[j];
				f[i] += f[i ^ (1 << j)] * p[j] / ret;
				ans[j] += f[i ^ (1 << j)] * p[j] / ret;
			}
	}
	for(int i = 0; i < n; ++i) printf("%.8f ", ans[i]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) scanf("%lf", p + i);
	calc();
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