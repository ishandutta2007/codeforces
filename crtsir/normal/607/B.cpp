#include<bits/stdc++.h>
using namespace std;
int dp[503][503],n,c[503];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int l=0;l<n;l++)
		for(int i=0;i<n-l;i++){
			int j=i+l;
			if(i==j){dp[i][j]=1;continue;}
			dp[i][j]=dp[i+1][j]+1;
			if(c[i]==c[i+1])dp[i][j]=min(dp[i][j],dp[i+2][j]+1);
			if(j-i>1) 
				for(int k=i+2;k<=j;k++)
					if(c[i]==c[k])
						dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);
		}
	cout<<dp[0][n-1];
}