#include <bits/stdc++.h>
using namespace std;
int a[234567];
int ans[234567];
int main()
{
	int n;
	cin>>n;
	ans[0]=ans[n+1]=2e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)ans[i]=0;
		else ans[i]=ans[i-1]+1;
	}
	for(int i=n;i>=1;--i)
	{
		if(a[i]==0)ans[i]=0;
		else ans[i]=min(ans[i],ans[i+1]+1);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}