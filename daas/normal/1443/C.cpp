#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int T,l,r,n,a[200001],b[200001],ans;
int check(int lim)
{
	long long sum=0,Lim=lim;
	for(int i=1;i<=n;++i)
		if(a[i]>lim)
			sum+=b[i];
	return sum<=Lim;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		l=1,r=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			r=max(r,a[i]);
		}
		for(int i=1;i<=n;++i)
			b[i]=read();
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))
				ans=mid,r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}