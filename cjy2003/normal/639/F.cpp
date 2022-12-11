#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	inline int read()
	{
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
}
using io::read;
struct graph
{
	struct bian
	{
		int nxt,to;
	}bi[600060];
	int head[300030],num;
	inline void add(int from,int to)
	{
		bi[++num]=bian{head[from],to};
		head[from]=num;
	}
	int dfn[300030],low[300030],dfnum,st[300030],tp,bl[300030],cnt;
	void tarjan(int v,int fb)
	{
		dfn[v]=low[v]=++dfnum,st[++tp]=v;
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			if((i+1)/2==(fb+1)/2)continue;
			u=bi[i].to;
			if(!dfn[u])
			{
				tarjan(u,i);
				if(low[u]<low[v])low[v]=low[u];
			}
			else if(dfn[u]<low[v])low[v]=dfn[u];
		}
		if(low[v]==dfn[v])
		{
			bl[v]=++cnt;
			while(st[tp]^v)bl[st[tp--]]=cnt;
			--tp;
		}
	}
}G,g;
struct tree
{
	struct bian
	{
		int nxt,to;
	}bi[600060];
	int head[300030],num,siz[300030],zson[300030],tp[300030],f[300030],dep[300030],id[300030],idnum,dy[300030],rt[300030];
	inline void add(int from,int to)
	{
	//	printf("%d %d\n",from,to);
		bi[++num]=bian{head[from],to};
		head[from]=num;
	}
	void dfs1(int v,int fa)
	{
		id[v]=++idnum;dy[idnum]=v;siz[v]=1;f[v]=fa;dep[v]=dep[fa]+1;rt[v]=rt[fa];
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if(u==fa)continue;
			dfs1(u,v);
			siz[v]+=siz[u];
			if(siz[u]>siz[zson[v]])zson[v]=u;
		}
	}
	void dfs2(int v,int topp)
	{
		tp[v]=topp;
		if(zson[v])dfs2(zson[v],topp);
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if(u==f[v]||u==zson[v])continue;
			dfs2(u,u);
		}
	}
	inline int lca(int x,int y)
	{
		while(tp[x]!=tp[y])
		{
			if(dep[tp[x]]<dep[tp[y]])y=f[tp[y]];
			else x=f[tp[x]];
		}
		if(dep[x]<dep[y])return x;
		else return y;
	}
}T;
int n,q,m,n1,m1,R,p[300030];
bool vis[300030];
int st[300030],tp,a[300030],cnt,acnt,fa[300030],f[300030];
inline bool cmp(int x,int y){return T.id[x]<T.id[y];}
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
void merge(int x,int y)
{
	int s=T.dy[lower_bound(a+1,a+1+acnt,T.id[x])-a],t=T.dy[upper_bound(a+1,a+1+acnt,T.id[y])-a-1];
	if(T.id[x]<=T.id[s]&&T.id[s]<=T.id[y]&&T.id[x]<=T.id[t]&&T.id[t]<=T.id[y])while(find(t)!=find(s))f[find(t)]=find(fa[find(t)]);
}
int main()
{
	n=read(),m=read(),q=read();
	int x,y;
	for(int i=1;i<=m;++i)
	{
		x=read(),y=read();
		G.add(x,y),G.add(y,x);
	}
	for(int i=1;i<=n;++i)if(!G.dfn[i])G.tarjan(i,0);
//	for(int i=1;i<=n;++i)printf("%d ",G.bl[i]);printf("\n");
	for(int i=1;i<=n;++i)
		for(int j=G.head[i];j;j=G.bi[j].nxt)
			if(G.bl[i]!=G.bl[G.bi[j].to])T.add(G.bl[i],G.bl[G.bi[j].to]);
	for(int i=1;i<=G.cnt;++i)if(!T.dep[i])T.rt[0]=i,T.dfs1(i,0);
	for(int i=1;i<=G.cnt;++i)if(T.dep[i]==1)T.dfs2(i,i);
//	for(int i=1;i<=G.cnt;++i)printf("%d ",T.f[i]);printf("\n");
	for(int t=1;t<=q;++t)
	{
		n1=read(),m1=read();
		for(int i=1;i<=n1;++i)
		{
			x=p[i]=G.bl[(read()+R-1)%n+1];
			if(!vis[x])vis[x]=1,a[++cnt]=x;
		}
		for(int i=1;i<=m1;++i)
		{
			x=G.bl[(read()+R-1)%n+1],y=G.bl[(read()+R-1)%n+1];
			g.add(x,y),g.add(y,x);
			if(!vis[x])vis[x]=1,a[++cnt]=x;
			if(!vis[y])vis[y]=1,a[++cnt]=y;
		}
		sort(a+1,a+1+cnt,cmp);acnt=cnt;
		tp=0;
		for(int i=1;i<=cnt;++i)
		{
			if(!tp||T.rt[st[tp]]!=T.rt[a[i]])
			{
				while(tp>1)g.add(st[tp-1],st[tp]),g.add(st[tp],st[tp-1]),--tp;
				st[tp=1]=T.rt[a[i]];
				if(!vis[T.rt[a[i]]])vis[T.rt[a[i]]]=1,a[++acnt]=T.rt[a[i]];
				else continue;
			}
			int l=T.lca(a[i],st[tp]);
			while(T.id[st[tp]]>T.id[l])
			{
				if(T.id[st[tp-1]]>=T.id[l])
				{
					g.add(st[tp-1],st[tp]),g.add(st[tp],st[tp-1]);
					--tp;
				}
				else
				{
					g.add(l,st[tp]),g.add(st[tp],l);
					st[tp]=l;a[++acnt]=l;
				}
			}
			st[++tp]=a[i];
		}
	//	for(int i=1;i<=acnt;++i)printf("%d ",a[i]);printf("\n");
		while(tp>1)g.add(st[tp-1],st[tp]),g.add(st[tp],st[tp-1]),--tp;
	//	for(int i=1;i<=G.cnt;++i)
	//		for(int j=g.head[i];j;j=g.bi[j].nxt)printf("%d %d\n",i,g.bi[j].to);
	//	printf("\n");
		for(int i=1;i<=acnt;++i)
			if(!g.dfn[a[i]])g.tarjan(a[i],0);
		bool flag=0;
		for(int i=2;i<=n1;++i)
			if(g.bl[p[i]]!=g.bl[p[1]]){flag=1;break;}
		if(flag)printf("NO\n");
		else printf("YES\n"),(R+=t)>=n?R-=n:0;
		for(int i=1;i<=acnt;++i)vis[a[i]]=g.head[a[i]]=g.dfn[a[i]]=g.low[a[i]]=0;g.num=0;g.cnt=0;g.dfnum=0;
		cnt=0;
	}
	return 0;
}