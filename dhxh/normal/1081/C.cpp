#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k, t;

long long mod = 998244353;

long long f[2005][2005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	k = read();
	
	f[1][0] = m;
	
	for(i=2;i<=n;i++){
		f[i][0] = f[i - 1][0];
		for(j=1;j<=k;j++){
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (m - 1)) % mod;
		}
	}
	
	printf("%I64d\n", f[n][k]);
	
	return 0;
}