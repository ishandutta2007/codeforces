#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int cnt[10005];
long long a[200005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % m;
		}
		b = b * b % m;
		x >>= 1;
	}
	return ret;
}

int main(){
	int i, j;
	int x, y;
	long long ans = 1;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = x = read();
		cnt[x % m]++;
		if(cnt[x % m] > 1){
			printf("0\n");
			return 0;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			ans = ans * abs(a[i] - a[j]) % m;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}