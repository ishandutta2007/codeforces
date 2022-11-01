#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n;
int a[30];

int f[2][405][405][3][3];
int g[405][405][2][2];
int h[405][26][26];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x, y, z;
	long long ans = 0;
	
	cin >> n;
	
	for(i=0;i<26;i++) cin >> a[i];
	
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			h[2][i][j] = 1;
		}
	}
	
	for(i=3;i<=n;i++){
		for(j=0;j<26;j++){
			for(k=0;k<26;k++){
				for(x=0;x<26;x++){
					if(j == x) continue;
					h[i][k][x] += h[i - 1][j][k];
					if(h[i][k][x] >= mod) h[i][k][x] -= mod;
				}
			}
		}
	}
	
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			ans += h[n][i][j];
		}
	}
	ans %= mod;
	
	g[2][2][0][0] = 1;
	g[2][1][0][1] = 25;
	g[2][1][1][0] = 25;
	g[2][0][1][1] = 25 * 25;
	
	for(i=3;i<=n;i++){
		for(j=0;j<=n;j++){
			for(x=0;x<2;x++){
				for(y=0;y<2;y++){
					if(x == 1){
						g[i][j][y][1] = (g[i][j][y][1] + g[i - 1][j][x][y] * 24ll) % mod;
						g[i][j + 1][y][0] = (g[i][j + 1][y][0] + g[i - 1][j][x][y]) % mod;
					}else{
						g[i][j][y][1] = (g[i][j][y][1] + g[i - 1][j][x][y] * 25ll) % mod;
					}
				}
			}
		}
	}
	
	for(i=0;i<26;i++){
		for(j=a[i]+1;j<=n;j++){
			ans -= g[n][j][0][0];
			ans -= g[n][j][0][1];
			ans -= g[n][j][1][0];
			ans -= g[n][j][1][1];
		}
	}
	ans = (ans % mod + mod) % mod;
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			f[0][(i == 0) + (j == 0)][(i == 1) + (j == 1)][i][j] = (i == 2 ? 24 : 1) * (j == 2 ? 24 : 1);
		}
	}
	
	for(i=3;i<=n;i++){
		memset(f[i & 1], 0, sizeof(f[i & 1]));
		for(j=0;j<=n;j++){
			for(k=0;k<=n;k++){
				for(x=0;x<=2;x++){
					for(y=0;y<=2;y++){
						for(z=0;z<=2;z++){
							if(z == 2){
								if(x == 2){
									f[i & 1][j][k][y][z] = (f[i & 1][j][k][y][z] + f[(i & 1) ^ 1][j][k][x][y] * 23ll) % mod;
								}else{
									f[i & 1][j + (z == 0)][k + (z == 1)][y][z] = (f[i & 1][j + (z == 0)][k + (z == 1)][y][z] + f[(i & 1) ^ 1][j][k][x][y] * 24ll) % mod;
								}
								continue;
							}
							if(x == z) continue;
							f[i & 1][j + (z == 0)][k + (z == 1)][y][z] += f[(i & 1) ^ 1][j][k][x][y];
							if(f[i & 1][j + (z == 0)][k + (z == 1)][y][z] >= mod) f[i & 1][j + (z == 0)][k + (z == 1)][y][z] -= mod;
						}
					}
				}
			}
		}
	}
	
	for(i=0;i<26;i++){
		for(j=i+1;j<26;j++){
			for(x=a[i]+1;x<=n;x++){
				for(y=a[j]+1;y<=n;y++){
					ans += f[n & 1][x][y][0][0];
					ans += f[n & 1][x][y][0][1];
					ans += f[n & 1][x][y][0][2];
					ans += f[n & 1][x][y][1][0];
					ans += f[n & 1][x][y][1][1];
					ans += f[n & 1][x][y][1][2];
					ans += f[n & 1][x][y][2][0];
					ans += f[n & 1][x][y][2][1];
					ans += f[n & 1][x][y][2][2];
				}
			}
		}
	}
	ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}