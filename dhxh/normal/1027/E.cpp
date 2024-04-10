#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 505;

long long mod = 998244353;

long long n, k;

long long g[2][maxn][maxn];

long long a[maxn];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, l;
	
	cin >> n >> k;
	
	g[1][1][1] = 1;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			for(l=1;l<=j;l++){
				g[(i + 1) & 1][j][l] = 0;
			}
		}
		for(j=1;j<=i;j++){
			for(l=1;l<=j;l++){
				if(j == l){
					g[(i + 1) & 1][j + 1][l + 1] = (g[(i + 1) & 1][j + 1][l + 1] + g[i & 1][j][l]) % mod;
				}else{
					g[(i + 1) & 1][j][l + 1] = (g[(i + 1) & 1][j][l + 1] + g[i & 1][j][l]) % mod;
				}
				g[(i + 1) & 1][j][1] = (g[(i + 1) & 1][j][1] + g[i & 1][j][l]) % mod;
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			a[i] = (a[i] + g[n & 1][i][j]) % mod;
		}
	}
	
	memset(g, 0, sizeof(g));
	
	for(i=1;i<=n;i++){
		if(i < k){
			g[1][1][i] = a[i];
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(l=1;l<=n;l++){
				g[(i + 1) & 1][j][l] = 0;
			}
		}
		for(j=1;j<=i;j++){
			for(l=1;l<=n;l++){
				if((j + 1) * l < k){
					g[(i + 1) & 1][j + 1][l] = (g[(i + 1) & 1][j + 1][l] + g[i & 1][j][l]) % mod;
				}
				g[(i + 1) & 1][1][l] = (g[(i + 1) & 1][1][l] + g[i & 1][j][l]) % mod;
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			ans = (ans + g[n & 1][i][j]) % mod;
		}
	}
	
	cout << ans * 2 % mod << endl;
	
	return 0;
}