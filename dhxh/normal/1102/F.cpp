#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int inf = 0x3f3f3f3f;

int n, m, t;

int a[25][10005];

int f[(1<<17)][17][17];
bool vis[(1<<17)][17][17];

int g[25][25];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int getp(int x, int p){
	return (x >> (p - 1)) & 1;
}

int addp(int x, int p){
	return x | (1 << (p - 1));
}

int main(){
	int i, j, k, l;
	int ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j] = read();
		}
	}
	
	memset(g, 0x3f, sizeof(g));
	
	if(n == 1){
		ans = inf;
		for(i=2;i<=m;i++){
			ans = min(ans, abs(a[1][i] - a[1][i - 1]));
		}
		printf("%d\n", ans);
		return 0;
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			for(k=1;k<=m;k++){
				g[i][j] = min(g[i][j], abs(a[i][k] - a[j][k]));
				g[j][i] = min(g[j][i], abs(a[i][k] - a[j][k]));
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i != j){
				int tmp = inf;
				for(k=1;k<m;k++){
					tmp = min(tmp, abs(a[j][k] - a[i][k + 1]));
				}
				f[addp(addp(0, i), j)][i][j] = tmp;
				vis[addp(addp(0, i), j)][i][j] = true;
			}
		}
	}
	
	for(i=0;i<(1<<n);i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(vis[i][j][k]){
					for(l=1;l<=n;l++){
						if(!getp(i, l)){
							f[addp(i, l)][l][k] = max(f[addp(i, l)][l][k], min(f[i][j][k], g[j][l]));
							vis[addp(i, l)][l][k] = true;
						}
					}
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i != j){
				ans = max(ans, min(f[(1 << n) - 1][i][j], g[i][j]));
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}