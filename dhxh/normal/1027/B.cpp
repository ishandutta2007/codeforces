#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, q;

long long ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x, y, t;
	
	n = read();
	q = read();
	
	t = n * n / 2 + (n & 1);
	
	while(q--){
		ans = 0;
		x = read();
		y = read();
		
		if((x & 1) == (y & 1)){
			if(x & 1){
				ans = (x / 2) * n;
				ans += y / 2 + (y & 1);
			}else{
				ans = (x / 2 - 1) * n;
				ans += n / 2 + (n & 1) + y / 2;
			}
		}else{
			ans = t;
			if(x & 1){
				ans += (x / 2) * n;
				ans += y / 2;
			}else{
				ans += (x / 2 - 1) * n;
				ans += n / 2 + y / 2 + (y & 1);
			}
		}
		
		printf("%I64d\n", ans);
	}
	
	return 0;
}