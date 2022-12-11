#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cassert>
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
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
	char buff[N],*T=buff;
	#define putc(ch) T==buff+N?fwrite(buff,1,N,stdout),T=buff:0,*T++=ch
	inline void print(int x)
	{
		if(!x){putc(48);return;}
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}using namespace io;
struct bian
{
	int nxt,to;
}bi[600060];
int n,head[300030],num,q;
int dep[300030],siz[300030],f[300030],zson[300030],id[300030],tp[300030],idnum;
char s[300030],a[600060];
int sa[600060],rk[600060],t[600060],st[20][600060],lg[600060];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void dfs1(int v,int fa)
{
	siz[v]=1,f[v]=fa,dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);siz[v]+=siz[u];
		if(siz[u]>siz[zson[v]])zson[v]=u;
	}
}
void dfs2(int v,int topp)
{
	id[v]=++idnum,tp[v]=topp,a[idnum]=s[v];
	if(zson[v])dfs2(zson[v],topp);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v]||u==zson[v])continue;
		dfs2(u,u);
	}
}
int xx[600060],yy[600060];
void getsa(int n)
{
	int *x=xx,*y=yy,m=200;
	for(int i=1;i<=n;++i)++t[x[i]=a[i]];
	for(int i=2;i<=m;++i)t[i]+=t[i-1];
	for(int i=n;i;--i)sa[t[x[i]]--]=i;
	memset(t+1,0,m<<2);
	for(int len=1;;len<<=1)
	{
		int cnt=0;
		for(int i=n-len+1;i<=n;++i)y[++cnt]=i;
		for(int i=1;i<=n;++i)if(sa[i]>len)y[++cnt]=sa[i]-len;
		for(int i=1;i<=n;++i)++t[x[i]];
		for(int i=2;i<=m;++i)t[i]+=t[i-1];
		for(int i=n;i;--i)sa[t[x[y[i]]]--]=y[i];
	//	for(int i=1;i<=n;++i)printf("%d ",x[i]);printf("\n");
		memset(t+1,0,m<<2);
		swap(x,y);
		x[sa[1]]=1;m=1;
		for(int i=2;i<=n;++i)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?m:++m;
		if(m==n)break;
	}
	for(int i=1;i<=n;++i)rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;++i)
	{
		if(rk[i]==1)continue;
		if(k)--k;
		while(a[i+k]==a[sa[rk[i]-1]+k])++k;
		st[0][rk[i]]=k;
	}
	for(int i=1;i<=19;++i)
		for(int j=1;j<=n-(1<<i)+1;++j)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
}
inline int qlcp(int x,int y)
{
	if(x==y)return 2*n-x+1;
	x=rk[x],y=rk[y];
	if(x>y)swap(x,y);++x;
	int len=lg[y-x+1];
	return min(st[len][x],st[len][y-(1<<len)+1]);
}
void get(int x,int y,int p[][2],int &cnt)
{
	static int p1[1010][2],p2[1010][2],cp1,cp2;cp1=0,cp2=0;
//	printf("%d %d:\n",x,y);
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]>dep[tp[y]])p1[++cp1][0]=2*n+1-id[x],p1[cp1][1]=id[x]-id[tp[x]]+1,x=f[tp[x]];
		else p2[++cp2][0]=id[tp[y]],p2[cp2][1]=id[y]-id[tp[y]]+1,y=f[tp[y]];
	}
	if(dep[x]<dep[y])p1[++cp1][0]=id[x],p1[cp1][1]=id[y]-id[x]+1;
	else p1[++cp1][0]=2*n+1-id[x],p1[cp1][1]=id[x]-id[y]+1;
	cnt=0;
	for(int i=1;i<=cp1;++i)p[++cnt][0]=p1[i][0],p[cnt][1]=p1[i][1];
	for(int i=cp2;i;--i)p[++cnt][0]=p2[i][0],p[cnt][1]=p2[i][1];
//	for(int i=1;i<=cnt;++i)printf("%d %d\n",p[i][0],p[i][1]);
}
int work(int a,int b,int c,int d)
{
	static int p[1010][2],q[1010][2],cp,cq,ans,t1,t2,p1,p2;
	get(a,b,p,cp),get(c,d,q,cq);ans=0;t1=t2=1;p1=p2=0;
	while(t1<=cp&&t2<=cq)
	{
		int now=min(qlcp(p[t1][0]+p1,q[t2][0]+p2),min(p[t1][1]-p1,q[t2][1]-p2));
		ans+=now;
		if(now<p[t1][1]-p1&&now<q[t2][1]-p2)break;
		p1+=now,p2+=now;
		if(p1==p[t1][1])++t1,p1=0;
		if(p2==q[t2][1])++t2,p2=0;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int x,y;
	for(int i=1;i<n;++i)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs1(1,0);dfs2(1,1);
//	for(int i=1;i<=n;++i)printf("%d ",id[i]);printf("\n");
	for(int i=1;i<=n;++i)a[2*n+1-i]=a[i];
	getsa(2*n);
/*	while(1)
	{
		x=read(),y=read();
		printf("%d\n",qlcp(x,y));
	}*/
	int a,b,c,d,l,r,mid;
	q=read();
	while(q--)
	{
		a=read(),b=read(),c=read(),d=read();
		print(work(a,b,c,d));putc('\n');
	}
	fwrite(buff,1,T-buff,stdout);
	return 0;
}