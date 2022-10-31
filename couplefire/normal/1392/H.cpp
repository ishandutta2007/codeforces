#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2000005;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return modpow(a, p - 1) * a % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}

int n, m;
long long f[MAXN], dp[MAXN], fact[2 * MAXN], invfact[2 * MAXN], inv[2 * MAXN];

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i <= n + m; i++){
		if(i == 0)fact[i] = 1;
		else fact[i] = i * fact[i - 1] % MOD;
	}
	for(int i = n + m; i >= 0; i--){
		if(i == n + m)invfact[i] = modinv(fact[n + m]);
		else invfact[i] = (i + 1) * invfact[i + 1] % MOD;
	}
	
	for(int i = 1; i <= n + m; i++)
		inv[i] = invfact[i] * fact[i - 1] % MOD;
	
	for(int i = 0; i <= n; i++){
		if(i == 0)f[i] = 0;
		else f[i] = i * inv[m + i] % MOD * (1 + f[i - 1]) % MOD;
	}
	
	long long sum = 0;
	for(int i = 0; i <= n; i++){
		if(i == 0){
			dp[i] = 0;
		}else{
			sum = sum * i % MOD * inv[m + i] % MOD;
			dp[i] = (f[n - i] + 1 + sum) % MOD;
			dp[i] = dp[i] * (i + m) % MOD * inv[i] % MOD;
			sum = (sum + dp[i] * m % MOD * inv[m + i]) % MOD;
		}
	}

	printf("%lld\n", (dp[n] + n) % MOD);
	
	return 0;
}