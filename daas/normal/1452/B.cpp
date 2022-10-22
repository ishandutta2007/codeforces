#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[100001],sum,maxn;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		sum=maxn=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		int fb=sum;
		if(sum%(n-1))
			sum=(sum/(n-1)+1)*(n-1);
		if(maxn>sum/(n-1))
			sum=maxn*(n-1);
		printf("%lld\n",sum-fb);
	}
	return 0;
}