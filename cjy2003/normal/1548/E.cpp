#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
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
int n,m,x,a[200020],b[200020],c[200020],d[200020],p[200020],q[200020];
void work(int f[],int mi[],int len)
{
	static int posup[200020],valup[200020],tpup,posdn[200020],valdn[200020],tpdn;
	for(int i=1;i<=len;++i)mi[i]=x+1;
	tpup=tpdn=0;posup[0]=posdn[0]=0;
	for(int i=1;i<=len;++i)
	{
		while(tpup&&f[i]<valup[tpup])--tpup;
		++tpup,posup[tpup]=i,valup[tpup]=f[i];
		while(tpdn&&f[i]>=valdn[tpdn])--tpdn;
		++tpdn,posdn[tpdn]=i,valdn[tpdn]=f[i];
		if(tpup!=1)mi[i]=min(mi[i],valdn[lower_bound(posdn+1,posdn+1+tpdn,posup[tpup-1]+1)-posdn]);
	}
	tpup=0,tpdn=0;posup[0]=posdn[0]=len+1;
	for(int i=len;i;--i)
	{
		while(tpup&&f[i]<=valup[tpup])--tpup;
		++tpup,posup[tpup]=i,valup[tpup]=f[i];
		while(tpdn&&f[i]>=valdn[tpdn])--tpdn;
		++tpdn,posdn[tpdn]=i,valdn[tpdn]=f[i];
		if(tpup!=1)mi[i]=min(mi[i],valdn[lower_bound(posdn+1,posdn+1+tpdn,posup[tpup-1]-1,greater<int>())-posdn]);
	}
}
namespace BIT
{
	int sum[200020];
	void add(int p){while(p<=200000)++sum[p],p+=p&-p;}
	int qry(int p)
	{
		if(p<=0)return 0;
		int res=0;
		while(p)res+=sum[p],p-=p&-p;
		return res;
	}
}
int main()
{
	n=read(),m=read(),x=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	work(a,c,n);
	work(b,d,m);
//	for(int i=1;i<=n;++i)printf("%d ",c[i]);printf("\n");
//	for(int i=1;i<=m;++i)printf("%d ",d[i]);printf("\n");
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=m;++i)q[i]=i;
	sort(q+1,q+1+m,[&](int x,int y){return d[x]>d[y];});
	long long ans=0;
	for(int i=1,last=1;i<=n;++i)
	{
		while(last<=m&&d[q[last]]>x-a[p[i]])BIT::add(b[q[last]]),++last;
		ans+=BIT::qry(x-a[p[i]])-BIT::qry(x-c[p[i]]);
	}
	printf("%lld\n",ans);
	flush();
	return 0;
}