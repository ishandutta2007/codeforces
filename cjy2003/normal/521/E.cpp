#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct bian
{
	int nxt,to;
}bi[400040];
vector<int>E[200020];
int n,m,head[200020],num,dep[200020],b[200020][2],id[200020],idnum,w[200020],f[200020],siz[200020];
bool used[200020];
int st[200020],tp;
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
void dfs(int v)
{
	id[v]=++idnum;siz[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(!dep[u])used[(i+1)/2]=1,dep[u]=dep[v]+1,E[v].push_back(u),f[u]=v,dfs(u),siz[v]+=siz[u];
	}
}
void dfs1(int v)
{
	for(auto u:E[v])
	{
		dfs1(u);
		w[v]+=w[u];
	}
}
int qlca(int x,int y)
{
	while(x!=y)
	{
		if(dep[x]>dep[y])x=f[x];
		else y=f[y];
	}
	return x;
}
bool in(int x,int y){return id[x]<=id[y]&&id[y]<id[x]+siz[x];}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		b[i][0]=x,b[i][1]=y;
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
		if(!dep[i])dep[i]=1,dfs(i);
//	for(int i=1;i<=n;++i)printf("%d ",f[i]);printf("\n");
	for(int i=1;i<=m;++i)
		if(!used[i])
		{
			if(dep[b[i][0]]<dep[b[i][1]])swap(b[i][0],b[i][1]);
			x=b[i][0],y=b[i][1];
			++w[x],--w[y];
		}
	for(int i=1;i<=n;++i)
		if(dep[i]==1)dfs1(i);
	int p=0,b1=0,b2=0,s,t,lca;
	for(int i=1;i<=n;++i)
		if(w[i]>=2){p=i;break;}
	if(!p)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=m;++i)
		if(!used[i]&&in(p,b[i][0])&&!in(p,b[i][1]))
		{
			if(!b1)b1=i;
			else{b2=i;break;}
		}
//	printf("%d %d %d\n",p,b1,b2);
	if(dep[b[b1][1]]>dep[b[b2][1]]||(dep[b[b1][1]]==dep[b[b2][1]]&&dep[b[b1][0]]<dep[b[b2][0]]))swap(b1,b2);
	lca=qlca(b[b1][0],b[b2][0]);
	if(lca==b[b2][0])
	{
		s=b[b2][1],t=b[b2][0];
		printf("2 %d %d\n",s,t);
		x=t;
		while(x!=s)st[++tp]=x,x=f[x];st[++tp]=s;
		printf("%d ",tp);
		while(tp)printf("%d ",st[tp--]);printf("\n");
		x=s;
		while(x!=b[b1][1])st[++tp]=x,x=f[x];st[++tp]=b[b1][1];
		x=b[b1][0];
		while(x!=t)st[++tp]=x,x=f[x];st[++tp]=t;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");tp=0;
	}
	else if(lca==b[b1][0])
	{
		s=b[b2][1],t=b[b1][0];
		x=t;
		while(x!=s)st[++tp]=x,x=f[x];st[++tp]=s;
		printf("%d ",tp);
		while(tp)printf("%d ",st[tp--]);printf("\n");
		x=s;
		while(x!=b[b1][1])st[++tp]=x,x=f[x];st[++tp]=b[b1][1],st[++tp]=t;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");tp=0;
		st[++tp]=s;
		x=b[b2][0];
		while(x!=t)st[++tp]=x,x=f[x];st[++tp]=t;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");tp=0;
	}
	else
	{
		s=b[b2][1],t=lca;
		x=t;
		while(x!=s)st[++tp]=x,x=f[x];st[++tp]=s;
		printf("%d ",tp);
		while(tp)printf("%d ",st[tp--]);printf("\n");
		x=s;
		while(x!=b[b1][1])st[++tp]=x,x=f[x];st[++tp]=b[b1][1];
		x=b[b1][0];
		while(x!=t)st[++tp]=x,x=f[x];st[++tp]=t;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");tp=0;
		st[++tp]=s;
		x=b[b2][0];
		while(x!=t)st[++tp]=x,x=f[x];st[++tp]=t;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i)printf("%d ",st[i]);printf("\n");tp=0;
	}
	return 0;
}