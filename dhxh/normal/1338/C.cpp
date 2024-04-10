#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

long long geta(long long n, long long i){
	long long ret = 0;
	for(;i>=0;i-=2){
		if(n <= (1ll << i)){
			ret |= (0ll << i);
		}else if(n <= 2 * (1ll << i)){
			ret |= (1ll << i);
			n -= (1ll << i);
		}else if(n <= 3 * (1ll << i)){
			ret |= (2ll << i);
			n -= 2 * (1ll << i);
		}else if(n <= 4 * (1ll << i)){
			ret |= (3ll << i);
			n -= 3 * (1ll << i);
		}
	}
	return ret;
}

long long getb(long long n, long long i){
	long long ret = 0;
	for(;i>=0;i-=2){
		if(n <= (1ll << i)){
			ret |= (0ll << i);
		}else if(n <= 2 * (1ll << i)){
			ret |= (2ll << i);
			n -= (1ll << i);
		}else if(n <= 3 * (1ll << i)){
			ret |= (3ll << i);
			n -= 2 * (1ll << i);
		}else if(n <= 4 * (1ll << i)){
			ret |= (1ll << i);
			n -= 3 * (1ll << i);
		}
	}
	return ret;
}

long long getc(long long n, long long i){
	long long ret = 0;
	for(;i>=0;i-=2){
		if(n <= (1ll << i)){
			ret |= (0ll << i);
		}else if(n <= 2 * (1ll << i)){
			ret |= (3ll << i);
			n -= (1ll << i);
		}else if(n <= 3 * (1ll << i)){
			ret |= (1ll << i);
			n -= 2 * (1ll << i);
		}else if(n <= 4 * (1ll << i)){
			ret |= (2ll << i);
			n -= 3 * (1ll << i);
		}
	}
	return ret;
}

long long search(long long n){
	if(n == 3) return 3;
	if(n == 2) return 2;
	if(n == 1) return 1;
	
	long long i = 0;
	
	while((1ll << (i + 2)) - 1 < n){
		i += 2;
	}
	
	n -= (1ll << i) - 1;
	
	if(n % 3 == 1){
		return (1ll << i) | geta(n / 3 + 1, i - 2);
	}else if(n % 3 == 2){
		return (1ll << (i + 1)) | getb(n / 3 + 1, i - 2);
	}else{
		return (1ll << i) | (1ll << (i + 1)) | getc(n / 3, i - 2);
	}
}

int main(){
	int i, j;
	
	scanf("%lld", &t);
	
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", search(n));
	}
	
	return 0;
}