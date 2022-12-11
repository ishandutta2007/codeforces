#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,dp[N][2];
int main(){
	scanf("%d",&n);
	dp[1][1]=1;dp[2][0]=1;
	for(int i=3;i<=n;i++){
		int r=(i+1)/2;
		bool op=r&1?1:0;
		dp[i][0]=dp[r-1][1]*dp[i-r][op];
		dp[i][1]=dp[r-1][0]*dp[i-r][op^1];
		if(!(i&1)){
			r=i/2+1;op=r&1?1:0;
			dp[i][0]+=dp[r-1][1]*dp[i-r][op];
			dp[i][1]+=dp[r-1][0]*dp[i-r][op^1];
		}
	}
	printf("%d\n",dp[n][0]+dp[n][1]);
	return 0;
}