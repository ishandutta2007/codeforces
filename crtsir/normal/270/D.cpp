#include<bits/stdc++.h>
using namespace std;
int ans,n,m,dp[5003];
pair<int,double>a[5003];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
			if(a[i].first>=a[j].first)
				dp[i]=max(dp[j]+1,dp[i]);
	}
	for(int i=0;i<=n;i++)dp[n]=max(dp[n],dp[i]);
	cout<<n-dp[n];
}