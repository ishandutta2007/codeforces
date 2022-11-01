#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 6;
const int maxn = N + 5;
const int mod = 1e9 + 7;

long long fac[maxn], inv[maxn];

long long ans[maxn];

int n, m;

long long qpow(long long b, long long x){
	long long ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		b = b * b % mod;
		x >>= 1;
	}
	return ret;
}

void init(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=N;i++) fac[i] = fac[i - 1] * i % mod;
	inv[N] = qpow(fac[N], mod - 2);
	for(int i=N;i>0;i--) inv[i - 1] = inv[i] * i % mod;
}

long long C(int n, int m){
	if(n < m) return 0;
	return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

int main(){
	int i, j;
	init();
	
	scanf("%d%d", &n, &m);
	
	long long inv3 = qpow(3, mod - 2);
	ans[0] = n + 1, ans[1] = 3ll * (n + 1) * n / 2 % mod;
	for(i=2;i<=3*n;i++){
		ans[i] = (C(3 * n + 3, i + 1) - 3 * ans[i - 1] - ans[i - 2] + 4ll * mod) * inv3 % mod;
	}
	
	while(m--){
		int x;
		scanf("%d", &x);
		printf("%lld\n", ans[x]);
	}
	
	return 0;
}