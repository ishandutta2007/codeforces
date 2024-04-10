#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
struct spider
{
	int a,id;
}a[300030];
int n,k,mx[10000000],mxpos[10000000],ch[10000000][2],dp[300030],fr[300030],tot=1;
void ins(int x,int w,int id)
{
	int u=1;
	if(w>mx[u])mx[u]=w,mxpos[u]=id;
	for(int i=29;~i;--i)
	{
		int c=x>>i&1;
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
		if(w>mx[u])mx[u]=w,mxpos[u]=id;
	}
}
pair<int,int>query(int x)
{
	int u=1,sum=0,res=0,pos=0;
	bool flag=0;
	for(int i=29;~i;--i)
	{
		if(!flag)
		{
			if(!(x>>i&1))u=ch[u][0];
			else if(sum+(1<<i)>=k)
			{
				if(ch[u][0]&&mx[ch[u][0]]>res)res=mx[ch[u][0]],pos=mxpos[ch[u][0]];
				u=ch[u][1];
			}
			else u=ch[u][0],flag=1,sum+=1<<i;
		}
		else
		{
			int c=x>>i&1;
			if(sum+(1<<i)>=k)
			{
				if(ch[u][c^1]&&mx[ch[u][c^1]]>res)res=mx[ch[u][c^1]],pos=mxpos[ch[u][c^1]];
				u=ch[u][c];
			}
			else u=ch[u][c^1],sum+=1<<i;
		}
		// printf("%d %d\n",i,sum);
	}
	return make_pair(res,pos);
}
int main()
{
	n=read(),k=read();
	if(k==0)
	{
		print(n),putc('\n');
		for(int i=1;i<=n;++i)print(i),putc(' ');
		flush();
		return 0;
	}
	for(int i=1;i<=n;++i)a[i].a=read(),a[i].id=i;
	sort(a+1,a+1+n,[&](spider x,spider y){return x.a<y.a;});
	for(int i=1;i<=n;++i)
	{
		pair<int,int>s=query(a[i].a);
		dp[i]=s.first+1;
		fr[i]=s.second;
		ins(a[i].a,dp[i],i);
	}
	int ans=0,x=0;
	for(int i=1;i<=n;++i)if(dp[i]>ans)ans=dp[i],x=i;
	if(ans==1)
	{
		print(-1),putc('\n');
	}
	else
	{
		print(ans),putc('\n');
		while(x)print(a[x].id),x=fr[x],putc(' ');
		putc('\n');
	}
	flush();
	return 0;
}