#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a[1010],ans=0;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	cout<<ans<<endl;
}