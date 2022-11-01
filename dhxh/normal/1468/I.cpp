#include <bits/stdc++.h>

using namespace std;

int n, m, t;

long long x, y, a, b;

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
	
	if(x * b == y * a){
		printf("NO\n");
		return 0;
	}
	
	long long l = __gcd(x, a);
	long long r;
	if(a and x){
		long long lcm = a * x / __gcd(a, x);
		r = lcm / a * b - lcm / x * y;
	}else if(a){
		r = y;
	}else if(x){
		r = b;
	}
	r = abs(r);
	l = abs(l);
	if(l * r == n){
		printf("YES\n");
		for(i=0;i<l;i++){
			for(j=0;j<r;j++){
				printf("%d %d\n", i, j);
			}
		}
	}else{
		printf("NO\n");
	}
	
	return 0;
}