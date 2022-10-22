#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define int long long
#define ll long long
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
int n,q;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z*=x;
		x*=x;
		y>>=1;
	}
	return z;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%lld ",(i%2?0:ksm(2,i+j-3)));
		putchar('\n');
	}
	fflush(stdout);
	q=read();
	while(q--)
	{
		int x=read(),mem[60],top=0,L[60],R[60],cnt=0;
		while(x)
		{
			mem[++top]=x&1;
			x>>=1;
		}
		for(int l=1,r;l<=top;l=r+1)
		{
			r=l;
			if(!mem[l]) continue;
			while(r+1<=top && mem[r+1]) ++r;
			L[++cnt]=l-1;
			R[cnt]=r-1;
		}
		int X=1,Y=1;
		printf("%lld %lld\n",X,Y);
		for(int i=1;i<=cnt;++i)
		{
			while(X+1+Y-3!=L[i])
			{
				++Y;
				printf("%lld %lld\n",X,Y);
			}
			++X;
			printf("%lld %lld\n",X,Y);
			while(X+Y-3!=R[i])
			{
				++Y;
				printf("%lld %lld\n",X,Y);
			}
			if(X!=n)
			{
				++X;
				printf("%lld %lld\n",X,Y);
			}
		}
		while(Y!=n)
		{
			++Y;
			printf("%lld %lld\n",X,Y);
		}
		fflush(stdout);
	}
	return 0;
}