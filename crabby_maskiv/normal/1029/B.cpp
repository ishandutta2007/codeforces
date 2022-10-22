#include<iostream>
using namespace std;
int dp[200005];
int n;
int a[200005];
int main()
{
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) cin>>a[i];
	dp[0]=1;
	for(i=1;i<n;i++) 
	{
		if(a[i-1]*2>=a[i]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
	}
	    
	int mx=-1;
	for(i=0;i<n;i++) mx=max(mx,dp[i]);
	cout<<mx;
	return 0;
}