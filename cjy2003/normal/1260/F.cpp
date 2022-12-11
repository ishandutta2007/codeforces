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
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int ans;
namespace seg
{
	int ch[5000000][2],sump[5000000],sum[5000000],adp[5000000],ad[5000000],tot;
	void ins(int &k,int l,int r,int ll,int rr,int p,int w)
	{
		if(l>rr||r<ll)return;
		if(!k)k=++tot;
		if(l>=ll&&r<=rr)
		{
			ad[k]=w,adp[k]=p;
			sum[k]=1ll*w*(r-l+1)%mod,sump[k]=1ll*p*(r-l+1)%mod;
			return;
		}
		ins(ch[k][0],l,(l+r)>>1,ll,rr,p,w);
		ins(ch[k][1],((l+r)>>1)+1,r,ll,rr,p,w);
		sum[k]=pl(sum[ch[k][0]],sum[ch[k][1]]);
		sump[k]=pl(sump[ch[k][0]],sump[ch[k][1]]);
	}
	int merge(int x,int y,int l,int r,int d)
	{
		if(!x||!y)return x+y;
		ans=(ans+1ll*ad[x]*sump[y]+1ll*adp[x]*sum[y]-2ll*d*adp[x]%mod*sump[y]
			+1ll*ad[y]*sump[x]+1ll*adp[y]*sum[x]-2ll*d*adp[y]%mod*sump[x]
			-(1ll*ad[x]*adp[y]+1ll*ad[y]*adp[x]-2ll*d*adp[x]%mod*adp[y])%mod*(r-l+1))%mod;
		add(sum[x],sum[y]);
		add(sump[x],sump[y]);
		add(ad[x],ad[y]);
		add(adp[x],adp[y]);
		if(l==r)return x;
		ch[x][0]=merge(ch[x][0],ch[y][0],l,(l+r)>>1,d);
		ch[x][1]=merge(ch[x][1],ch[y][1],((l+r)>>1)+1,r,d);
		return x;
	}
}
int n,rt[100010],l[100010],r[100010],dep[100010];
vector<int>E[100010];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	int p=kpow(r[v]-l[v]+1,mod-2);
	seg::ins(rt[v],1,100000,l[v],r[v],p,1ll*p*dep[v]%mod);
	for(auto u:E[v])
	{
		if(u==fa)continue;
		dfs(u,v);
		rt[v]=seg::merge(rt[v],rt[u],1,100000,dep[v]);
		// printf("%d %d %d\n",v,u,ans);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)l[i]=read(),r[i]=read();
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		E[x].emplace_back(y);
		E[y].emplace_back(x);
	}
	dfs(1,0);
	if(ans<0)ans+=mod;
	for(int i=1;i<=n;++i)ans=1ll*ans*(r[i]-l[i]+1)%mod;
	printf("%d",ans);
	flush();
	return 0;
}