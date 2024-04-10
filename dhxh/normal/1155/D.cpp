#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 5;

int n;

long long a[maxn];
long long m;

long long f[maxn][2][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		f[i][0][0] = max(f[i - 1][0][0] + a[i], a[i]);
		f[i][1][0] = max(max(f[i - 1][1][0] + a[i] * m, a[i] * m), f[i - 1][0][0] + a[i] * m);
		f[i][1][1] = max(max(f[i - 1][1][1] + a[i], a[i]), f[i - 1][1][0] + a[i]);
		ans = max(max(ans, f[i][0][0]), max(f[i][1][0], f[i][1][1]));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}