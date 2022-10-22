#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<map>
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
map<pair<int,int>,bool>Q;
int n,m,q,head[200001],tot=1,headn[200001],totn,point[200001],cnt;
int jump[200001][18],deep[200001],tag[200001][2],root[200001],mem[200001];
int dfn[200001],low[200001],T,bridge[400001];
struct sb
{
	int to,nextn;
}a[400001],an[400001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
inline void ADDn(int from,int to)
{
	an[++totn].to=to,an[totn].nextn=headn[from];
	headn[from]=totn;
}
inline void tarjan(int u,int from)
{
	dfn[u]=low[u]=++T;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(!dfn[v])
		{
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				bridge[i]=bridge[i^1]=1;
		}
		else
			if(i!=(from^1))
				low[u]=min(low[u],dfn[v]);
	}
}
inline void fun(int u)
{
	point[u]=cnt;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(bridge[i] || point[v])
			continue;
		fun(v);
	}
}
inline void format(int u,int fa)
{
	deep[u]=deep[fa]+1;
	jump[u][0]=fa;
	int LOG=log2(deep[u]);
	for(register int i=1;i<=LOG;++i)
		jump[u][i]=jump[jump[u][i-1]][i-1];
	for(register int i=headn[u];i!=0;i=an[i].nextn)
	{
		int v=an[i].to;
		if(v==fa)
			continue;
		mem[v]=mem[u];
		format(v,u);
	}
}
inline int LCA(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int C=deep[x]-deep[y];
	int LOG=log2(C);
	for(register int i=0;i<=LOG;++i)
		if(C&(1<<i))
			x=jump[x][i];
	if(x==y)
		return x;
	LOG=log2(deep[x]);
	for(register int i=LOG;i>=0;--i)
		if(jump[x][i]!=jump[y][i])
		{
			x=jump[x][i];
			y=jump[y][i];
		}
	return jump[x][0];
}
inline int get(int u,int fa)
{
	for(register int i=headn[u];i!=0;i=an[i].nextn)
	{
		int v=an[i].to;
		if(v==fa)
			continue;
		int bck=get(v,u);
		if(!bck)
			return 0;
		tag[u][0]+=tag[v][0];
		tag[u][1]+=tag[v][1];
	}
	if(tag[u][0] && tag[u][1])
		return 0;
	return 1;
}
int main()
{
	n=read(),m=read(),q=read();
	for(register int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i])
			tarjan(i,0);
	for(register int i=1;i<=n;++i)
		if(!point[i])
			++cnt,fun(i);
	for(register int u=1;u<=n;++u)
		for(register int i=head[u];i!=0;i=a[i].nextn)
		{
			int v=a[i].to;
			if(point[u]==point[v] || point[v]<point[u] || Q[make_pair(point[u],point[v])])
				continue;
			Q[make_pair(point[u],point[v])]=1;
			ADDn(point[u],point[v]);
			ADDn(point[v],point[u]);
		}
	for(register int i=1;i<=cnt;++i)
		if(!deep[i])
			mem[i]=i,format(root[++root[0]]=i,0);
	for(register int i=1;i<=q;++i)
	{
		int s=point[read()],t=point[read()];
		if(s==t)
			continue;
		if(mem[s]!=mem[t])
		{
			puts("No");
			return 0;
		}
		int lca=LCA(s,t);
		++tag[s][0];
		++tag[t][1];
		--tag[lca][0];
		--tag[lca][1];
	}
	for(register int i=1;i<=root[0];++i)
		if(!get(root[i],0))
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}