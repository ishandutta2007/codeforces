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

ll n;
const int N = 1e7;
const int M1 = 1e5, M2 = 1e2;
const int maxn = N + 10;
bool nop[maxn];
int pri[N], tot, cnt[maxn];
int dp[M1][M2];

void pre(){
	for(int i = 2; i <= N; ++i){
		cnt[i] = cnt[i - 1];
		if(!nop[i]) pri[++tot] = i, cnt[i]++;
		for(int j = 1; j <= tot && pri[j] * i <= N; ++j){
			nop[pri[j] * i] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	
	for(int j = 1; j < M2; ++j)
		for(int i = 1; i < M1; ++i){
			if(j == 1) dp[i][j] = i;
			else dp[i][j] = dp[i][j - 1] - dp[i / pri[j - 1]][j - 1];
		}
}

ll pi(ll n, int m){
	if(m == 1) return n;
	if(pri[m - 1] >= n) return 1;
	if(n < M1 && m < M2) return dp[n][m];
	return pi(n, m - 1) - pi(n / pri[m - 1], m - 1);
}

ll solve(ll n){
	if(n <= N) return cnt[n];
	int s = sqrt(n + 0.5), y = cbrt(n + 0.5);
	int a = cnt[y] + 1; ll res = pi(n, a) + a - 1;
	for(int i = a; pri[i] <= s; ++i) res -= solve(n / pri[i]) - solve(pri[i - 1]);
	return res - 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	cin >> n;
	pre();
	
	ll res = 0;
	for(int i = 1; i <= tot; ++i){
		ll x = pri[i];
		if(x * x * x > n) break;
		res++;
	}

	for(int i = 1; i <= tot; ++i){
		ll x = pri[i];
		if(x * x >= n) break;
		res += solve(n / x) - solve(x);
	}
	cout << res;
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