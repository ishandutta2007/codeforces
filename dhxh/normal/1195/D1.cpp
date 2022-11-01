#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 998244353;
const int maxn = 1e5 + 5;

long long n, m, t;
long long a[maxn];

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

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	long long x, y;
	long long ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		x = a[i];
		y = 0;
		j = 1;
		while(x){
			y = (y + (x % 10) * j) % mod;
			x /= 10;
			j = j * 100 % mod;
		}
		ans = (ans + y * n) % mod;
		
		x = a[i];
		y = 0;
		j = 10;
		while(x){
			y = (y + (x % 10) * j) % mod;
			x /= 10;
			j = j * 100 % mod;
		}
		ans = (ans + y * n) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}