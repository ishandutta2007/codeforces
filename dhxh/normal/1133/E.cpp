#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5e3 + 5;

int n, m, t;

int a[maxn];

int f[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			f[i][j] = f[i - 1][j];
		}
		
		for(k=i;k>=1&&a[i]-a[k]<=5;k--);
		for(j=0;j<m;j++){
			f[i][j + 1] = max(f[i][j + 1], f[k][j] + i - k);
		}
	}
	
	printf("%d\n", f[n][m]);
	
	return 0;
}