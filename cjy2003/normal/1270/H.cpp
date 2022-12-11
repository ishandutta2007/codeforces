#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
	char buff[N],*T=buff;
	#define putc(ch) T==buff+N?fwrite(buff,1,N,stdout),T=buff:0,*T++=ch
	inline void print(int x)
	{
		if(!x){putc('0');return;}
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using namespace io;
const int inf=0x3f3f3f3f;
inline int qmax(int x,int y){return x<y?y:x;}
inline int qmin(int x,int y){return x<y?x:y;}
int n,q,a[500050],d[1000010],c[1000010];
int mi[4000040],cnt[4000040],ad[4000040],pl[4000040],pr[4000040],pos[1000010];
inline void pushup(int k)
{
	mi[k]=qmin(mi[k<<1],mi[k<<1|1]);
	cnt[k]=(mi[k]==mi[k<<1]?cnt[k<<1]:0)+(mi[k]==mi[k<<1|1]?cnt[k<<1|1]:0);
	mi[k]+=ad[k];
}
void build(int k,int l,int r)
{
	pl[k]=l,pr[k]=r;
	if(l==r)
	{
		mi[k]=d[l],cnt[k]=c[l],pos[l]=k;
		return;
	}
	build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
	pushup(k);
}
void upd(int p,int w)
{
	int k=pos[p];
	cnt[k]=w;k>>=1;
	while(k)pushup(k),k>>=1;
}
void add(int l,int r,int w)
{
	if(l==r)
	{
		int k=pos[l];mi[k]+=w;k>>=1;
		while(k)pushup(k),k>>=1;
		return;
	}
	int k1=pos[l],k2=pos[r],k=k1;
//	printf("%d %d ",k1,k2);
	while(pr[k]<r)k>>=1;
//	printf("%d\n",k1,k2,k);
	mi[k1]+=w,mi[k2]+=w;
	while((k1>>1)!=k)
	{
		if(!(k1&1))ad[k1+1]+=w,mi[k1+1]+=w;
		k1>>=1,pushup(k1);
	}
	while((k2>>1)!=k)
	{
		if(k2&1)ad[k2-1]+=w,mi[k2-1]+=w;
		k2>>=1,pushup(k2);
	}
	while(k)pushup(k),k>>=1;
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read(),c[a[i]]=1;
	a[0]=1000001;
	for(int i=0;i<=n;++i)
	{
		if(a[i]<a[i+1])++d[a[i]+1],--d[a[i+1]+1];
		else ++d[a[i+1]+1],--d[a[i]+1];
	}
	for(int i=1;i<=1000001;++i)d[i]+=d[i-1];
//	for(int i=1;i<=100;++i)printf("%d ",d[i]);printf("\n");
	build(1,1,1000001);
	int x,y;
	for(int i=1;i<=q;++i)
	{
		x=read(),y=read();
		if(a[x-1]<a[x])add(a[x-1]+1,a[x],-1);
		else add(a[x]+1,a[x-1],-1);
		if(a[x]<a[x+1])add(a[x]+1,a[x+1],-1);
		else add(a[x+1]+1,a[x],-1);
		upd(a[x],0);
		a[x]=y;
		upd(a[x],1);
		if(a[x-1]<a[x])add(a[x-1]+1,a[x],1);
		else add(a[x]+1,a[x-1],1);
		if(a[x]<a[x+1])add(a[x]+1,a[x+1],1);
		else add(a[x+1]+1,a[x],1);
		print(cnt[1]),putc('\n');
	}
	fwrite(buff,1,T-buff,stdout);
	cerr<<clock()<<endl;
	return 0;
}