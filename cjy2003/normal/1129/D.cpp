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
const int siz=300,mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int n,k,a[100010];
int last[100010],pre[100010];
int cur[100010],dp[100010],bl[100010];
int ad[400],bnum,st[400],ed[400];
vector<pair<int,int> >sum[400];
void rebuild(int x)
{
	sum[x].clear();
	for(int i=st[x];i<=ed[x];++i)sum[x].emplace_back(make_pair(cur[i],dp[i]));
	sort(sum[x].begin(),sum[x].end());
	for(int i=1;i<(int)sum[x].size();++i)add(sum[x][i].second,sum[x][i-1].second);
}
int query(int x)
{
	int p=lower_bound(sum[x].begin(),sum[x].end(),make_pair(k-ad[x],0x3f3f3f3f))-sum[x].begin()-1;
	if(p>=0)return sum[x][p].second;
	else return 0;
}
void add(int l,int r,int w)
{
//	printf("add:%d %d %d\n",l,r,w);
	int x=bl[l],y=bl[r];
	if(x==y)
	{
		for(int i=l;i<=r;++i)cur[i]+=w;
		rebuild(x);
	}
	else
	{
		for(int i=l;i<=ed[x];++i)cur[i]+=w;
		for(int i=st[y];i<=r;++i)cur[i]+=w;
		rebuild(x);rebuild(y);
		for(int i=x+1;i<y;++i)ad[i]+=w;
	}
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<=n;i+=siz)
	{
		++bnum;
		st[bnum]=i,ed[bnum]=i+siz>n?n:i+siz-1;
		for(int j=st[bnum];j<=ed[bnum];++j)bl[j]=bnum;
	}
	dp[0]=1;
	sum[1].emplace_back(make_pair(0,1));
	for(int i=1;i<=n;++i)
	{
		pre[i]=last[a[i]];
		if(pre[i])add(pre[pre[i]],pre[i]-1,-1);
		add(pre[i],i-1,1);
		last[a[i]]=i;
		for(int j=1;j<bl[i];++j)add(dp[i],query(j));
		for(int j=st[bl[i]];j<i;++j)if(cur[j]+ad[bl[i]]<=k)add(dp[i],dp[j]);
		if(i==ed[bl[i]])rebuild(bl[i]);
	}
	printf("%d\n",dp[n]);
	flush();
	return 0;
}