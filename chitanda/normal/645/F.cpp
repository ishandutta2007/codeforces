//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define M 1000000007

int n, k, q, x, tot, ans;
int cal[1000100], la[1000100];
bool nop[1000100];
int phi[1000100], pri[1000100], A[1000100], B[1000100];
vector<int> g[1000100];

void pre(){
	ll ta;
	phi[1] = 1;
	for(int i = 2; i <= 1000000; i++){
		if(!nop[i]) pri[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && (ta = (ll) i * pri[j]) <= 1000000; j++){
			nop[ta] = 1;
			if(i % pri[j]) phi[ta] = phi[i] * (pri[j] - 1); else{
				phi[ta] = phi[i] * pri[j];
				break;
			}
		}
	}
	for(int i = 1; i <= 1000000; i++)
		for(int j = i; j <= 1000000; j += i)
			g[j].pb(i);
}

int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

inline int C(int n, int m){
	if(m > n) return 0;
	return (ll)A[n] * B[m] % M * B[n - m] % M;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	cin >> n >> k >> q;
	A[0] = B[0] = 1;
	for(int i = 1; i <= 1000000; i++) A[i] = (A[i - 1] * (ll)i) % M, B[i] = pow(A[i], M - 2);
	pre();
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		for(auto v : g[x]){
			cal[v]++;
			(ans += (ll)phi[v] * C(cal[v] - 1, k - 1) % M) %= M;
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%d", &x);
		for(auto v : g[x]){
			cal[v]++;
			(ans += (ll)phi[v] * C(cal[v] - 1, k - 1) % M) %= M;
		}
		printf("%d\n", ans);
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