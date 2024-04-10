#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

long long a[maxn];
long long b[maxn];

long long f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<=n;i++){
		b[i] = read();
	}
	
	for(i=1;i<=n;i++){
		f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i]);
		f[i][1] = max(f[i - 1][1], f[i - 1][0] + b[i]);
	}
	
	printf("%lld\n", max(f[n][0], f[n][1]));
	
	return 0;
}