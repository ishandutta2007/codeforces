#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
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
struct edge
{
	int nxt,to;
}e[200020];
int n,m,n1,n2,n3,head[5050],num;
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
int type[5050],rt,cnt1[5050],cnt2[5050],tot,p[5050],ans[5050];
bitset<5050>ok[5050];
void dfs(int v)
{
	if(type[v]==1)++cnt1[rt];
	else ++cnt2[rt];
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(type[u]==type[v])
		{
			printf("NO");
			exit(0);
		}
		if(type[u])continue;
		type[u]=3-type[v];
		dfs(u);
	}
}
void dfs1(int v,int s)
{
	ans[v]=s;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(ans[u])continue;
		dfs1(u,3-s);
	}
}
void getans(int i,int j)
{
	if(!i)return;
	int x=p[i];
	if(j>=cnt1[x]&&ok[i-1][j-cnt1[x]])
	{
		dfs1(x,2);
		getans(i-1,j-cnt1[x]);
		return;
	}
	if(j>=cnt2[x]&&ok[i-1][j-cnt2[x]])
	{
		dfs1(x,1);
		getans(i-1,j-cnt2[x]);
		return;
	}
}
int main()
{
	n=read(),m=read();
	n1=read(),n2=read(),n3=read();
	for(int i=1,x,y;i<=m;++i)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	ok[0][0]=1;
	for(int i=1;i<=n;++i)
		if(!type[i])
		{
			rt=i,type[i]=1,dfs(i);
			p[++tot]=i;
			ok[tot]=(ok[tot-1]<<cnt1[i])|(ok[tot-1]<<cnt2[i]);
		}
	if(!ok[tot][n2])return printf("NO"),0;
	printf("YES\n");
	getans(tot,n2);
	for(int i=1;i<=n;++i)
	{
		if(ans[i]==1)
		{
			if(n1)--n1;
			else ans[i]=3;
		}
		printf("%d",ans[i]);
	}
	flush();
	return 0;
}