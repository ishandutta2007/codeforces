#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;

int n, m, t;

long long f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	for(i=3;i<=2e6;i++){
		f[i][0] = (max(f[i - 1][0], f[i - 1][1]) + 2 * max(f[i - 2][0], f[i - 2][1])) % mod;
		f[i][1] = (f[i - 1][0] + 2 * f[i - 2][0] + 4) % mod;
	}
	
	t = read();
	
	while(t--){
		n = read();
		printf("%lld\n", max(f[n][0], f[n][1]));
	}
	
	return 0;
}