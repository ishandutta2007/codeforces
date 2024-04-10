#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[1003],dp[1003],C[1003][1003];
int main(){cin>>n;
	C[0][0]=1;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		C[i][0]=1;}
	for(int i=0;i<n;i++)cin>>a[i];
	dp[n]=1;
	for(int i=n-1;i>=0;i--)
		if(a[i]>0)
			for(int j=i+a[i];j<=n;j++)
				dp[i]=(dp[i]+dp[j]*C[j-i-1][a[i]])%mod;
	int ans=0;
	for(int i=0;i<n;i++)
		ans=(ans+dp[i])%mod;
	cout<<ans;
}