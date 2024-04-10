#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;
const int maxn = 1e5 + 5;

long long n, m, t;
long long inv;

int a[maxn];
int b[maxn];

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

int main(){
	int i, j;
	long long d = 1;
	long long ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<=n;i++){
		b[i] = read();
	}
	
	inv = qpow(m, mod - 2);
	
	for(i=1;i<=n;i++){
		if(a[i] == 0 and b[i] == 0){
			ans = (ans + ((m * (m - 1) / 2) % mod) * inv % mod * inv % mod * d % mod) % mod;
			d = d * inv % mod;
		}else if(a[i] == 0){
			ans = (ans + (m - b[i]) * inv % mod * d % mod) % mod;
			d = d * inv % mod;
		}else if(b[i] == 0){
			ans = (ans + (a[i] - 1) * inv % mod * d % mod) % mod;
			d = d * inv % mod;
		}else{
			if(a[i] > b[i]){
				ans = (ans + d) % mod;
				break;
			}
			if(a[i] != b[i]){
				break;
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}