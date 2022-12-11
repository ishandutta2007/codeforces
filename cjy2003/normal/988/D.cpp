#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
map<long long,bool>mp;
int n;
int ans,a,b;
int main()
{
	n=read();
	while(n--)mp[read()]=1;
	for(auto p:mp)
		for(long long i=1;i<=2000000000;i<<=1)
			if(mp.count(p.first-i)&&mp.count(p.first+i))
			{
				printf("3\n%lld %lld %lld",p.first-i,p.first,p.first+i);
				return 0;
			}
			else if(mp.count(p.first-i))ans=2,a=p.first,b=p.first-i;
	if(!ans)printf("1\n%lld",mp.begin()->first);
	else printf("2\n%d %d",a,b);
	return 0;
}