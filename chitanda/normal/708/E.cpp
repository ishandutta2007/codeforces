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

const int maxn = 2000, maxk = 100100;
int n, m, a, b, k;
int fac[maxk], p[maxn], sum_p[maxn], s[maxn], f[maxn], pref[maxn];

int power(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

int C(int n, int m){
	return (ll)fac[n] * power(fac[m], M - 2) % M * power(fac[n - m], M - 2) % M;
}

int add(int a, int b){
	a += b;
	return a >= M ? a - M : a;
}

int mul(int a, int b){
	return (ll)a * b % M;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &a, &b);
	scanf("%d", &k);
	int pos = mul(a, power(b, M - 2));
	int re_pos = add(1, M - pos);

	fac[0] = 1;
	for(int i = 1; i <= k; ++i) fac[i] = mul(fac[i - 1], i);
	
	int now = 0;
	for(int i = 0; i <= min(m, k); ++i){
		p[i] = mul(C(k, i), mul(power(pos, i), power(re_pos, k - i)));
		sum_p[i] = now = add(now, p[i]);
	}

	for(int i = 1; i <= m; ++i) f[i] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < m; ++j) s[j] = add(s[j - 1], mul(p[j], f[m - j])), pref[j + 1] = f[j + 1];
		for(int j = 0; j < m; ++j)
			f[j + 1] = add(f[j], mul(p[j], add(mul(sum_p[m - j - 1], add(pref[m - j], -pref[m] + M)), s[m - j - 1])));
	}
	
	printf("%d\n", f[m]);
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