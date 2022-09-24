#include <bits/stdc++.h>

using namespace std;

int dp[1010101][3][6], K[1010101];
int n, m, ans;

int main()
{
	int i, a, x, y, z, k;
	
	scanf("%d%d", &n, &m);
	
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		K[a] ++;
	}
	
	for(i=0; i<=m; i++){
		for(x=0; x<3; x++) for(y=0; y<6; y++){
			dp[i][x][y] = -1e9;
		}
	}
	
	dp[0][0][0] = 0;
	
	for(i=1; i<=m; i++){
		for(x=0; x<3; x++) for(y=x; y<6; y++){
			if(K[i] < x) continue;
			k = (K[i] - x) / 3; z = (K[i] - x) % 3;
			dp[i][min(y - x, 2)][z] = max(dp[i][min(y - x, 2)][z], dp[i - 1][x][y] + k + x);
			if(k > 0) dp[i][min(y - x, 2)][z + 3] = max(dp[i][min(y - x, 2)][z + 3], dp[i - 1][x][y] + k - 1 + x);
		}
		
		for(x=2; x>=0; x--) for(y=5; y>=x; y--){
			if(x + 1 <= 2) dp[i][x][y] = max(dp[i][x][y], dp[i][x + 1][y]);
			if(y + 1 <= 5) dp[i][x][y] = max(dp[i][x][y], dp[i][x][y + 1]);
		}
	}
	
	for(x=0; x<3; x++) for(y=x; y<6; y++){
		ans = max(ans, dp[m][x][y]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}