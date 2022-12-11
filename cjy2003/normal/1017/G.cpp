#include<cstdio>
#include<cstring>
#include<algorithm>
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
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename o>
	inline void print(o x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
struct edge
{
	int nxt,to;
}e[100010];
int n,q,head[100010],num,f[100010];
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int dep[100010],siz[100010],zson[100010],id[100010],dy[100010],tp[100010],idnum;
void dfs1(int v)
{
	siz[v]=1;dep[v]=dep[f[v]]+1;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		dfs1(u);
		siz[v]+=siz[u];
		if(siz[u]>siz[zson[v]])zson[v]=u;
	}
}
void dfs2(int v,int topp)
{
	id[v]=++idnum,tp[v]=topp,dy[idnum]=v;
	if(zson[v])dfs2(zson[v],topp);
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==zson[v])continue;
		dfs2(u,u);
	}
}
pair<int,int>s[400040];
pair<int,int>operator + (pair<int,int>a,pair<int,int>b){return make_pair(max(a.first+b.second,b.first),a.second+b.second);}
int mxdep[400040];
bool tag[400040];
void build(int k,int l,int r)
{
	if(l==r)return s[k].first=mxdep[k]=dep[dy[l]],void();
	build(k<<1,l,(l+r)>>1);
	build(k<<1|1,((l+r)>>1)+1,r);
	s[k]=s[k<<1]+s[k<<1|1];
	mxdep[k]=max(mxdep[k<<1],mxdep[k<<1|1]);
}
void pushdown(int k)
{
	s[k<<1]=make_pair(mxdep[k<<1],0);
	s[k<<1|1]=make_pair(mxdep[k<<1|1],0);
	tag[k<<1]=tag[k<<1|1]=1;
	tag[k]=0;
}
void add(int k,int l,int r,int p,int w)
{
	if(l==r)return s[k].first+=w,s[k].second+=w,void();
	if(tag[k])pushdown(k);
	if(p<=(l+r)>>1)add(k<<1,l,(l+r)>>1,p,w);
	else add(k<<1|1,((l+r)>>1)+1,r,p,w);
	s[k]=s[k<<1]+s[k<<1|1];
}
pair<int,int>query(int k,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return s[k];
	if(tag[k])pushdown(k);
	if(ll>(l+r)>>1)return query(k<<1|1,((l+r)>>1)+1,r,ll,rr);
	if(rr<=(l+r)>>1)return query(k<<1,l,(l+r)>>1,ll,rr);
	return query(k<<1,l,(l+r)>>1,ll,rr)+query(k<<1|1,((l+r)>>1)+1,r,ll,rr);
}
void clear(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr)return s[k]=make_pair(mxdep[k],0),tag[k]=1,void();
	if(tag[k])pushdown(k);
	clear(k<<1,l,(l+r)>>1,ll,rr);
	clear(k<<1|1,((l+r)>>1)+1,r,ll,rr);
	s[k]=s[k<<1]+s[k<<1|1];
}
int query(int x)
{
	pair<int,int>cur=make_pair(0,0);
	while(x)
	{
		cur=query(1,1,n,id[tp[x]],id[x])+cur;
		x=f[tp[x]];
	}
	return cur.first;
}
void clear(int x)
{
	clear(1,1,n,id[x],id[x]+siz[x]-1);
	int t=query(x);
	add(1,1,n,id[x],dep[x]-t);
}
int main()
{
	n=read(),q=read();
	for(int i=2;i<=n;++i)
	{
		f[i]=read();
		add(f[i],i);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	int op,x;
	while(q--)
	{
		op=read(),x=read();
		if(op==1)add(1,1,n,id[x],1);
		else if(op==2)clear(x);
		else puts(query(x)>dep[x]?"black":"white");
	}
	flush();
	return 0;
}