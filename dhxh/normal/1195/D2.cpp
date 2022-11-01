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
long long cnt[55];

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

long long count(long long x){
	if(x == 0)return 1;
	long long ret = 0;
	while(x){
		ret++;
		x /= 10;
	}
	return ret;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j, k, l;
	long long x, y;
	long long ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		cnt[count(a[i])]++;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=10;j++){
			x = a[i];
			k = 1;
			l = 0;
			y = 0;
			
			while(x){
				y = (y + (x % 10) * k) % mod;
				x /= 10;
				l++;
				k = k * 100 % mod;
				if(l >= j){
					y = (y + x * k) % mod;
					break;
				}
			}
			ans = (ans + y * cnt[j]) % mod;
			
			x = a[i];
			k = 10;
			l = 0;
			y = 0;
			
			while(x){
				l++;
				if(l >= j){
					y = (y + x * k) % mod;
					break;
				}
				y = (y + (x % 10) * k) % mod;
				x /= 10;
				k = k * 100 % mod;
			}
			ans = (ans + y * cnt[j]) % mod;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}