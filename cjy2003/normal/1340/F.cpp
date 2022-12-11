#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
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
void yes(){putc('Y'),putc('e'),putc('s'),putc('\n');}
void no(){putc('N'),putc('o'),putc('\n');}
mt19937 myrand(time(0)+(unsigned long long)(new char));
const int siz=300,mod=998244353;
int sed1,sed2,po1[310],po2[310];
int n,k,a[100010],q,bl[100010],bcnt;
struct block
{
	int st,ed,len,lenp,phas1[310],shas1[310],phas2[310],shas2[310];
	bool ok;
	void build()
	{
		// printf("build %d %d:\n",st,ed);
		static int stk[310],tp;tp=0;
		for(int i=st;i<=ed;++i)
		{
			if(tp&&stk[tp]>0&&stk[tp]+a[i]==0)--tp;
			else stk[++tp]=a[i];
		}
		ok=1;
		for(int i=1;i<tp;++i)if(stk[i]>0&&stk[i+1]<0)ok=0;
		if(ok)
		{
			len=tp;lenp=0;
			for(int i=1;i<=len;++i)if(stk[i]<0)lenp=i;
			for(int i=1;i<=len;++i)phas1[i]=(1ll*phas1[i-1]*sed1+stk[i])%mod,phas2[i]=(1ll*phas2[i-1]*sed2+stk[i])%mod;
			shas1[len+1]=shas2[len+1]=0;
			for(int i=len;i;--i)shas1[i]=(1ll*shas1[i+1]*sed1+stk[i])%mod,shas2[i]=(1ll*shas2[i+1]*sed2+stk[i])%mod;
			// for(int i=1;i<=len;++i)printf("%d ",phas1[i]);printf("\n");
			// for(int i=1;i<=len;++i)printf("%d ",shas1[i]);printf("\n");
		}
	//	printf("%d %d:%d %d\n",st,ed,ok,lenp);
	//	for(int i=1;i<=tp;++i)printf("%d ",stk[i]);printf("\n");
	}
	pair<int,int>qpre(int l,int r)
	{
		return make_pair((phas1[r]-1ll*phas1[l-1]*po1[r-l+1])%mod,(phas2[r]-1ll*phas2[l-1]*po2[r-l+1])%mod);
	}
	pair<int,int>qsuf(int l,int r)
	{
		return make_pair((shas1[l]-1ll*shas1[r+1]*po1[r-l+1])%mod,(shas2[l]-1ll*shas2[r+1]*po2[r-l+1])%mod);
	}
}b[400],l,r;
block *p[400];
int cnt,cl[400],cr[400],ans;
bool check(pair<int,int>a,pair<int,int>b)
{
	// printf("check %d %d %d %d\n",a.first,b.first,a.second,b.second);
	return (a.first+b.first)%mod==0&&(a.second+b.second)%mod==0;
}
bool ins(block &x)
{
	if(!x.ok)return 0;
	// printf("ins %d %d:\n",x.st,x.ed);
	// for(int i=1;i<=cnt;++i)printf("%d %d  ",p[i]->st+cl[i]-1,p[i]->st+cr[i]-1);
	// printf("\n");
	int nl=1,nr=x.len;
	while(nl<=x.lenp)
	{
		if(!cnt)return /*printf("nothing\n"),*/0;
		int clen=min(x.lenp-nl+1,cr[cnt]-cl[cnt]+1);
		if(!check(x.qpre(nl,nl+clen-1),p[cnt]->qsuf(cr[cnt]-clen+1,cr[cnt])))return /*printf("failcheck %d %d %d %d\n",x.st+nl-1,x.st+nl+clen-2,p[cnt]->st+cr[cnt]-clen,p[cnt]->st+cr[cnt]-1),*/0;
		nl+=clen,cr[cnt]-=clen;
		if(cl[cnt]>cr[cnt])--cnt;
	}
	if(nl<=nr)
	{
		++cnt;
		p[cnt]=&x;
		cl[cnt]=nl,cr[cnt]=nr;
	}
	return 1;
}
bool query(int x,int y)
{
	if(bl[x]==bl[y])
	{
		l.st=x,l.ed=y;
		l.build();
		return l.ok&&!l.len;
	}
	else 
	{
		l.st=x,l.ed=b[bl[x]].ed,l.build();
		r.st=b[bl[y]].st,r.ed=y,r.build();
		cnt=0;
		if(!ins(l))return /*printf("wa on %d %d\n",l.st,l.ed),*/0;
		for(int i=bl[x]+1;i<bl[y];++i)if(!ins(b[i]))return /*printf("wa on %d %d\n",b[i].st,b[i].ed),*/0;
		if(!ins(r))return /*printf("wa on %d %d\n",r.st,r.ed),*/0;
		// printf("remain:");
		// for(int i=1;i<=cnt;++i)printf("%d %d  ",p[i]->st+cl[i]-1,p[i]->st+cr[i]-1);
		// printf("\n");
		return !cnt;
	}
}
int main()
{
	sed1=myrand()%(mod-200000)+200000;
	sed2=myrand()%(mod-200000)+200000;
	po1[0]=po2[0]=1;
	for(int i=1;i<=siz;++i)
	{
		po1[i]=1ll*po1[i-1]*sed1%mod;
		po2[i]=1ll*po2[i-1]*sed2%mod;
	}
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;i+=siz)
	{
		++bcnt;
		b[bcnt].st=i,b[bcnt].ed=i+siz>n?n:i+siz-1;
		for(int j=b[bcnt].st;j<=b[bcnt].ed;++j)bl[j]=bcnt;
		b[bcnt].build();
	}
	q=read();
	int c,x,y;
	while(q--)
	{
		c=read(),x=read(),y=read();
		if(c==1)
		{
			a[x]=y;
			b[bl[x]].build();
		}
		else if(query(x,y))yes();
		else no();
	}
	flush();
	return 0;
}