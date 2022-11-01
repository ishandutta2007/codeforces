#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n;

long long L[maxn];
long long R[maxn];
long long p[maxn];

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		x >>= 1;
		b = b * b % mod;
	}
	
	return ret;
}

int main(){
	int i, j;
	long long ans = 0;
	long long sum = 0;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &L[i]);
	}
	
	for(i=1;i<=n;i++){
		scanf("%lld", &R[i]);
	}
	
	for(i=1;i<=n;i++){
		p[i] = (mod + 1 - max(0ll, min(R[i], R[i - 1]) - max(L[i], L[i - 1]) + 1) * qpow((R[i] - L[i] + 1) * (R[i - 1] - L[i - 1] + 1) % mod, mod - 2) % mod) % mod;
		ans = (ans - p[i] * p[i] + p[i]) % mod;
		ans = (ans + mod) % mod;
		sum += p[i];
	}
	
	sum %= mod;
	
	ans = (ans + sum * sum) % mod;
	
	for(i=2;i<=n;i++){
		ans = (ans - 2ll * p[i] * p[i - 1] % mod + mod) % mod;
		long long x = 1 - (1 - p[i]) - (1 - p[i - 1]) + max(0ll, min(min(R[i], R[i - 1]), R[i - 2]) - max(max(L[i], L[i - 1]), L[i - 2]) + 1)
					* qpow((R[i] - L[i] + 1) * (R[i - 1] - L[i - 1] + 1) % mod * (R[i - 2] - L[i - 2] + 1) % mod, mod - 2) % mod;
		ans += 2ll * x;
		ans %= mod;
	}
	
	printf("%lld\n", (ans + mod) % mod);
	
	return 0;
}