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
int n,q,d[300030],cnt[600060],cntl[300030];
long long sumcntl[300030];
vector<int>p[600060];
char s[300030];
int main()
{
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')d[i]=d[i-1]+1,++cnt[d[i-1]+n];
		else if(s[i]==')')
		{
			d[i]=d[i-1]-1;
			cnt[d[i-1]+n]=0;
			cntl[i]=cnt[d[i]+n];
			p[d[i]+n].emplace_back(i);
		}
		else d[i]=d[i-1];
		sumcntl[i]=sumcntl[i-1]+cntl[i];
	}
	// for(int i=1;i<=n;++i)printf("%d ",cntl[i]);
	// printf("\n");
	// for(int i=1;i<=n;++i)printf("%lld ",sumcntl[i]);
	// printf("\n");
	while(q--)
	{
		int t,l,r;
		scanf("%d %d %d",&t,&l,&r);
		long long ans=sumcntl[r]-sumcntl[l-1];
		int cnt0=lower_bound(p[d[r]+n].begin(),p[d[r]+n].end(),r)-lower_bound(p[d[r]+n].begin(),p[d[r]+n].end(),l)+1;
		// printf("%d ",cnt0);
		ans-=1ll*cnt0*(cntl[r]-cnt0);
		printf("%lld\n",ans);
	}
	flush();
	return 0;
}