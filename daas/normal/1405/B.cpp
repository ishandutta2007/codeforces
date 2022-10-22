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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[100001],mem,ans;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		mem=ans=0;
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i)
		{
			if(a[i]>0) mem+=a[i];
			else
			{
				a[i]+=mem;
				if(a[i]>0) mem=a[i];
				else mem=0,ans-=a[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}