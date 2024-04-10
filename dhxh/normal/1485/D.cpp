#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int a[505][505];
int b[505][505];

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if((i + j) & 1){
				for(int k=1;k<=16;k++){
					if((720720 - k * k * k * k) % a[i][j] == 0){
						b[i][j] = 720720 - k * k * k * k;
						break;
					}
				}
			}else{
				b[i][j] = 720720;
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}