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
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
struct edge
{
	int nxt,to;
}e[620];
int n,head[310],num,dep[310];
void add_edge(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int cnt[310];
//<rrr
int dp[310][2][310],tmp[2][310];//dp[0][d]:d;dp[1][d]:c-d
//>
void dfs(int v,int fa,int c)
{
	memset(dp[v],0,sizeof(dp[v]));
	dp[v][0][0]=1;
	dp[v][1][0]=1;
	dep[v]=0;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs(u,v,c);
		memset(tmp,0,sizeof(tmp));
		for(int j=0;j<=dep[v];++j)
			for(int k=0;k<=dep[u];++k)
			{
				add(tmp[0][max(j,k+1)],1ll*dp[v][0][j]*dp[u][0][k]%mod);
				if(j+k+1<=c)add(tmp[1][k+1],1ll*dp[v][0][j]*dp[u][1][k]%mod),add(tmp[1][j],1ll*dp[v][1][j]*dp[u][0][k]%mod);
				else add(tmp[0][j],1ll*dp[v][0][j]*dp[u][1][k]%mod),add(tmp[0][k+1],1ll*dp[v][1][j]*dp[u][0][k]%mod);;
				add(tmp[1][min(j,k+1)],1ll*dp[v][1][j]*dp[u][1][k]%mod);
			}
		memcpy(dp[v],tmp,sizeof(tmp));
		dep[v]=max(dep[v],dep[u]+1);
	}
	// printf("%d:\n",v);
	// for(int i=0;i<=dep[v];++i)printf("%d ",dp[v][0][i]);
	// printf("\n");
	// for(int i=0;i<=dep[v];++i)printf("%d ",dp[v][1][i]);
	// printf("\n");
}
int main()
{
	n=read();
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		add_edge(x,y),add_edge(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		// printf("cnt=%d:\n",i);
		dfs(1,0,i);
		for(int j=0;j<=dep[1];++j)add(cnt[i],dp[1][1][j]);
	}
	cnt[n+1]=kpow(2,n);
	// for(int i=0;i<=n+1;++i)printf("%d ",cnt[i]);
	// printf("\n");
	for(int i=0;i<=n;++i)cnt[i]=pl(cnt[i+1],mod-cnt[i]);
	// for(int i=0;i<=n;++i)printf("%d ",cnt[i]);
	// printf("\n");
	int ans=mod-1;
	for(int i=1;i<=n;++i)ans=(ans+1ll*cnt[i]*i)%mod;
	ans=1ll*ans*kpow(kpow(2,mod-2),n)%mod;
	printf("%d",ans);
	flush();
	return 0;
}