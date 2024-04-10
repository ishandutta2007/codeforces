#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;

int t;

int n, m;
int a[20][maxn];
int b[50];
int c[maxn];
int maxx[maxn];

int f[15][(1<<13)];
int g[(1<<15)];

bool cmp(int x, int y){
	return maxx[x] > maxx[y];
}

int solve(int x){
	int i, j, k;
	memset(g, 0, sizeof(g));
	for(i=1;i<=n;i++){
		b[i] = a[i][x];
	}
	for(i=n+1;i<=2*n;i++){
		b[i] = a[i - n][x];
	}
	
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			int ans = 0;
			for(k=1;k<=n;k++){
				if((i >> (k - 1)) & 1){
					ans += b[j + k];
				}
			}
			g[i] = max(g[i], ans);
		}
	}
	
	return 0;
}

int main(){
	int i, j, k;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		memset(maxx, 0, sizeof(maxx));
		memset(f, 0, sizeof(f));
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d", &a[i][j]);
				maxx[j] = max(maxx[j], a[i][j]);
				c[j] = j;
			}
		}
		
		sort(c + 1, c + m + 1, cmp);
		
		for(i=1;i<=min(n,m);i++){
			solve(c[i]);
			for(j=0;j<(1<<n);j++){
				f[i][j] = max(f[i][j], f[i - 1][j]);
				for(k=j;k>0;k=((k-1)&j)){
					f[i][j] = max(f[i][j], f[i - 1][j ^ k] + g[k]);
				}
			}
		}
		
		printf("%d\n", f[min(n, m)][(1<<n)-1]);
	}
	
	return 0;
}