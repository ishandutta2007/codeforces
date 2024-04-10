#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 150000 + 5;

int n, m;

long long a[maxn];
long long b[maxn];

long long gcd(long long x, long long y){
	if(x % y){
		return gcd(y, x % y);
	}else{
		return y;
	}
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long t;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		b[i] = read();
	}
	
	t = a[1] * b[1] / gcd(a[1], b[1]);
	
	for(i=2;i<=n;i++){
		t = gcd(t, a[i]) * gcd(t, b[i]) / gcd(gcd(t, a[i]), gcd(t, b[i]));
	}
	
	for(i=1;i<=n;i++){
		if(gcd(t, a[i]) > 1){
			t = gcd(t, a[i]);
		}else{
			t = gcd(t, b[i]);
		}
	}
	
	if(t > 1){
		printf("%I64d\n", t);
	}else{
		printf("-1\n");
	}
	
	return 0;
}