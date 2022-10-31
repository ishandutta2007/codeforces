#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n, m, t;

long long fac[maxn];
long long sum[maxn];

long long a[maxn];

long long ans = 0;

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
		
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

int init(){
	long long i, j;
	
	fac[1] = 1;
	
	for(i=2;i<=n;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	return 0;
}

int main(){
	int i, j;
	int l, x;
	
	n = read();
	
	init();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	x = n;
	
	while(a[x] == a[x - 1]){
		x--;
	}
	
	for(i=1;i<x;i++){
		if(a[i] != a[i - 1]){
			l = i;
		}
		
		ans = (ans + a[i] * fac[n] % mod * qpow(n - l + 1, mod - 2)) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}