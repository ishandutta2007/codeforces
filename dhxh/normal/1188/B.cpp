#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

long long n, m, k, p;

map <long long, long long> s;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x, y;
	long long ans = 0;
	
	n = read();
	p = read();
	k = read();
	
	for(i=1;i<=n;i++){
		x = read();
		y = x * x % p * x % p * x % p;
		y -= k * x % p;
		y = (y % p + p) % p;
		ans += s[y];
		s[y]++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}