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
int n,c[100010];
struct edge
{
	int nxt,to;
}e[200020];
int head[100010],num;
void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int mx[3000020],tot,ch[3000020][2],rt[100010];
long long mxsum[3000020],ans[100010];
void ins(int &k,int l,int r,int p)
{
	k=++tot;
	mx[k]=1,mxsum[k]=p;
	if(l==r)return;
	if(p<=(l+r)>>1)ins(ch[k][0],l,(l+r)>>1,p);
	else ins(ch[k][1],((l+r)>>1)+1,r,p);
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y)return x+y;
	if(l==r)
	{
		mx[x]+=mx[y];
		return x;
	}
	ch[x][0]=merge(ch[x][0],ch[y][0],l,(l+r)>>1),ch[x][1]=merge(ch[x][1],ch[y][1],((l+r)>>1)+1,r);
	mx[x]=max(mx[ch[x][0]],mx[ch[x][1]]);
	mxsum[x]=(mx[x]==mx[ch[x][0]]?mxsum[ch[x][0]]:0)+(mx[x]==mx[ch[x][1]]?mxsum[ch[x][1]]:0);
	return x;
}
void dfs(int v,int fa)
{
	ins(rt[v],1,n,c[v]);
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs(u,v);
		rt[v]=merge(rt[v],rt[u],1,n);
	}
	ans[v]=mxsum[rt[v]];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)print(ans[i]),putc(' ');
	flush();
	return 0;
}