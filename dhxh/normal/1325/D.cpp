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
	
	scanf("%lld%lld", &n, &m);
	
	if(n > m or (n & 1) != (m & 1)){
		printf("-1\n");
		return 0;
	}
	
	if(n == m){
		if(n == 0){
			printf("0\n");
		}else{
			printf("1\n%lld\n", n);
		}
	}else{
		if((n ^ ((m - n) / 2)) == n + (m - n) / 2){
			printf("2\n%lld %lld\n", (n ^ ((m - n) / 2)), (m - n) / 2);
		}else{
			printf("3\n%lld %lld %lld\n", n, (m - n) / 2, (m - n) / 2);
		}
	}
	
	return 0;
}