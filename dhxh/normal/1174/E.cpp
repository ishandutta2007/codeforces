#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int mod = 1e9 + 7;

int n, m, t;

int f[maxn][20][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	cin >> n;
	
	while((1 << (m + 1)) <= n){
		m++;
	}
	
	f[1][m][0] = 1;
	
	if((1 << (m - 1)) * 3 <= n){
		f[1][m][1] = 1;
	}
	
	for(i=2;i<=n;i++){
		for(j=0;j<=m;j++){
			f[i][j][0] += 1ll * f[i - 1][j][0] * (n / (1 << j) - i + 1) % mod;
			if(f[i][j][0] >= mod)f[i][j][0] -= mod;
			if(j > 0)f[i][j - 1][0] += 1ll * f[i - 1][j][0] * (n / (1 << (j - 1)) - n / (1 << j)) % mod;
			if(j > 0 and f[i][j - 1][0] >= mod)f[i][j - 1][0] -= mod;
			
			f[i][j][1] += 1ll * f[i - 1][j][1] * (n / ((1 << (j - 1)) * 3) - i + 1) % mod;
			if(f[i][j][1] >= mod)f[i][j][1] -= mod;
			if(j > 0)f[i][j - 1][0] += 1ll * f[i - 1][j][1] * (n / (1 << (j - 1)) - n / ((1 << (j - 1)) * 3)) % mod;
			if(j > 0 and f[i][j - 1][0] >= mod)f[i][j - 1][0] -= mod;
			if(j > 0)f[i][j - 1][1] += 1ll * f[i - 1][j][1] * (n / ((1 << (j - 2)) * 3) - n / ((1 << (j - 1)) * 3)) % mod;
			if(j > 0 and f[i][j - 1][1] >= mod)f[i][j - 1][1] -= mod;
		}
	}
	
	cout << f[n][0][0] << endl;
	
	return 0;
}