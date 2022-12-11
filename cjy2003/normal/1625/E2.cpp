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
const int siz=500;
int n,q,d[300030],cnt[600060],cntl[300030],bl[300030],id[600060],idnum;
long long sumcntl[1000];
int ad[1000][1000],num[1000][1000],id1[300030];
vector<int>p[600060];
int ps[300030];
char s[300030];
bool vis[300030];
struct BIT
{
	int *s,len;
	void add(int p,int w)
	{
		while(p<=len)s[p]+=w,p+=p&-p;
	}
	int qry(int p)
	{
		int res=0;
		while(p)res+=s[p],p-=p&-p;
		return res;
	}
	int qry(int l,int r){return qry(r)-qry(l-1);}
}b[600060];
long long qsum(int l,int r)
{
	long long sum=0;
	int lb=bl[l],rb=bl[r];
	for(int i=l;i<=r&&bl[i]==lb;++i)if(!vis[i])sum+=cntl[i]+ad[id1[i]][bl[i]];
	for(int i=lb+1;i<rb;++i)sum+=sumcntl[i];
	if(lb!=rb)for(int i=(rb-1)*siz+1;i<=r;++i)if(!vis[i])sum+=cntl[i]+ad[id1[i]][bl[i]];
	return sum;
}
int main()
{
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		bl[i]=(i-1)/siz+1;
		if(s[i]=='(')d[i]=d[i-1]+1,++cnt[d[i-1]+n];
		else if(s[i]==')')
		{
			d[i]=d[i-1]-1;
			cnt[d[i-1]+n]=0;
			cntl[i]=cnt[d[i]+n];
			sumcntl[bl[i]]+=cntl[i];
			ps[i]=p[d[i]+n].size();
			p[d[i]+n].emplace_back(i);
		}
		else d[i]=d[i-1];
	}
	for(int i=-n;i<=n;++i)
	{
		if(p[i+n].size()>=siz)
		{
			id[i+n]=++idnum;
			for(auto x:p[i+n])++num[idnum][bl[x]],id1[x]=idnum;
		}
		if(p[i+n].size())
		{
			b[i+n].len=p[i+n].size();
			b[i+n].s=new int[p[i+n].size()+1];
			memset(b[i+n].s,0,(b[i+n].len+1)<<2);
		}
	}
	// for(int i=1;i<=n;++i)printf("%d ",cntl[i]);
	// printf("\n");
	// for(int i=1;i<=n;++i)printf("%lld ",sumcntl[i]);
	// printf("\n");
	while(q--)
	{
		int t,l,r;
		scanf("%d %d %d",&t,&l,&r);
		if(t==1)
		{
			vis[r]=1;
			b[d[r]+n].add(ps[r]+1,1);
			if(id1[r])--num[id1[r]][bl[r]];
			sumcntl[bl[r]]-=cntl[r]+ad[id1[r]][bl[r]];
			int pos=ps[r],ed=lower_bound(p[d[r]+n-1].begin(),p[d[r]+n-1].end(),r)-p[d[r]+n-1].begin();
			if(ed==(int)p[d[r]+n-1].size())ed=n+1;
			else ed=p[d[r]+n-1][ed];
			if(!id1[r])
			{
				for(int i=pos,x=p[d[r]+n][i];i<(int)p[d[r]+n].size()&&x<ed;++i,x=p[d[r]+n][i])
					if(!vis[x])--cntl[x],--sumcntl[bl[x]];
			}
			else
			{
				// printf("!!!\n");
				int lb=bl[r],rb=bl[ed-1];
				for(int i=pos,x=p[d[r]+n][i];i<(int)p[d[r]+n].size()&&x<ed&&bl[x]==lb;++i,x=p[d[r]+n][i])
					if(!vis[x])--cntl[x],--sumcntl[bl[x]];
				// printf("!!!%d %d\n",lb,rb);
				for(int i=lb+1;i<rb;++i)--ad[id1[r]][i],sumcntl[i]-=num[id1[r]][i];
				if(lb!=rb)
				{
					pos=lower_bound(p[d[r]+n].begin(),p[d[r]+n].end(),(rb-1)*siz+1)-p[d[r]+n].begin();
					for(int i=pos,x=p[d[r]+n][i];i<(int)p[d[r]+n].size()&&x<ed;++i,x=p[d[r]+n][i])
						if(!vis[x])--cntl[x],--sumcntl[bl[x]];
				}
			}
		}
		else
		{
			long long ans=qsum(l,r);
			// printf("ans %lld ",ans);
			int p1=lower_bound(p[d[r]+n].begin(),p[d[r]+n].end(),l)-p[d[r]+n].begin()+1,p2=lower_bound(p[d[r]+n].begin(),p[d[r]+n].end(),r)-p[d[r]+n].begin()+1;
			int cnt0=p2-p1+1-b[d[r]+n].qry(p1+1,p2);
			// printf("%d ",cnt0);
			ans-=1ll*cnt0*(cntl[r]+ad[id1[r]][bl[r]]-cnt0);
			printf("%lld\n",ans);
		}
	}
	flush();
	return 0;
}