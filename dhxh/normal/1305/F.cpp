#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];

vector <long long> vec;

long long check(long long x){
	int i, j;
	long long ret = 0;
	
	for(i=1;i<=n;i++){
		if(a[i] > x){
			ret += min(a[i] % x, x - a[i] % x);
		}else{
			ret += x - a[i];
		}
	}
	
	return ret;
}

int getprime(long long x){
	long long y = x;
	long long i, j;
	
	for(i=2;i*i<=x and y > 1;i++){
		if(y % i == 0){
			vec.push_back(i);
			while(y % i == 0) y/= i;
		}
	}
	
	if(y > 1) vec.push_back(y);
	
	return 0;
}

int main(){
	int i, j;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	int x, y;
	long long g = 0;
	
	srand(time(0));
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		g = __gcd(g, a[i]);
	}
	
	if(g > 1){
		printf("0\n");
		return 0;
	}
	
	for(i=1;i<=20;i++){
		x = 1ll * rand() * rand() % n + 1;
		getprime(a[x]);
		if(a[x] > 1) getprime(a[x] - 1);
		getprime(a[x] + 1);
	}
	
	sort(vec.begin(), vec.end());
	int sz = unique(vec.begin(), vec.end()) - vec.begin();
	
	for(i=0;i<sz;i++){
		ans = min(ans, check(vec[i]));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}