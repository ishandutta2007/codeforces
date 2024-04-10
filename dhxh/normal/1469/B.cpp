#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int a[105];
int b[105];
int f[105][105];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			a[i] += a[i - 1];
		}
		
		scanf("%d", &m);
		for(i=1;i<=m;i++){
			scanf("%d", &b[i]);
			b[i] += b[i - 1];
		}
		
		memset(f, 0xc0, sizeof(f));
		
		f[0][0] = 0;
		
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				if(i < n){
					f[i + 1][j] = max(f[i + 1][j], max(f[i][j], a[i + 1] + b[j]));
				}
				if(j < m){
					f[i][j + 1] = max(f[i][j + 1], max(f[i][j], a[i] + b[j + 1]));
				}
			}
		}
		
		printf("%d\n", f[n][m]);
	}
	
	return 0;
}