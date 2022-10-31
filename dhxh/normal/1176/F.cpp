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

long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, t;

long long f[maxn][15];
long long g[maxn][5][5][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k, l, r;
	long long x, y;
	
	n = read();
	
	for(i=0;i<=n;i++){
		for(j=0;j<=10;j++){
			f[i][j] = -inf;
		}
	}
	f[0][0] = 0;
	
	for(i=1;i<=n;i++){
		m = read();
		
		for(l=0;l<=3;l++){
			for(r=0;r<=3;r++){
				g[0][l][r][0] = g[0][l][r][1] = -inf;
			}
		}
		g[0][0][0][0] = 0;
		
		for(j=1;j<=m;j++){
			x = read();
			y = read();
			for(l=0;l<=3;l++){
				for(r=0;r<=3;r++){
					g[j][l][r][0] = g[j - 1][l][r][0];
					g[j][l][r][1] = g[j - 1][l][r][1];
				}
			}
			for(l=0;l<=2;l++){
				for(r=0;r<=3-x;r++){
					g[j][l + 1][r + x][0] = max(g[j][l + 1][r + x][0], g[j - 1][l][r][0] + y);
					g[j][l + 1][r + x][1] = max(g[j][l + 1][r + x][1], max(g[j - 1][l][r][0] + 2 * y, g[j - 1][l][r][1] + y));
				}
			}
		}
		
		for(j=0;j<10;j++){
			for(k=0;k<=3;k++){
				long long maxa = -inf;
				long long maxb = -inf;
				for(l=0;l<=3;l++){
					maxa = max(maxa, g[m][k][l][0]);
					maxb = max(maxb, g[m][k][l][1]);
				}
				
				if(j + k >= 10){
					f[i][(j + k) % 10] = max(f[i][(j + k) % 10], f[i - 1][j] + maxb);
				}else{
					f[i][j + k] = max(f[i][j + k], f[i - 1][j] + maxa);
				}
			}
		}
	}
	
	long long ans = -inf;
	for(i=0;i<10;i++){
		ans = max(ans, f[n][i]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}