#include<bits/stdc++.h>
using namespace std;
 
int n;
int a[2345];
int main()
{
	cin>>n;
	int t=0,cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=__gcd(t,a[i]);
		if(a[i]==1)cnt--;
	}
	if(t!=1)
	{
		puts("-1");
		return 0;
	}
	if(cnt<n)
	{
		printf("%d\n",cnt);
		exit(0);
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i];
		for(int j=i+1;j<=n;j++)
		{
			tmp=__gcd(tmp,a[j]);
			if(tmp==1)
			{
				ans=min(ans,j-i);
				break;
			}
		}
	}
	printf("%d\n",ans+n-1);
	return 0;
}