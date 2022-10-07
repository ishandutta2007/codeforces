#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a[N],f[N],i,x,m,u,v;
long long siz[N],s;
struct str{
	int v,x;
};
vector<str> g[N];
int Find(int i)
{
	return f[i]?f[i]=Find(f[i]):i;
}
void dfs(int i,int fa)
{
	siz[i]=a[i];
	for(auto it:g[i])
		if(it.v!=fa)
		{
			dfs(it.v,i);
			siz[i]=siz[i]+siz[it.v]-x;
		}
}
void cal(int i,int fa)
{
	for(auto it:g[i])
		if(it.v!=fa)
			if(siz[it.v]>=0)
				cal(it.v,i);
	for(auto it:g[i])
		if(it.v!=fa)
			if(siz[it.v]>=x)
				printf("%d\n",it.x);
	for(auto it:g[i])
		if(it.v!=fa)
			if(siz[it.v]<x)
				printf("%d\n",it.x);
	for(auto it:g[i])
		if(it.v!=fa)
			if(siz[it.v]<0)
				cal(it.v,i);
}
int main()
{
	scanf("%d %d %d",&n,&m,&x);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s<1ll*x*(n-1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		int x=Find(u),y=Find(v);
		if(x!=y)
		{
			f[x]=y;
			g[u].push_back({v,i});
			g[v].push_back({u,i});
		}
	}
	dfs(1,0);
	cal(1,0);
}