#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 3e5 + 5;

long long mod = 998244353;

int n, m, t;

vector <int> e[maxn];

long long f[maxn][2];
long long g[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	
	return 0;
}

int dfs(int x, int fa){
	int y;
	int i, j;
	
	f[x][0] = 0;
	f[x][1] = 1;
	g[x] = 1;
	
	for(auto y : e[x]){
		if(y != fa){
			dfs(y, x);
			f[x][1] = f[x][1] * ((f[y][0] + f[y][1]) % mod) % mod;
			g[x] = g[x] * ((2 * f[y][0] + f[y][1]) % mod) % mod;
		}
	}
	
	for(auto y : e[x]){
		if(y != fa){
			f[x][0] = (f[x][0] + (g[x] * qpow((2 * f[y][0] + f[y][1]) % mod, mod - 2) % mod) * g[y] % mod) % mod;
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		
		addedge(x, y);
	}
	
	dfs(1, -1);
	
	printf("%lld\n", (f[1][0] + f[1][1]) % mod);
	
	return 0;
}