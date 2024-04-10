#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;
const int maxn = 1e5 + 5;

long long a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		scanf("%d", &n);
		long long x = 0;
		long long sum = 0;
		
		for(i=1;i<=n;i++){
			a[i] = read();
			x ^= a[i];
			sum += a[i];
		}
		
		printf("2\n%lld %lld\n", x, sum + x);
	}
	
	return 0;
}