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
int n,m,a[50050];
int dp[50050],fr[50050],ls[50050],dp1[50050],pre[50050],suf[50050],l,r,sum;
void rr()
{
	++r;
	if(pre[r]>=l)sum+=r-pre[r];
	// printf("%d %d %d\n",l,r,sum);
}
void rl()
{
	if(pre[r]>=l)sum-=r-pre[r];
	--r;
	// printf("%d %d %d\n",l,r,sum);
}
void ll()
{
	--l;
	if(suf[l]<=r)sum+=suf[l]-l;
	// printf("%d %d %d\n",l,r,sum);
}
void lr()
{
	if(suf[l]<=r)sum-=suf[l]-l;
	++l;
	// printf("%d %d %d\n",l,r,sum);
}
void solve(int al,int ar,int bl,int br)
{
	// printf("%d %d %d %d\n",al,ar,bl,br);
	if(al>ar)return;
	if(bl==br)
	{
		while(r<al)rr();
		while(l>bl+1)ll();
		while(r>al)rl();
		while(l<bl+1)lr();
		for(int i=al;i<=ar;++i)
		{
			dp1[i]=dp[bl]+sum;
			rr();
		}
		return;
	}
	int mid=al+ar>>1;
	while(r<mid)rr();
	while(l>bl+1)ll();
	while(r>mid)rl();
	while(l<bl+1)lr();
	int pos=bl,mi=0x3f3f3f3f;
	// printf("%d %d %d\n",l,r,sum);
	for(int i=bl;i<=br&&i<mid;++i)
	{
		if(dp[i]+sum<mi)mi=dp[i]+sum,pos=i;
		lr();
	}
	dp1[mid]=mi;
	solve(al,mid-1,bl,pos);
	solve(mid+1,ar,pos,br);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
	{
		if(!fr[a[i]])ls[a[i]]=fr[a[i]]=i;
		else sum+=i-ls[a[i]],pre[i]=ls[a[i]],suf[ls[a[i]]]=i,ls[a[i]]=i;
		dp[i]=sum;
	}
	for(int i=1;i<=n;++i)if(!suf[i])suf[i]=n+1;
	// for(int i=1;i<=n;++i)printf("%d ",dp[i]);
	// printf("\n");
	for(int i=2;i<=m;++i)
	{
		sum=0,l=1,r=0;
		solve(i,n,i-1,n-1);
		memcpy(dp+1,dp1+1,n<<2);
		// for(int j=1;j<=n;++j)printf("%d ",dp[j]);
		// printf("\n");
	}
	printf("%d\n",dp[n]);
	flush();
	return 0;
}