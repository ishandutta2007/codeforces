#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int t,n,k,a[N],b[N],c[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int mmax=-1e10;
		for(int i=1;i<=n;++i)
			mmax=max(mmax,a[i]);
		for(int i=1;i<=n;++i)
			b[i]=mmax-a[i];
		mmax=-1e10;
		for(int i=1;i<=n;++i)
			mmax=max(mmax,b[i]);
		for(int i=1;i<=n;++i)
			c[i]=mmax-b[i];
		if(k%2==1)
		{
			for(int i=1;i<=n;++i)
				printf("%lld ",b[i]);
		}
		else
		{
			for(int i=1;i<=n;++i)
				printf("%lld ",c[i]);
		}
		printf("\n");
	}
	return 0;
}