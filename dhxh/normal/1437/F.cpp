#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 5;
const int mod = 998244353;

int n;
int a[maxn];

long long f[maxn];
long long fac[maxn];
long long inv[maxn];

int p[maxn];

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

long long A(int n, int m){
	return fac[n] * inv[n - m] % mod;
}

int main(){
	int i, j;
	
	fac[0] = inv[0] = 1;
	for(i=1;i<=5000;i++) fac[i] = fac[i - 1] * i % mod;
	inv[5000] = qpow(fac[5000], mod - 2);
	for(i=5000;i>1;i--) inv[i - 1] = inv[i] * i % mod; 
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	for(i=1;i<=n;i++){
		p[i] = p[i - 1];
		while(2 * a[p[i] + 1] <= a[i]){
			p[i]++;
		}
	}
	
	p[0] = -1;
	f[0] = 1;
	
	for(i=1;i<=n;i++){
		for(j=0;j<=p[i];j++){
			f[i] = (f[i] + f[j] * A(n - p[j] - 2, p[i] - p[j] - 1)) % mod;
		}
	}
	
	if(p[n] != n - 1) f[n] = 0;
	
	printf("%lld\n", f[n]);
	
	return 0;
}