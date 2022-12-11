#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;
int n;
LL a[MaxN],b[MaxN],t;
int x[MaxN];
int main()
{
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;++i)
	scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
	scanf("%d",x+i);
	for(int i=1;i<=n;++i)
	if(x[i]<i)
	{
		puts("No");
		return 0;
	}
	int maxk=1;
	for(int i=1;i<=n;++i)
	{
		b[i]=std::max(a[i]+t,std::max(b[i],b[i-1]+1));
		for(int j=std::max(i,maxk);j<x[i];++j)
		b[j]=std::max(b[j],a[j+1]+t);
		maxk=std::max(maxk,x[i]);
	}
	for(int i=1;i<=n;++i)
	{
		if(x[i]!=n)
		if(b[x[i]]>=a[x[i]+1]+t)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;++i)
	printf("%lld%c",b[i]," \n"[i==n]);
	return 0;
}