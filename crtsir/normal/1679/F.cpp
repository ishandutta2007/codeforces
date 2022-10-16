#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
int n,m,ans,msk[13];
int dp[50003][1024];
int main(){
	cin>>n>>m;
	for(int j=0;j<m;j++){
		int x,y;
		scanf("%d%d",&x,&y);
		msk[x]^=(1<<y);
		msk[y]^=(1<<x);
	}
	for(int j=0;j<10;j++)msk[j]^=1023;
	dp[0][1023]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<1024;j++)
			for(int k=0;k<10;k++)
				if(j&(1<<k)){
					dp[i][((j>>k)<<k)|msk[k]]+=dp[i-1][j];
					if(dp[i][((j>>k)<<k)|msk[k]]>=mod)dp[i][((j>>k)<<k)|msk[k]]-=mod;
				}
	for(int i=0;i<1024;i++){
		ans+=dp[n][i];
		if(ans>=mod)ans-=mod;
	}cout<<ans;
}