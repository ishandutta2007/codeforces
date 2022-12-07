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
#define M 1000000007

int n, m, t;
int fac[100100], inv[100100], f[100100], ans[100100];
vector<pair<int, int> >g[100100];
char s[100100];

int mul(int a, int b){
	return (int)((ll)a * b % M);
}

int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = mul(a, a))
		if(b & 1) ans = mul(ans, a);
	return ans;
}

int C(int n, int m){
	return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> m;
	scanf("%s", s);
	int k = strlen(s), tt = 0;
	while(m--){
		scanf("%d", &t);
		if(t == 1){
			scanf("%s", s);
			k = strlen(s);
		}else{
			scanf("%d", &n);
			g[k].pb(mkp(++tt, n));
		}
	}
	fac[0] = 1;
	for(int i = 1; i <= 100000; i++) fac[i] = mul(fac[i - 1], i);
	inv[100000] = pow(fac[100000], M - 2);
	for(int i = 99999; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);

	for(int i = 1; i <= 100000; i++)
		if(g[i].size()){
			memset(f, 0, sizeof(f));
			f[i] = 1;
			int t = 25;
			for(int j = i + 1; j <= 100000; t = mul(t, 25), j++)
				f[j] = ((ll)f[j - 1] * 26 % M + mul(C(j - 1, i - 1), t)) % M;
			for(auto&& x : g[i])
				ans[x.fi] = f[x.se];
		}
	for(int i = 1; i <= tt; i++) printf("%d\n", ans[i]);
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