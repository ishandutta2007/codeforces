#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;
#define ri register int
const int M=1000000007;
int n,t,i,j,a[1000005];
ll s[1000005],mx,mn=1000000000000ll;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i+=2)
	{
		a[i]=(i<<1)-1;
		a[i+n]=(i<<1);
	}
	for(i=2;i<=n;i+=2)
	{
		a[i]=(i<<1);
		a[i+n]=(i<<1)-1;
	}
	for(i=1;i<=n*2;i++)
			s[i]=s[i-1]+a[i];
		for(i=n;i<=2*n;i++)
		{
		    mx=max(mx,s[i]-s[i-n]);
		    mn=min(mn,s[i]-s[i-n]);
		}
		for(i=1;i<n;i++)
		{
		      mx=max(mx,s[i]+s[n*2]-s[n+i]);
		      mn=min(mn,s[i]+s[n*2]-s[n+i]);
		}
	if(mx-mn<=1)
	{
		printf("YES\n");
		for(i=1;i<=n*2;i++)
			printf("%d ",a[i]);
	}
	else
		printf("NO\n");
}