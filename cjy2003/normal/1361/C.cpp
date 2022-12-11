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
int n,a[500050][2],head[1048576],num,d[1048576];
struct edge
{
	int nxt,to;
}e[1000010];
void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;++d[to];}
bool vis[1048576];
bool bfs(int s)
{
	static int q[500050],h,t;
	h=0,t=1,q[t]=s,vis[s]=1;
	int sum=0;
	while(h<t)
	{
		int x=q[++h];
		for(int i=head[x],y;i;i=e[i].nxt)
		{
			y=e[i].to;++sum;
			if(vis[y])continue;
			vis[y]=1,q[++t]=y;
		}
	}
	for(int i=1;i<=t;++i)vis[q[i]]=0;
	return sum/2==n;
}
bool check(int w)
{
	memset(d,0,4<<w);
	memset(head,0,4<<w);
	num=0;
	int lim=(1<<w)-1;
	for(int i=1;i<=n;++i)
	{
		add(a[i][0]&lim,a[i][1]&lim);
		add(a[i][1]&lim,a[i][0]&lim);
	}
	for(int i=0;i<=lim;++i)if(d[i]&1)return 0;
	return bfs(a[1][0]&lim);
}
int stk[500050][2],tp;
void dfs(int v,int fb)
{
	for(int &i=head[v];i;i=e[i].nxt)
		if(!vis[(i+1)/2])
		{
			vis[(i+1)/2]=1;
			dfs(e[i].to,(i+1)/2);
		}
	++tp;
	stk[tp][0]=v,stk[tp][1]=fb;
}
void getans(int w)
{	
	memset(d,0,4<<w);
	memset(head,0,4<<w);
	num=0;
	int lim=(1<<w)-1;
	for(int i=1;i<=n;++i)
	{
		add(a[i][0]&lim,a[i][1]&lim);
		add(a[i][1]&lim,a[i][0]&lim);
	}
	tp=0;
	dfs(a[1][0]&lim,0);
	print(w),putc('\n');
	for(int i=tp-1;i;--i)
	{
		int x=stk[i][1]*2-1,y=stk[i][1]*2;
		if((a[stk[i][1]][0]&lim)!=stk[i+1][0])swap(x,y);
		print(x),putc(' ');
		print(y),putc(' ');
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i][0]=read(),a[i][1]=read();
	int l=0,r=20,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	getans(l);
	flush();
	return 0;
}