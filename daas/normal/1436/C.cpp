#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e9+7;
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
int n,X,pos,sum[1001],numl,numr;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2)
			z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
int A(int m,int n)
{
	if(m<0 || n<0 || m<n)
		return 0;
	return 1ll*sum[m]*ksm(sum[m-n],mod-2)%mod;
}
int main()
{
	n=read(),X=read(),pos=read();
	sum[0]=1;
	for(int i=1;i<=n;++i)
		sum[i]=1ll*sum[i-1]*i%mod;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(mid<=pos)
		{
			numl++,l=mid+1;
			if(mid==pos)
				--numl;
		}
		else
			numr++,r=mid;
	}
	printf("%I64d\n",1ll*A(X-1,numl)*A(n-X,numr)%mod*A(n-1-numl-numr,n-1-numl-numr)%mod);
	return 0;
}