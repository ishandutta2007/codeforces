#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005]={};
int rem[2505]={};
char s[2005],p[2005];

int main() {
	scanf("%s%s",s,p);
	int n = strlen(s), m = strlen(p);
	for(int i = 1; i <= n; ++i) {
		int j = m-1;
		int k = i-1;
		while(k >= 0 && j >= 0) {
			if(s[k] != p[j]) ++rem[i];
			else --j;
			--k;
		}
		if(j >= 0) rem[i] = 1e9;
	}
	fill(dp[0]+1,dp[0]+n+1,-1e9);
	for(int i = 1; i <= n; ++i) {
		fill(dp[i]+i+1,dp[i]+n+1,-1e9);
		for(int x = 0; x <= i; ++x) {
			dp[i][x] = dp[i-1][x];
			if(x > 0)
				dp[i][x] = max(dp[i][x],dp[i-1][x-1]);
			if(rem[i] <= x)
				dp[i][x] = max(dp[i][x],1+dp[i-m-rem[i]][x-rem[i]]);
		}
	}
	for(int x = 0; x <= n; ++x) {
		printf("%d ",dp[n][x]);
	}
	printf("\n");
}