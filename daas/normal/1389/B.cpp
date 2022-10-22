#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read()
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
int T,n,K,Z;
ll ans,a[100001];
inline ll fun(int z)
{
	int r=1+K-2*z;
	ll maxn=0,bck=a[1];
	if(r<2)
		return -1;
	for(register int i=2;i<=r;++i)
	{
		maxn=max(maxn,a[i]+a[i-1]);
		bck+=a[i];
	}
	return bck+maxn*z;
}
inline ll fun2(int z)
{
	int r=1+K-2*z+1;
	if(r<2)
		return -1;
	ll maxn=0,bck=a[1]+a[r-1];
	for(register int i=2;i<=r;++i)
	{
		maxn=max(maxn,a[i]+a[i-1]);
		bck+=a[i];
	}
	return bck+maxn*(z-1);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read(),Z=read();
		for(register int i=1;i<=n;++i)
			a[i]=read();
		ans=0;
		for(register int i=0;i<=Z;++i)
			ans=max(ans,fun(i));
		for(register int i=1;i<=Z;++i)
			ans=max(ans,fun2(i));
		printf("%lld\n",ans);
	}
	return 0;
}