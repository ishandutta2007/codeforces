#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,dep[N],f[N],c[N],u[N],v[N],tf[N],td[N],tot,ans[N],i,l,r,ap;
int Find(int x)
{
	ap^=c[x];
	return (f[x]?Find(f[x]):x);
}
void uniot(int u,int v)
{
	ap=0;
	int x=Find(u),cx=ap;
	ap=0;
	int y=Find(v),cy=ap;
	if(x!=y)
	{
		if(dep[x]>dep[y])
			swap(x,y);
		tf[++tot]=x;
		td[tot]=dep[y];
		f[x]=y;
		dep[y]=max(dep[y],dep[x]+1);
		c[x]=cx^cy^1;
	}
}
void Del()
{
	int x=tf[tot],y=f[x];
	f[x]=0;
	c[x]=1;
	dep[y]=td[tot];
	--tot;
}
void dfs(int l,int r,int ll,int rr)
{
	if(l>r)
		return;
	if(ll==rr)
	{
		for(int i=l;i<=r;++i)
			ans[i]=rr;
		return;
	}
	int mid=ll+rr>>1;
	int i;
	int las=tot;
	for(i=rr;i>mid;--i)
	{
		ap=0;
		int x=Find(u[i]),cx=ap;
		ap=0;
		int y=Find(v[i]),cy=ap;
		if(x==y)
		{
			if(cx^cy^1)
				break;
		}
		else
			uniot(u[i],v[i]);
	}
	if(i>mid)
	{
		while(tot>las)
			Del();
		dfs(l,r,mid+1,rr);
		return;
	}
	else
	{
		int las2=tot;
		for(i=l;i<=min(r,mid-1);++i)
		{
			ap=0;
			int x=Find(u[i]),cx=ap;
			ap=0;
			int y=Find(v[i]),cy=ap;
			if(x==y)
			{
				if(cx^cy^1)
					break;
			}
			else
				uniot(u[i],v[i]);
		}
		--i;
		int tmp=i;
		while(tot>las2)
			Del();
		dfs(l,tmp,ll,mid);
		while(tot>las)
			Del();
		for(int j=l;j<=tmp;++j)
			uniot(u[j],v[j]);
		dfs(tmp+1,r,mid+1,rr);
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u[i],&v[i]);
		ans[i]=m+1;
	}
	for(i=1;i<=n;++i)
		c[i]=1;
	dfs(1,m,1,m);
	memset(f,0,sizeof(f));
	for(i=1;i<=n;++i)
		c[i]=1;
	memset(dep,0,sizeof(dep));
	tot=0;
	for(i=1;i<=m;++i)
	{
		ap=0;
		int x=Find(u[i]),cx=ap;
		ap=0;
		int y=Find(v[i]),cy=ap;
		if(x==y)
		{
			if(cx^cy^1)
				break;
		}
		else
			uniot(u[i],v[i]);
	}
	int al=i;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;++i)
		c[i]=1;
	memset(dep,0,sizeof(dep));
	tot=0;
	for(i=m;i>=1;--i)
	{
		ap=0;
		int x=Find(u[i]),cx=ap;
		ap=0;
		int y=Find(v[i]),cy=ap;
		if(x==y)
		{
			if(cx^cy^1)
				break;
		}
		else
			uniot(u[i],v[i]);
	}
	ans[0]=i;
	while(q--)
	{
		scanf("%d %d",&l,&r);
		puts((l>al||ans[l-1]>r)?"YES":"NO");
	}
}