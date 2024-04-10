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
int S,T,M,ans,minn=0x3f3f3f3f3f3f3f3f,n,a[100001];
signed main()
{
	S=read(),T=read(),M=read();
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	if(a[1]>S)
	{
		printf("%lld\n",S);
		return 0;
	}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && a[r+1]==a[l])
			++r;
		if(a[r]==0)
			continue;
		int tim=S+(l-1)*M-1;
		if(tim+M>=T)
			break;
		if(tim<a[l]-1)
		{
			printf("%lld\n",a[l]-1);
			return 0;
		}
		if(tim-a[l]+2<minn)
			minn=tim-a[l]+2,ans=a[l]-1;
	}
	int tim=S+n*M-1;
	if(tim+M<T)
		printf("%lld\n",tim+1);
	else
		printf("%lld\n",ans);
	return 0;
}