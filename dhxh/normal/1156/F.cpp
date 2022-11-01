#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5005;
long long mod = 998244353;

int n, m, t;

long long inv[maxn];
long long cnt[maxn];

long long f[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

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
	int x, y;
	long long ans = 0;
	
	for(i=1;i<=5000;i++){
		inv[i] = qpow(i, mod - 2);
	}
	
	n = read();
	
	for(i=1;i<=n;i++){
		x = read();
		cnt[x]++;
	}
	
	for(i=1;i<=n;i++){
		f[i][1] = cnt[i] * inv[n] % mod;
		if(cnt[i] > 1)ans += cnt[i] * (cnt[i] - 1) % mod * inv[n] % mod * inv[n - 1] % mod;
		ans %= mod;
		f[i][1] += f[i - 1][1];
		for(j=2;j<=n;j++){
			f[i][j] = f[i - 1][j - 1] * cnt[i] % mod * inv[n - j + 1] % mod;
			if(cnt[i] > 1)ans += f[i - 1][j - 1] * cnt[i] % mod * (cnt[i] - 1) % mod * inv[n - j + 1] % mod * inv[n - j] % mod;
			ans %= mod;
			f[i][j] += f[i - 1][j];
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}