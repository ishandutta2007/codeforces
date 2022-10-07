#include<bits/stdc++.h>
using namespace std;
const int M=998244853;
int n,m,i,j,ans,siz[55],id[55],k,p[55],fa[55];
int f[8388608];
unsigned long long g[8388608];
char c[55][55];
int Find(int x)
{
	return fa[x]?fa[x]=Find(fa[x]):x;
}
void uniot(int x,int y)
{
	int u=Find(x),v=Find(y);
	if(u!=v)
		fa[u]=v;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			if(c[i][j]=='A')
				uniot(i,j);
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			if(c[i][j]=='X')
				if(Find(i)==Find(j))
				{
					puts("-1");
					return 0;
				}
	for(i=1;i<=n;++i)
		++siz[Find(i)];
	for(i=1;i<=n;++i)
		if(siz[i]>1)
			id[i]=++k;
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			if(c[i][j]=='X')
				if(id[Find(i)]&&id[Find(j)])
				{
					p[id[Find(j)]-1]|=(1<<id[Find(i)]-1);
					p[id[Find(i)]-1]|=(1<<id[Find(j)]-1);
				}
	f[0]=1;
	for(i=1;i<(1<<k);++i)
	{
		int x=__lg(-i&i);
		if(!(p[x]&(i^(-i&i))))
			f[i]=f[i^(-i&i)];
	}
	for(j=0;j<k;++j)
		for(i=0;i<(1<<k);++i)
			if((i>>j)&1)
				f[i]+=f[i^(1<<j)];
	for(i=0;i<(1<<k);++i)
		g[i]=1;
	for(i=0;i<=k;++i)
	{
		unsigned long long s=0;
		for(j=0;j<(1<<k);++j)
			s+=(__builtin_popcount(j)&1?-1:1)*g[j];
		if(s)
			break;
		for(j=0;j<(1<<k);++j)
			g[j]=g[j]*f[j];
	}
	cout<<i+n-1;
}