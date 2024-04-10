#include<bits/stdc++.h>
using namespace std;
const int MAX = 5050;
char s[MAX];
int dp[MAX][MAX];
int cot[MAX];
int ans[MAX];
int main(){
	scanf("%s",s);
	int len = strlen (s);
	for (int i=0;i<=len;i++){
		dp[i][i] = 1;
		dp[i][i-1] = 1;
	}
	cot[1] = len;
	for (int k=2;k<=len;k++){
		for (int l = 0;l<=len-k;l++){
			int r = l+k-1;
			if (s[l]==s[r]&&dp[l+1][r-1]){
				dp[l][r] = dp[l][l-1+((r-l+1)>>1)]+1;
//				printf("dp[%d][%d]:%d\n",l,r,dp[l][r]);
				cot[dp[l][r]]++;
			}
		}
	}
	int sum =0;
	for (int i=len;i>=1;i--){
		sum+=cot[i];
		ans[i] = sum;
	}
	for (int i=1;i<=len;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}