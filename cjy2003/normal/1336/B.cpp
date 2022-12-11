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
	inline void print(int x)
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
int T,nr,ng,nb,r[100010],g[100010],b[100010],*x,*y,*z,nx,ny,nz;
long long ans;
int main()
{
	T=read();
	while(T--)
	{
		ans=3e18;
		nr=read(),ng=read(),nb=read();
		for(int i=1;i<=nr;++i)r[i]=read();sort(r+1,r+1+nr);
		for(int i=1;i<=ng;++i)g[i]=read();sort(g+1,g+1+ng);
		for(int i=1;i<=nb;++i)b[i]=read();sort(b+1,b+1+nb);
		x=r,y=g,z=b;nx=nr,ny=ng,nz=nb;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		x=r,y=b,z=g;nx=nr,ny=nb,nz=ng;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		x=g,y=r,z=b;nx=ng,ny=nr,nz=nb;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		x=g,y=b,z=r;nx=ng,ny=nb,nz=nr;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		x=b,y=r,z=g;nx=nb,ny=nr,nz=ng;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		x=b,y=g,z=r;nx=nb,ny=ng,nz=nr;
		for(int i=1,py=1,pz=1;i<=nx;++i)
		{
			while(py<ny&&y[py+1]<=x[i])++py;
			while(pz<=nz&&z[pz]<x[i])++pz;
			if(py<=ny&&pz<=nz&&y[py]<=x[i])ans=min(ans,1ll*(x[i]-y[py])*(x[i]-y[py])+1ll*(x[i]-z[pz])*(x[i]-z[pz])+1ll*(y[py]-z[pz])*(y[py]-z[pz]));
		}
		printf("%lld\n",ans);
	}
	flush();
	return 0;
}