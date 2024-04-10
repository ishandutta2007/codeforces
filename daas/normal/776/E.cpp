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
int n,K,pd[1000001],num[1000001],lim=1e6;
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
int calc(int v)
{
	int bck=1;
	for(int i=1;i<=num[0] && num[i]<=v;++i)
		if(v%num[i]==0)
		{
			int cnt=0;
			while(v%num[i]==0)
			{
				++cnt;
				v/=num[i];
			}
			bck*=(num[i]-1)*ksm(num[i],cnt-1);
		}
	return bck*(v==1?1:v-1);
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
	n=read(),K=(read()+1)/2;
	while(n!=1 && K)
	{
		--K;
		n=calc(n);
	}
	printf("%lld\n",n%mod);
	return 0;
}