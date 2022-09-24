#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[3030][5050];
ll minv[3030][5050];
ll A[5050];
ll n;

int main()
{
	ll i, j;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld", A+i);
	}
	
	if(n == 1){
		printf("0\n");
		return 0;
	}
	
	dp[1][1] = max(0ll, A[2] - (A[1] - 1));
	for(j=2; j<n; j++){
		dp[1][j] = max(0ll, A[j-1] - (A[j] - 1)) + max(0ll, A[j+1] - (A[j] - 1));
	}
	dp[1][n] = max(0ll, A[n-1] - (A[n] - 1));
	
	minv[1][1] = dp[1][1];
	for(j=2; j<=n; j++) minv[1][j] = min(dp[1][j], minv[1][j-1]);
	
	
	
	
	for(i=2; i+i<=n+1; i++){
	    dp[i][1] = dp[i][2] = 1e18;
		
		for(j=3; j<n; j++){
			dp[i][j] = 1e18;
			dp[i][j] = min(dp[i][j], dp[i-1][j-2] + max(0ll, min(A[j-1], A[j-2] - 1) - (A[j] - 1)) + max(0ll, A[j+1] - (A[j] - 1)));
			if(j > 3) dp[i][j] = min(dp[i][j], minv[i-1][j-3] + max(0ll, A[j-1] - (A[j] - 1)) + max(0ll, A[j+1] - (A[j] - 1)));
		}
		
		dp[i][n] = 1e18;
		if(n >= 3) dp[i][n] = min(dp[i][n], dp[i-1][n-2] + max(0ll, min(A[n-1], A[n-2] - 1) - (A[n] - 1)));
		if(n >= 4) dp[i][n] = min(dp[i][n], minv[i-1][n-3] + max(0ll, A[n-1] - (A[n] - 1)));
		
		minv[i][1] = dp[i][1];
		for(j=2; j<=n; j++) minv[i][j] = min(dp[i][j], minv[i][j-1]);
	}
	
	for(i=1; i+i<=n+1; i++) printf("%lld ", minv[i][n]);
	
	return 0;
}