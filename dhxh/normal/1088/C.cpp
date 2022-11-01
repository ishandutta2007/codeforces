#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2005;

int n, m;

int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long d = 0;
	long long t;
	
	n = read();
	
	for(i=0;i<n;i++){
		a[i] = read();
	}
	
	printf("%d\n", n + 1);
	
	for(i=n-1;i>=0;i--){
		t = (d + a[i]) % n;
		t = ((i - t) + n) % n;
		d += t;
		printf("%d %d %I64d\n", 1, i + 1, t);
	}
	
	printf("%d %d %d\n", 2, n, n);
	
	return 0;
}