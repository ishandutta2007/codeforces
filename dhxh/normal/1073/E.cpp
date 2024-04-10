#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

long long f[25][(1<<10)][11];
long long g[25][(1<<10)][11];
long long mod = 998244353;

long long ten[25];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int count(int x){
	int cnt = 0;
	while(x){
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

int getp(long long x, int y){
	while(y--){
		x /= 10;
	}
	
	return x % 10;
}

int countt(long long x){
	if(x == 0)return 0;
	int cnt = 0;
	while(x){
		cnt++;
		x /= 10;
	}
	return cnt - 1;
}

long long getans(long long n){
	int i, j, k, l;
	long long ans = 0;
	
	for(i=countt(n);i>=0;i--){
		for(j=1;j<(i == countt(n) ? getp(n, countt(n)) : 10);j++){
			for(k=0;k<(1<<10);k++){
				if(count(k) > t)continue;
				ans += f[i][k][j];
				if(ans >= mod)ans -= mod;
			}
		}
	}
	
	int tmp = (1 << getp(n, countt(n)));
	long long tb = getp(n, countt(n)) * ten[countt(n)] % mod;
	
	for(i=countt(n)-1;i>=0;i--){
		for(j=0;j<getp(n, i);j++){
			for(k=0;k<(1<<10);k++){
				if(count(k | tmp) > t)continue;
				ans += f[i][k][j];
				if(ans >= mod)ans -= mod;
				ans += g[i][k][j] * tb % mod;
				if(ans >= mod)ans -= mod;
			}
		}
		tmp |= (1 << getp(n, i));
		tb = (tb + getp(n, i) * ten[i]) % mod;
	}
	
	return ans;
}

int main(){
	int i, j, k, l;
	long long ti = 1;
	
	cin >> n >> m >> t;
	
	for(i=0;i<10;i++){
		f[0][1 << i][i] = i;
		g[0][1 << i][i] = 1;
	}
	
	ten[0] = 1;
	for(i=0;i<20;i++){
		ti = ti * 10 % mod;
		ten[i + 1] = ti;
		for(j=0;j<(1<<10);j++){
			for(k=0;k<10;k++){
				for(l=0;l<10;l++){
					g[i + 1][j | (1 << l)][l] += g[i][j][k];
					f[i + 1][j | (1 << l)][l] += (f[i][j][k] + ti * l * g[i][j][k]) % mod;
					if(f[i + 1][j | (1 << l)][l] >= mod)f[i + 1][j | (1 << l)][l] -= mod;
					if(g[i + 1][j | (1 << l)][l] >= mod)g[i + 1][j | (1 << l)][l] -= mod;
				}
			}
		}
	}
	
	cout << (getans(m + 1) - getans(n) + mod) % mod << endl;
	
	return 0;
}