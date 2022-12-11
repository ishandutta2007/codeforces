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
struct stone
{
	int p,w;
	friend bool operator < (stone a,stone b){return a.p<b.p;}
}a[30];
int n,m,l,k,lim,c[10];
inline void upmin(long long &x,long long y){x>y?x=y:0;}
const long long inf=0x3f3f3f3f3f3f3f3fll;
struct matrix
{
	long long a[128][128];
	friend matrix operator * (matrix a,matrix b)
	{
		static matrix c;
		for(int i=0;i<lim;++i)
			for(int j=0;j<lim;++j)
			{
				c.a[i][j]=inf;
				for(int k=0;k<lim;++k)
					upmin(c.a[i][j],a.a[i][k]+b.a[k][j]);
			}
		return c;
	}
}t[30];
struct data
{
	long long a[128];
	friend data operator * (data a,matrix b)
	{
		static data c;
		for(int i=0;i<lim;++i)
		{
			c.a[i]=inf;
			for(int j=0;j<lim;++j)upmin(c.a[i],a.a[j]+b.a[j][i]);
		}
		return c;
	}
}s;
void trans(int d)
{
	for(int i=0;i<=26;++i)if(d>>i&1)s=s*t[i];
}
int main()
{
	n=read(),m=read(),l=read(),k=read();
	for(int i=1;i<=m;++i)c[i]=read();
	for(int i=1;i<=k;++i)a[i].p=read(),a[i].w=read();
	sort(a+1,a+1+k);
	lim=1<<(m-1);
	for(int i=0;i<lim;++i)
		for(int j=0;j<lim;++j)
			t[0].a[i][j]=inf;
	for(int i=0;i<lim;++i)
	{
		if(__builtin_popcount(i)==n)t[0].a[i][i>>1]=0;
		else if(__builtin_popcount(i)==n-1)
		{
			for(int j=1;j<=m;++j)
			{
				int x=i^(1<<(j-1));
				if(__builtin_popcount(x)==n)t[0].a[i][x>>1]=c[j];
			}
		}
	}
	for(int i=1;i<=26;++i)t[i]=t[i-1]*t[i-1];
	for(int i=0;i<lim;++i)s.a[i]=inf;
	s.a[(1<<(n-1))-1]=0;
	int last=1;
	for(int i=1;i<=k&&a[i].p<=l-n;++i)
	{
		trans(a[i].p-last);
		last=a[i].p;
		for(int j=0;j<lim;++j)if(__builtin_popcount(j)==n-1)s.a[j]+=a[i].w;
	}
	trans(l-n+1-last);
	long long ans=s.a[(1<<(n-1))-1];
	for(int i=1;i<=k;++i)if(a[i].p>l-n)ans+=a[i].w;
	printf("%lld",ans);
	flush();
	return 0;
}