#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, k;

int a[maxn];

int t;

int ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int gcd(int x, int y){
	if(y){
		return gcd(y, x % y);
	}else{
		return x;
	}
}

int main(){
	int i, j;
	
	n = read();
	k = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		a[i] %= k;
	}
	
	t = k;
	
	for(i=1;i<=n;i++){
		if(a[i] == 0){
			continue;
		}
		
		t = gcd(t, a[i]);
	}
	
	if(t == k){
		printf("1\n");
		printf("0\n");
		return 0;
	}
	
	for(i=0;i<k;i+=t){
		ans++;
	}
	
	printf("%d\n", ans);
	
	printf("0");
	
	for(i=t;i<k;i+=t){
		printf(" %d", i);
	}
	
	printf("\n");
	
	
	return 0;
}