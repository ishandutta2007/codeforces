#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e7 + 5;

long long inf = 0x3f3f3f3f3f3f3f3f;

long long n, l, r, t;

unsigned long long b[maxn], x, y, z;
long long a[maxn];

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		l = read();
		r = read();
		x = read();
		y = read();
		z = read();
		b[1] = read();
		b[2] = read();
		for(i=3;i<=n;i++){
			b[i] = (b[i - 2] * x % (unsigned long long)(1ll << 32) + b[i - 1] * y % (unsigned long long)(1ll << 32) + z) % (unsigned long long)(1ll << 32);
		}
		
		for(i=1;i<=n;i++){
			a[i] = ((long long)b[i] % (r - l + 1)) + l;
		}
		
		long long minx = a[1];
		long long maxx = a[n];
		long long ans = inf;
		bool flag = false;
		
		for(i=2;i<=n;i++){
			if(a[i] > minx){
				if(!flag){
					ans = a[i] * minx;
					flag = true;
				}else{
					ans = min(ans, a[i] * minx);
				}
			}
			minx = min(minx, a[i]);
		}
		
		for(i=n-1;i>0;i--){
			if(a[i] < maxx){
				if(!flag){
					ans = a[i] * maxx;
					flag = true;
				}else{
					ans = min(ans, a[i] * maxx);
				}
			}
			maxx = max(maxx, a[i]);
		}
		
		if(flag){
			printf("%lld\n", ans);
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	
	return 0;
}