#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

long long mod = 998244353;

long long n, m, t;

vector <int> e[maxn];
long long w[maxn];
long long g[maxn];

long long fac[maxn];
long long f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int fa){
	f[x] = 1;
	w[x] = 1;
	
	for(int y : e[x]){
		if(y == fa)continue;
		dfs(y, x);
		w[x] += 1;
		f[x] = f[x] * f[y] % mod * w[y] % mod;
	}
	
	f[x] = f[x] * fac[w[x] - 1] % mod;
	
	return 0;
}

int main(){
	long long i, j;
	int x, y;
	
	n = read();
	
	fac[0] = 1;
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
		fac[i] = fac[i - 1] * i % mod;
	}
	fac[n] = fac[n - 1] * n % mod;
	
	dfs(1, -1);
	
	printf("%lld\n", f[1] * n % mod);
	
	return 0;
}