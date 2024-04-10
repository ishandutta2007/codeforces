#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
}e[200020];
int n,head[100010],num,trt,ans[100010];
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int id[100010],dy[100010],siz[100010],mx[100010],mx1[100010],mi[100010],idnum;
void dfs1(int v,int fa)
{
	id[v]=++idnum,dy[idnum]=v,siz[v]=1,mi[v]=0x3f3f3f3f;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		siz[v]+=siz[u];
		if(siz[u]>mx[v])mx1[v]=mx[v],mx[v]=siz[u];
		else if(siz[u]>mx1[v])mx1[v]=siz[u];
		if(siz[u]<mi[v])mi[v]=siz[u];
	}
	if(v!=trt)
	{
		if(n-siz[v]>mx[v])mx1[v]=mx[v],mx[v]=n-siz[v];
		else if(n-siz[v]>mx1[v])mx1[v]=n-siz[v];
		if(n-siz[v]<mi[v])mi[v]=n-siz[v];
	}
//	printf("%d %d %d %d\n",v,mx[v],mx1[v],mi[v]);
}
namespace seg
{
	int ch[6000000][2],cnt[6000000],tot;
	int add(int pre,int l,int r,int p,int w)
	{
		int now=++tot;
		cnt[now]=cnt[pre]+w;
		if(l==r)return now;
		if(p<=(l+r)>>1)ch[now][0]=add(ch[pre][0],l,(l+r)>>1,p,w),ch[now][1]=ch[pre][1];
		else ch[now][1]=add(ch[pre][1],((l+r)>>1)+1,r,p,w),ch[now][0]=ch[pre][0];
		return now;
	}
	void print(int now,int pre,int l,int r)
	{
		if(l==r)
		{
			printf("%d ",cnt[now]-cnt[pre]);
			return;
		}
		print(ch[now][0],ch[pre][0],l,(l+r)>>1);
		print(ch[now][1],ch[pre][1],((l+r)>>1)+1,r);
	}
	int findl(int now,int pre,int l,int r,int pos)
	{
		if(l>pos)return 0;
		if(l==r)return cnt[now]>cnt[pre]?l:0;
		if(r<=pos)
		{
			if(cnt[ch[now][1]]-cnt[ch[pre][1]])return findl(ch[now][1],ch[pre][1],((l+r)>>1)+1,r,pos);
			else return findl(ch[now][0],ch[pre][0],l,(l+r)>>1,pos);
		}
		int s=findl(ch[now][1],ch[pre][1],((l+r)>>1)+1,r,pos);
		if(s)return s;
		return findl(ch[now][0],ch[pre][0],l,(l+r)>>1,pos);
	}
	int findr(int now,int pre,int l,int r,int pos)
	{
		if(r<pos)return n+1;
		if(l==r)return cnt[now]>cnt[pre]?l:n+1;
		if(l>=pos)
		{
			if(cnt[ch[now][0]]-cnt[ch[pre][0]])return findr(ch[now][0],ch[pre][0],l,(l+r)>>1,pos);
			else return findr(ch[now][1],ch[pre][1],((l+r)>>1)+1,r,pos);
		}
		int s=findr(ch[now][0],ch[pre][0],l,(l+r)>>1,pos);
		if(s!=n+1)return s;
		return findr(ch[now][1],ch[pre][1],((l+r)>>1)+1,r,pos);
	}
}
int rt[100010],nrt;
void dfs2(int v,int fa)
{
	bool flag=0;
	if(mx[v]==mx1[v])ans[v]=mx[v];
	else
	{
		for(int i=head[v],u;i;i=e[i].nxt)
		{
			u=e[i].to;
			if(u==fa)continue;
			if(siz[u]==mx[v])
			{
				int x=seg::findl(rt[id[u]+siz[u]-1],rt[id[u]-1],1,n,(mx[v]-mi[v])/2),y=seg::findr(rt[id[u]+siz[u]-1],rt[id[u]-1],1,n,(mx[v]-mi[v])/2);
		//		printf("%d:",v);
		//		seg::print(rt[id[u]+siz[u]-1],rt[id[u]-1],1,n);
		//		printf("\n");
		//		printf("%d %d\n",x,y);
				ans[v]=min(max(mi[v]+x,mx[v]-x),max(mi[v]+y,mx[v]-y));
			}
		}
		if(n-siz[v]==mx[v])
		{
			// printf("%d:\n",v);
			// seg::print(nrt,0,1,n);
			// printf("\n");
			int x=seg::findl(nrt,0,1,n,(mx[v]-mi[v])/2+siz[v])-siz[v],y=seg::findr(nrt,0,1,n,(mx[v]-mi[v])/2+siz[v])-siz[v];
			// printf("%d %d\n",x,y);
			ans[v]=min(max(mi[v]+x,mx[v]-x),max(mi[v]+y,mx[v]-y));
			nrt=seg::add(nrt,1,n,siz[v],1);flag=1;
			
			x=seg::findl(rt[n],rt[id[v]+siz[v]-1],1,n,(mx[v]-mi[v])/2),y=seg::findr(rt[n],rt[id[v]+siz[v]-1],1,n,(mx[v]-mi[v])/2);
			// printf("%d:",v);
			// seg::print(rt[n],nrt,1,n);
			// printf("\n");
			// printf("%d:%d %d\n",v,x,y);
			ans[v]=min(ans[v],min(max(mi[v]+x,mx[v]-x),max(mi[v]+y,mx[v]-y)));

			x=seg::findl(rt[id[v]],nrt,1,n,(mx[v]-mi[v])/2),y=seg::findr(rt[id[v]],nrt,1,n,(mx[v]-mi[v])/2);
			// printf("%d:",v);
			// seg::print(rt[n],nrt,1,n);
			// printf("\n");
			// printf("%d:%d %d\n",v,x,y);
			ans[v]=min(ans[v],min(max(mi[v]+x,mx[v]-x),max(mi[v]+y,mx[v]-y)));
		}
		ans[v]=max(ans[v],mx1[v]);
	}
	if(!flag)nrt=seg::add(nrt,1,n,siz[v],1);
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs2(u,v);
	}
	nrt=seg::add(nrt,1,n,siz[v],-1);
}
int main()
{
	n=read();
	for(int i=1,x,y;i<=n;++i)
	{
		x=read(),y=read();
		if(!x||!y)trt=x+y;
		else add(x,y),add(y,x);
	}
	dfs1(trt,0);
	for(int i=1;i<=n;++i)rt[i]=seg::add(rt[i-1],1,n,siz[dy[i]],1);
	dfs2(trt,0);
	for(int i=1;i<=n;++i)print(ans[i]),putc('\n');
	flush();
	return 0;
}