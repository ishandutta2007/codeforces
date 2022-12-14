#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[105], rev[105], b[105];
long double ans = 0, cnt = 0, f[2][35][35], g[31][31];

void dfs(int u){
	if(!u){
		for(int i = 1;i <= n;i ++)
			for(int j = i + 1;j <= n;j ++)
				if(a[i] > a[j]) ans ++;
		cnt ++;
		return;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			for(int k = i;k <= (i + j) / 2;k ++) swap(a[k], a[j - (k - i)]);
			dfs(u - 1);
			for(int k = i;k <= (i + j) / 2;k ++) swap(a[k], a[j - (k - i)]);
		}
	}
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	long double kk = n * (n + 1) / 2.0;
	for(int i = 1;i <= n;i ++) for(int j = i + 1;j <= n;j ++) if(a[i] > a[j]) f[0][i][j] = 1;
	for(int o = 1;o <= m;o ++){
		int p = o & 1;
		memset(f[p], 0, sizeof(f[p]));
		for(int i = 1;i <= n;i ++){
			for(int j = i;j <= n;j ++){
				for(int k = 1;k <= n;k ++) b[k] = k;
				for(int k = i;k <= (j + i) / 2;k ++) swap(b[k], b[j - k + i]);
				for(int x = 1;x <= n;x ++) for(int y = x + 1;y <= n;y ++) if(b[x] < b[y]) f[p][b[x]][b[y]] += f[p ^ 1][x][y] / kk; else f[p][b[y]][b[x]] += (1 - f[p ^ 1][x][y]) / kk;
			}
		}
	}
	long double ans = 0;
	for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j ++) ans += f[m & 1][i][j];
	printf("%.10lf\n", (double)ans);
	return 0;
}