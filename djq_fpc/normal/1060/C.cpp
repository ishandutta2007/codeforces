#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[2005],b[2005],s1[2005],s2[2005],ans,x;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<=m;i++) scanf("%I64d",&b[i]); 
	scanf("%I64d",&x);
	memset(s1,15,sizeof(s1));
	memset(s2,15,sizeof(s2));
	for (i=1;i<=n;i++)
	{
		long long s=0;
		for (j=i;j<=n;j++)
		{
			s+=a[j];
			s1[j-i+1]=min(s1[j-i+1],s);
		}
	}
	for (i=1;i<=m;i++)
	{
		long long s=0;
		for (j=i;j<=m;j++)
		{
			s+=b[j];
			s2[j-i+1]=min(s2[j-i+1],s);
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (s1[i]*s2[j]<=x) ans=max(ans,i*j);
		}
	}
	cout<<ans;
}