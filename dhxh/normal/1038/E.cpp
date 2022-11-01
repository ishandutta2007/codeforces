#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

long long inf = 0x3f3f3f3f3f3f3f3f / 2;

long long f[205][205][5][5];
bool vis[205][205][5][5];

struct ex {
	int l, r;
	long long v;
};

ex p[205];

int dfs(int l, int r, int x, int y){
	int i, j, k, a, b;
	vis[l][r][x][y] = true;
	
	for(i=l;i<=r;i++){
		for(j=i;j<=r;j++){
			if(!vis[i][j][x][y])dfs(i, j, x, y);
			f[l][r][x][y] = max(f[l][r][x][y], f[i][j][x][y]);
		}
	}
	
	for(i=l;i<r;i++){
		for(a=1;a<=4;a++){
			if(!vis[l][i][x][a])dfs(l, i, x, a);
			if(!vis[i + 1][r][a][y])dfs(i + 1, r, a, y);
			f[l][r][x][y] = max(f[l][r][x][y], f[l][i][x][a] + f[i + 1][r][a][y]);
			
			if(!vis[i + 1][r][x][a])dfs(i + 1, r, x, a);
			if(!vis[l][i][a][y])dfs(l, i, a, y);
			f[l][r][x][y] = max(f[l][r][x][y], f[i + 1][r][x][a] + f[l][i][a][y]);
		}
	}
	
	return 0;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k, l;
	long long ans = 0;
	
	n = read();
	
	for(i=0;i<=200;i++){
		for(j=0;j<=200;j++){
			for(k=0;k<=4;k++){
				for(l=0;l<=4;l++){
					f[i][j][k][l] = -inf;
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		p[i].l = read();
		p[i].v = read();
		p[i].r = read();
		f[i][i][p[i].l][p[i].r] = f[i][i][p[i].r][p[i].l] = p[i].v;
		vis[i][i][p[i].l][p[i].r] = vis[i][i][p[i].r][p[i].l] = true;
	}
	
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			if(!vis[1][n][i][j])dfs(1, n, i, j);
			ans = max(ans, f[1][n][i][j]);
		}
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}