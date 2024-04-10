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
	int nxt,to,w;
}e[200020];
int n,m,q,head[200020],num;
long long a[200020],b[200020];
inline void add(int from,int to,int w){e[++num]=edge{head[from],to,w};head[from]=num;}
long long mi[800080],ad[800080];
long long w[800080];
#define ls k<<1,l,(l+r)>>1
#define rs k<<1|1,((l+r)>>1)+1,r
void build(int k,int l,int r,long long c[])
{
	ad[k]=0;
	if(l==r)return mi[k]=c[l],void();
	build(ls,c);build(rs,c);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)return mi[k]+=w,ad[k]+=w,void();
	add(ls,ll,rr,w);add(rs,ll,rr,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1])+ad[k];
}
void upd(int k,int l,int r,int p,long long w)
{
	if(l==r)return mi[k]=w,void();
	if(p<=(l+r)>>1)upd(ls,p,w);
	else upd(rs,p,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
#undef ls
#undef rs
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<n;++i)a[i]=read(),b[i+1]=read();
	for(int i=1,x,y,w;i<=m;++i)
	{
		x=read(),y=read(),w=read();
		add(x,y,w);
	}
	build(1,1,n,b);
	for(int i=1;i<=n;++i)
	{
		for(int j=head[i];j;j=e[j].nxt)add(1,1,n,1,e[j].to,e[j].w);
		w[i]=mi[1]+a[i];
	//	printf("%lld\n",w[i]);
	}
	build(1,1,n,w);
	for(int i=1;i<=n;++i)w[i]-=a[i];
	print(mi[1]),putc('\n');
	int x,y;
	while(q--)
	{
		x=read(),y=read();
		upd(1,1,n,x,y+w[x]);
		print(mi[1]),putc('\n');
	}
	flush();
	return 0;
}