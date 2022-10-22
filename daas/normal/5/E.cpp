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
int n,N,a[2000001],z[2000001],top,L[1000001],R[1000001],maxn,cnt,same[1000001];
ll ans;
int calc(int id)
{
	return id>n?id-n:id;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=a[i+n]=read();
		maxn=max(maxn,a[i]);
	}
	N=n*2;
	for(int i=1;i<=N;++i)
	{
		while(top && a[z[top]]<=a[i])
			--top;
		if(top && i>n)
			L[i-n]=calc(z[top]);
		z[++top]=i;
	}
	top=0;
	for(int i=N;i>=1;--i)
	{
		while(top && a[z[top]]<=a[i])
		{
			if(a[z[top]]==a[i])
				same[calc(i)]=max(same[calc(i)],same[calc(z[top])]+1);
			--top;
		}
		if(top && i<=n)
			R[i]=calc(z[top]);
		z[++top]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==maxn)
		{
			++cnt;
			continue;
		}
		//cout<<"cao "<<i<<" "<<L[i]<<" "<<R[i]<<" "<<same[i]<<endl;
		ans+=1+(L[i]!=R[i])+same[i];
	}
	ans+=1ll*cnt*(cnt-1)/2;
	printf("%lld\n",ans);
	return 0;
}