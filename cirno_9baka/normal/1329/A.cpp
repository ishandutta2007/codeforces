#include<bits/stdc++.h>
using namespace std;
const int N=1005,E=262144;
const int M=998244353;
const int V=499122177;
int i,n,m,a[500005],ans[500005],k,j;
long long s[500005],p;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for(i=m;i>=1;--i)
		s[i]=s[i+1]+a[i];
	if(s[1]<n)
	{
		puts("-1");
		return 0;
	}
	for(j=1;j<=m;++j)
	{
		if(j+a[j]-1>n)
		{
			puts("-1");
			return 0;
		}
		if(j-1+s[j]<=n)
			break;
		ans[j]=j;
	}
	p=n;
	for(k=m;k>=j;--k)
	{
		p-=a[k];
		ans[k]=p+1;
	}
	for(i=1;i<=m;++i)
		printf("%d ",ans[i]);
}