#include <bits/stdc++.h>

using namespace std;

int D[1010][1010];
int n, k;

int main()
{
	int i, j;
	
	scanf("%d", &n);
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n/2; j++){
			D[i << 1][j << 1] = k++;
			D[i << 1][j << 1 | 1] = k++;
			D[i << 1 | 1][j << 1] = k++;
			D[i << 1 | 1][j << 1 | 1] = k++;
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){		
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}