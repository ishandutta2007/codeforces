#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
const int N=3e2+5,M=2e6+5;
int n,m,k,a[N][N],id[N][N],ans[M],fa[M<<1],tot,cnt;
struct did{int u,v,c,b;}q[M]; 
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
in void merge(int u,int v) {u=find(u),v=find(v);if(u^v)fa[u]=v,tot--;}
in void check(int u,int v)
{
	if(a[u][v]==a[u-1][v]) merge(id[u][v],id[u-1][v]);
	if(a[u][v]==a[u+1][v]) merge(id[u][v],id[u+1][v]);
	if(a[u][v]==a[u][v-1]) merge(id[u][v],id[u][v-1]);
	if(a[u][v]==a[u][v+1]) merge(id[u][v],id[u][v+1]);
}
in void solve1()
{
	for(int i=1;i<=k;i++) if(q[i].b^q[i].c)
	{
		int u=q[i].u,v=q[i].v;tot=1;
		a[u][v]=q[i].c,id[u][v]=++cnt,fa[cnt]=cnt;
		check(u,v);ans[i]+=tot;
	}
}
in void solve2()
{
	for(int i=k;i;i--) if(q[i].b^q[i].c)
	{
		int u=q[i].u,v=q[i].v;tot=1;
		a[u][v]=q[i].b,id[u][v]=++cnt,fa[cnt]=cnt;
		check(u,v);ans[i]-=tot;
	}
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++) q[i]={read(),read(),read()},q[i].b=a[q[i].u][q[i].v],a[q[i].u][q[i].v]=q[i].c;
	ans[0]=1;cnt=0;memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=0;
	solve1();memset(fa,0,sizeof(fa));cnt=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) id[i][j]=++cnt,fa[cnt]=cnt;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) check(i,j);
	solve2();for(int i=1;i<=k;i++) ans[i]+=ans[i-1],write(ans[i],'\n');
	return ot(),0; 
}
//Author: disangan233