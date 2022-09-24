#include <bits/stdc++.h>

using namespace std;

int dp[303030][22], M[22][22];
int A[303030];
int n, q;

int main()
{
	int i, j, k, x, y, f;
	
	scanf("%d%d", &n, &q);
	
	for(i=0; i<19; i++){
		for(j=0; j<19; j++){
			M[i][j] = 0;
		}
	}
	
	for(i=1; i<=n; i++){
		scanf("%d", A + i);
		
		for(k=0; k<19; k++) dp[i][k] = 0;
		
		for(j=0; j<19; j++) if(A[i] & (1 << j)){
			for(k=0; k<19; k++){
				dp[i][k] = max(dp[i][k], M[j][k]);
			}
			dp[i][j] = i;
		}
		
		for(j=0; j<19; j++) if(A[i] & (1 << j)){
			for(k=0; k<19; k++){
				M[j][k] = dp[i][k];
			}
		}
	}
	
	for(i=0; i<q; i++){
		scanf("%d%d", &x, &y); f = 0;
		for(k=0; k<19; k++) if(A[x] & (1 << k)){
			if(dp[y][k] >= x) break;
		}
		printf("%s\n", k < 19? "Shi" : "Fou");
	}
	
	return 0;
}