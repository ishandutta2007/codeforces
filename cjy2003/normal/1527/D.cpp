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
int T,n;
struct edge
{
	int nxt,to;
}e[400040];
int head[200020],num;
void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int siz[200020],f[200020],mi[200020],miup[200020],sz[200020];
int p[200020],pcnt,pos[200020];
long long ans[200020];
void dfs(int v,int fa)
{
	siz[v]=1;f[v]=fa;mi[v]=v;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs(u,v);
		siz[v]+=siz[u];
		mi[v]=min(mi[v],mi[u]);
	}
}
void dfs1(int v,int fa)
{
	int mi_1=0x3f3f3f3f,mi_2=0x3f3f3f3f;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		if(mi[u]<mi_1)mi_2=mi_1,mi_1=mi[u];
		else if(mi[u]<mi_2)mi_2=mi[u];
	}
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		if(mi[u]==mi_1)miup[u]=min(miup[v],min(v,mi_2)),dfs1(u,v);
		else miup[u]=min(miup[v],min(v,mi_1)),dfs1(u,v);
	}
}
void dfs2(int v,int fa,int lim)
{
	if(v<lim)p[++pcnt]=v,pos[v]=pcnt;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs2(u,v,lim);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1,x,y;i<n;++i)
		{
			x=read(),y=read();
			add(x,y);add(y,x);
		}
		dfs(0,-1);
		miup[0]=0x3f3f3f3f;
		dfs1(0,-1);
		int lcnt=n,st;
		for(int i=0;i<n;++i)
		{
			int mi_1=0x3f3f3f3f,mi_2=0x3f3f3f3f,mi_3=0x3f3f3f3f;
			for(int j=head[i],u;j;j=e[j].nxt)
			{
				u=e[j].to;
				if(u==f[i])continue;
				if(mi[u]<mi_1)mi_3=mi_2,mi_2=mi_1,mi_1=mi[u];
				else if(mi[u]<mi_2)mi_3=mi_2,mi_2=mi[u];
				else if(mi[u]<mi_3)mi_3=mi[u];
			}
			if(f[i]!=-1)
			{
				if(miup[i]<mi_1)mi_3=mi_2,mi_2=mi_1,mi_1=miup[i];
				else if(miup[i]<mi_2)mi_3=mi_2,mi_2=miup[i];
				else if(miup[i]<mi_3)mi_3=miup[i];
			}
			lcnt=min(lcnt,mi_3);
		}
		for(int i=0;i<lcnt;++i)
		{
			int cnt=0,s=0;
			for(int j=head[i],u;j;j=e[j].nxt)
			{
				u=e[j].to;
				if(u==f[i])continue;
				if(mi[u]<i)s+=siz[u],++cnt;
			}
			if(miup[i]<i)s+=n-siz[i],++cnt;
			if(cnt==1)
			{
				st=i;
				sz[i]=n-s;
			}
		}
		// printf("st:%d\n",st);
		// printf("lcnt:%d\n",lcnt);
		dfs2(st,-1,lcnt);
		// for(int i=1;i<=pcnt;++i)printf("%d ",p[i]);
		// printf("\n");
		ans[0]=1ll*n*(n-1)/2;
		for(int j=head[0],u;j;j=e[j].nxt)
		{
			u=e[j].to;
			if(mi[u]==1)sz[0]=n-siz[u];
			ans[0]-=1ll*siz[u]*(siz[u]-1)/2;
		}
		// for(int i=0;i<n;++i)printf("%d ",sz[i]);
		// printf("\n");
		for(int i=1,l=pos[0],r=pos[0],lsz=sz[0],rsz=sz[0];i<lcnt;++i)
		{
			if(pos[i]>r)r=pos[i],rsz=sz[i];
			else if(pos[i]<l)l=pos[i],lsz=sz[i];
			ans[i]=1ll*lsz*rsz;
		}
		for(int i=lcnt-1;i;--i)ans[i]=ans[i-1]-ans[i];
		ans[0]=1ll*n*(n-1)/2-ans[0];
		ans[lcnt]=1ll*n*(n-1)/2;
		for(int i=0;i<lcnt;++i)ans[lcnt]-=ans[i];
		for(int i=0;i<=n;++i)print(ans[i]),putc(i==n?'\n':' ');
		memset(ans,0,(n+1)<<3);
		memset(sz,0,n<<2);
		pcnt=0;
		memset(head,0,n<<2);
		num=0;
	}
	flush();
	return 0;
}