#include<bits/stdc++.h>
using namespace std;
int n,sum[100044],tsum[100034],a[100034],m,ans;
int main()
{
	cin>>n>>m;
	for(int i=2;i<2+n;i++)
	{
		cin>>a[i];
		if(i%2==0)sum[i]=sum[i-2]+a[i]-a[i-1];
	}
	a[2+n]=m;
	if(n%2==0)sum[n+2]=sum[n]+m-a[n+1];
	for(int i=1+n;i>1;i--)
		if(i%2==0)
			tsum[i]=tsum[i+2]+a[i+1]-a[i];
	ans=max(sum[2+n],sum[n+1]);
	for(int i=2;i<n+2;i++)
		if(i%2==0)
			ans=max(ans,sum[i]+tsum[i]-1);
		else
			ans=max(ans,sum[i-1]+a[i]-a[i-1]-1+tsum[i+1]);
	cout<<ans;
}