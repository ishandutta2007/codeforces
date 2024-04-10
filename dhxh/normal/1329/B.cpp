#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		m = read();
		long long ans = 1;
		long long sum = 1;
		long long s = 1, i = 2;
		
		while(s + i <= n){
			ans = (ans + i * sum + i) % m;
			sum = ans;
			s += i;
			i *= 2;
		}
		
		ans = (ans + (n - s) * sum + (n - s)) % m;
		
		printf("%lld\n", ans);
	}
	
	return 0;
}