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
	
	n = read();
	m = read();
	
	long long l = 1, r = n;
	
	while(l < r){
		long long mid = (l + r) / 2;
		
		if((mid + 1ll) * mid / 2 - (n - mid) < m){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	printf("%lld\n", n - l);
	
	return 0;
}