#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy 
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	inline void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename T>
	inline void print(T x)
	{
		if(!x){putc('0');return;}
		if(x<0)putc('-'),x=-x;
		static int st[30],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
const int bsiz=1000;
struct edge
{
	int nxt,to;
}e[600060];
int n,m,a[300030],head[300030],num;
int in[300030],out[300030],dfnum,p[600060];
int f[300030],dep[300030],siz[300030],zson[300030],tp[300030];
int st[1500],ed[1500],bl[600060],bnum;
struct query
{
	int x,y,w,l,r,id;
	friend bool operator < (query a,query b){return bl[a.x]==bl[b.x]?bl[a.x]&1?a.y<b.y:a.y>b.y:a.x<b.x;}
}q[300030];
int ans[300030];
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
void dfs1(int v,int fa)
{
	in[v]=++dfnum;p[dfnum]=v;
	f[v]=fa;dep[v]=dep[fa]+1;siz[v]=1;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		siz[v]+=siz[u];
		if(siz[u]>siz[zson[v]])zson[v]=u;
	}
	out[v]=++dfnum;p[dfnum]=v;
}
void dfs2(int v,int topp)
{
	tp[v]=topp;
	if(zson[v])dfs2(zson[v],topp);
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==f[v]||u==zson[v])continue;
		dfs2(u,u);
	}
}
int lca(int x,int y)
{
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]>=dep[tp[y]])x=f[tp[x]];
		else y=f[tp[y]];
	}
	return dep[x]>=dep[y]?y:x;
}
bool o[300030];
int cnt[1000];
void upd(int x)
{
	o[x]^=1;
	if(o[x])++cnt[bl[x]];
	else --cnt[bl[x]];
}
int qry(int x,int y)
{
	if(bl[x]==bl[y])
	{
		for(int i=x;i<=y;++i)if(o[i])return i;
		return -1;
	}
	for(int i=x;i<=ed[bl[x]];++i)if(o[i])return i;
	for(int i=bl[x]+1;i<bl[y];++i)
		if(cnt[i])
			for(int j=st[i];j<=ed[i];++j)if(o[j])return j;
	for(int i=st[bl[y]];i<=y;++i)if(o[i])return i;
	return -1;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=2*n;i+=bsiz)
	{
		++bnum;
		st[bnum]=i,ed[bnum]=min(i+bsiz-1,2*n);
		for(int j=st[bnum];j<=ed[bnum];++j)bl[j]=bnum;
	}
	for(int i=1,x,y;i<=m;++i)
	{
		x=read(),y=read(),q[i].l=read(),q[i].r=read(),q[i].id=i;
		if(in[x]>in[y])swap(x,y);
		int l=lca(x,y);
		if(l==x)q[i].x=in[x],q[i].y=in[y];
		else q[i].x=out[x],q[i].y=in[y],q[i].w=a[l];
	}
	sort(q+1,q+1+m);
	for(int i=1,x=q[1].x,y=x-1;i<=m;++i)
	{
		while(y<q[i].y)++y,upd(a[p[y]]);
		while(x>q[i].x)--x,upd(a[p[x]]);
		while(y>q[i].y)upd(a[p[y]]),--y;
		while(x<q[i].x)upd(a[p[x]]),++x;
		if(q[i].w)upd(q[i].w);
		ans[q[i].id]=qry(q[i].l,q[i].r);
		if(q[i].w)upd(q[i].w);
	}
	for(int i=1;i<=m;++i)print(ans[i]),putc('\n');
	flush();
	cerr<<bsiz<<' '<<clock()<<endl;
	return 0;
}