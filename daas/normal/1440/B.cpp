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
int T,n,K,N,a[200001],ans;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		N=n*K;
		for(int i=1;i<=N;++i)
			a[i]=read();
		ans=0;
		int del=(n+1)/2-1,P=n-(n+1)/2+1;
		for(int i=del*K+1,j=1;j<=K;++j,i+=P)
			ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}