#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int a[310];
int fac[310], inv[310];
int f[2][310];
bool mark[310];

int qpow(int a, int b){
	int res = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) res = (ll)res * a % M;
	return res;
}

int C(int n, int m){
	return n < m ? 0 : (ll)fac[n] * inv[m] % M * inv[n - m] % M;
}

int main(){
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 300; ++i){
		fac[i] = (ll)fac[i - 1] * i % M;
		inv[i] = qpow(fac[i], M - 2);
	}
	

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	
	int t = 0;
	f[t][0] = 1;
	
	int now = 0, res = 1;
	for(int i = 1; i <= n; ++i)
		if(!mark[i]){
			int cnt = 1;
			for(int j = i + 1; j <= n; ++j){
				ll tmp = (ll)a[i] * a[j];
				ll sq = sqrt(tmp) + 0.1;
				if(sq * sq == tmp) cnt++, mark[j] = 1;
			}
			
			for(int i = 0; i <= now; ++i)
				for(int j = 1; j <= cnt; ++j){
					int tr = (ll)C(cnt - 1, cnt - j) * inv[j] % M;
					f[t ^ 1][i + j] = (f[t ^ 1][i + j] + (ll)tr * f[t][i]) % M;
				}
			memset(f[t], 0, sizeof(f[t]));
			
			now += cnt;
			t ^= 1;
			res = (ll)res * fac[cnt] % M;
		}
	int ans = 0;
	for(int i = 0; i <= now; ++i){
		int tr = f[t][i];
		if ((now - i) & 1) tr = M - tr;
		ans = (ans + (ll)fac[i] * tr) % M;
	}
	
	ans = (ll)ans * res % M;
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}