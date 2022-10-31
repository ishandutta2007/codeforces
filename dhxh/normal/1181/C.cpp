#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

char a[1005][1005];

int cnt[1005][1005];
int f[1005][1005];
int g[1005][1005];
int h[1005][1005];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf(" %c", &a[i][j]);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j] == a[i - 1][j]){
				cnt[i][j] = cnt[i - 1][j] - 1;
			}else{
				cnt[i][j] = 1;
				for(k=i+1;k<=n;k++){
					if(a[i][j] == a[k][j]){
						cnt[i][j]++;
					}else{
						break;
					}
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j] == a[i][j - 1] and cnt[i][j] == cnt[i][j - 1]){
				f[i][j] = f[i][j - 1] - 1;
			}else{
				f[i][j] = 1;
				for(k=j+1;k<=m;k++){
					if(a[i][j] == a[i][k] and cnt[i][j] == cnt[i][k]){
						f[i][j]++;
					}else{
						break;
					}
				}
			}
			
			if(a[i][j] == a[i][j - 1]){
				g[i][j] = g[i][j - 1] - 1;
			}else{
				g[i][j] = 1;
				for(k=j+1;k<=m;k++){
					if(a[i][j] == a[i][k]){
						g[i][j]++;
					}else{
						break;
					}
				}
			}
		}
	}
	
	int il, xl, yl, jl;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i + cnt[i][j] <= n and cnt[i][j] == cnt[i + cnt[i][j]][j]){
				x = i + cnt[i][j];
				if(x + cnt[x][j] <= n and cnt[x][j] <= cnt[x + cnt[x][j]][j]){
					y = x + cnt[x][j];
					for(k=0;k<g[y][j];k++){
						if(cnt[y][k + j] >= cnt[x][j]){
							t = k + 1;
						}else{
							break;
						}
					}
					ans += min(f[i][j], min(f[x][j], t)) * (min(f[i][j], min(f[x][j], t)) + 1) / 2;
					j += min(f[i][j], min(f[x][j], t)) - 1;
				}
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}