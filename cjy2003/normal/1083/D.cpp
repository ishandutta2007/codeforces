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
const int mod=1000000007;
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
int n,a[100010],d[100010];
int pre[100010],suf[100010],last[100010];
int ans;
inline int qsum(int l,int r){return 1ll*(l+r)*(r-l+1)/2%mod;}
struct ret
{
	int sumpre,sumsuf,sum,sumsuf1;
	friend ret operator + (ret a,ret b){return ret{pl(a.sumpre,b.sumpre),pl(a.sumsuf,b.sumsuf),pl(a.sum,b.sum),pl(a.sumsuf1,b.sumsuf1)};}
};
namespace seg
{
	#define ls k<<1,l,(l+r)>>1
	#define rs k<<1|1,((l+r)>>1)+1,r
	int sumpre[400010],sumsuf[400010],sum[400010],sumsuf1[400010];
	int tagpre[400010],tagsuf[400010];
	void pushpre(int k,int l,int r,int w)
	{
		sum[k]=1ll*w*sumsuf[k]%mod;
		sumpre[k]=1ll*w*(r-l+1)%mod;
		tagpre[k]=w;
	}
	void pushsuf(int k,int l,int r,int w)
	{
		sum[k]=1ll*w*sumpre[k]%mod;
		sumsuf[k]=1ll*w*(r-l+1)%mod;
		sumsuf1[k]=1ll*w*qsum(l-1,r-1)%mod;
		tagsuf[k]=w;
	}
	void pushdown(int k,int l,int r)
	{
		if(tagpre[k])
		{
			pushpre(ls,tagpre[k]);
			pushpre(rs,tagpre[k]);
			tagpre[k]=0;
		}
		if(tagsuf[k])
		{
			pushsuf(ls,tagsuf[k]);
			pushsuf(rs,tagsuf[k]);
			tagsuf[k]=0;
		}
	}
	void pushup(int k)
	{
		sumpre[k]=pl(sumpre[k<<1],sumpre[k<<1|1]);
		sumsuf[k]=pl(sumsuf[k<<1],sumsuf[k<<1|1]);
		sum[k]=pl(sum[k<<1],sum[k<<1|1]);
		sumsuf1[k]=pl(sumsuf1[k<<1],sumsuf1[k<<1|1]);
	}
	void updpre(int k,int l,int r,int ll,int rr,int w)
	{
		if(l>rr||r<ll)return;
		if(l>=ll&&r<=rr)return pushpre(k,l,r,w);
		pushdown(k,l,r);
		updpre(ls,ll,rr,w);
		updpre(rs,ll,rr,w);
		pushup(k);
	}
	void updsuf(int k,int l,int r,int ll,int rr,int w)
	{
		if(l>rr||r<ll)return;
		if(l>=ll&&r<=rr)return pushsuf(k,l,r,w);
		pushdown(k,l,r);
		updsuf(ls,ll,rr,w);
		updsuf(rs,ll,rr,w);
		pushup(k);
	}
	ret qry(int k,int l,int r,int ll,int rr)
	{
		if(l>=ll&&r<=rr)return ret{sumpre[k],sumsuf[k],sum[k],sumsuf1[k]};
		pushdown(k,l,r);
		if(ll>(l+r)>>1)return qry(rs,ll,rr);
		if(rr<=(l+r)>>1)return qry(ls,ll,rr);
		return qry(ls,ll,rr)+qry(rs,ll,rr);
	}
	#undef ls
	#undef rs
}
using namespace seg;
int stpre[100010],tppre,stsuf[100010],tpsuf;
int t[100010];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),d[i]=a[i];
	sort(d+1,d+1+n);
	for(int i=1;i<=n;++i)a[i]=lower_bound(d+1,d+1+n,a[i])-d;
	for(int i=1;i<=n;++i)
	{
		if(last[a[i]])pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	memset(last+1,0,n<<2);
	for(int i=n;i;--i)
	{
		if(last[a[i]])suf[i]=last[a[i]];
		else suf[i]=n+1;
		last[a[i]]=i;
	}
	for(int i=1,l=1;i<=n;++i)
	{
		while(tppre&&pre[i]>=pre[stpre[tppre]])--tppre;
		updpre(1,1,n,stpre[tppre]+1,i,pre[i]);
		stpre[++tppre]=i;
		while(tpsuf&&suf[i]<=suf[stsuf[tpsuf]])--tpsuf;
		updsuf(1,1,n,stsuf[tpsuf]+1,i,suf[i]);
		stsuf[++tpsuf]=i;
		++t[a[i]];
		while(t[a[i]]>1)--t[a[l]],++l;
		ret res=qry(1,1,n,l,i);
		// printf("%d %d %d %d %d %d\n",l,i,res.sum,res.sumpre,res.sumsuf,res.sumsuf1);
		ans=(ans+res.sumsuf1-1ll*(i+1)*qsum(l-1,i-1)-res.sum+1ll*res.sumpre*(i+1))%mod;
	}
	if(ans<0)ans+=mod;
	printf("%d",ans);
	flush();
	return 0;
}