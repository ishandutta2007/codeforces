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
int T,p,q,lim=100000,pd[100001],num[100001];
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2)
			z=z*x;
		x=x*x;
		y/=2;
	}
	return z;
}
signed main()
{
	for(int i=2;i<=lim;++i)
	{
		if(!pd[i])
			num[++num[0]]=i;
		for(int j=1;j<=num[0] && i*num[j]<=lim;++j)
		{
			pd[i*num[j]]=1;
			if(i%num[j]==0)
				break;
		}
	}
	T=read();
	while(T--)
	{
		p=read(),q=read();
		if(gcd(p,q)!=q)
		{
			printf("%lld\n",p);
			continue;
		}
		int ans=0,fb=p;
		for(int i=1;i<=num[0] && num[i]<=q;++i)
			if(q%num[i]==0)
			{
				int cnt1=0,cnt2=0;
				while(q%num[i]==0)
				{
					q/=num[i];
					++cnt1;
				}
				while(p%num[i]==0)
				{
					p/=num[i];
					++cnt2;
				}
				ans=max(ans,fb/ksm(num[i],cnt2-cnt1+1));
			}
		if(q!=1)
		{
			int cnt1=1,cnt2=0;
			while(p%q==0)
			{
				p/=q;
				++cnt2;
			}
			ans=max(ans,fb/ksm(q,cnt2-cnt1+1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}