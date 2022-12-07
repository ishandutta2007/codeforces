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
#define M 1000000007

const int maxn = 200100;
int n, k, l[maxn], r[maxn], d[3 * maxn], fac[maxn], inv[maxn];

int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

int C(int n, int m){
	return (ll)fac[n] * inv[m] % M * inv[n - m] % M;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % M;
	inv[n] = pow(fac[n], M - 2);
	for(int i = n - 1; i >= 0; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % M;
	vector<int> q;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", l + i, r + i);
		q.pb(l[i]);
		q.pb(r[i]);
		q.pb(r[i] + 1);
	}
	sort(all(q));
	q.erase(unique(all(q)), q.end());
	for(int i = 1; i <= n; ++i){
		l[i] = lower_bound(all(q), l[i]) - q.begin();
		r[i] = lower_bound(all(q), r[i]) - q.begin();
		d[l[i]]++;
		d[r[i] + 1]--;
	}
	int now = 0, ans = 0;
	for(int i = 0; i <= q.size(); ++i){
		if(now >= k){
			(ans += (ll)C(now, k) * (q[i] - q[i - 1]) % M) %= M;
		}
		now += d[i];
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