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

const int M = 3000000, maxn = M + 10;
int a[maxn], b[maxn], cnt[maxn], n, m, x, sum[maxn];
ll ans[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= M; ++i) sum[i] = sum[i - 1] + cnt[i];
	for(int i = 1; i <= M; ++i){
		int t = M / i;
		ans[M] += (ll)(n - sum[t]) * cnt[i];
		if(t < i){
			ans[M] -= cnt[i];
		}
	}
	for(int i = 1; i <= M; ++i){
		for(int j = 1; j * i <= M; ++j)
				ans[i * j] += (ll)cnt[i] * cnt[j];	
		if((ll)i * i <= M) ans[i * i] -= cnt[i];
	}
	for(int i = M - 1; i >= 1; --i) ans[i] += ans[i + 1];
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d", &x);
		printf("%lld\n", ans[x]);
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