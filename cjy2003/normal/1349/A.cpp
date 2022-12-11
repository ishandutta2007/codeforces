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
int n,p[200020],pnum,pos[200020],mi[200020],mi2[200020],hv[200020];
bool vis[200020];
long long ans;
int main()
{
	vis[1]=1;
	for(int i=2;i<=200000;++i)
	{
		if(!vis[i])p[++pnum]=i,pos[i]=pnum,mi[pnum]=mi2[pnum]=0x3f3f3f3f;
		for(int j=1;j<=pnum&&p[j]*i<=200000;++j)
		{
			vis[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	n=read();
	for(int i=1,x,cnt;i<=n;++i)
	{
		x=read();
		for(int j=1;p[j]<=500;++j)
			if(x%p[j]==0)
			{
				cnt=0;++hv[j];
				while(x%p[j]==0)x/=p[j],++cnt;
				if(cnt<mi[j])mi2[j]=mi[j],mi[j]=cnt;
				else if(cnt<mi2[j])mi2[j]=cnt;
			}
		if(x>1)
		{
			if(1<mi[pos[x]])mi2[pos[x]]=mi[pos[x]],mi[pos[x]]=1;
			else if(1<mi2[pos[x]])mi2[pos[x]]=1;
			++hv[pos[x]];
		}
	}
	ans=1;
	for(int i=1;i<=pnum;++i)
	{
		if(hv[i]<=n-2)continue;
		if(hv[i]==n-1)for(int j=1;j<=mi[i];++j)ans*=p[i];
		else for(int j=1;j<=mi2[i];++j)ans*=p[i];
	}
	printf("%lld",ans);
	return 0;
}