#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

long long mod = 998244353;

int n, m, t;

long long a[maxn];
long long b[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(long long x, long long y){
	return x > y;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		a[i] *= 1ll * i * (n - i + 1);
	}
	
	for(i=1;i<=n;i++){
		b[i] = read();
	}
	
	sort(b + 1, b + n + 1);
	
	sort(a + 1, a + n + 1, cmp);
	
	long long ans = 0;
	
	for(i=1;i<=n;i++){
		ans = (ans + a[i] % mod * b[i] % mod) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}