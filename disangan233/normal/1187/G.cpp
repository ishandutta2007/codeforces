#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
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
};
using namespace fast_io;
const int N=1e7+5,inf=1e9;
int cnt=1,tot,n,s,t,m,p,a,b,x[N],y[N],h[N],l,r,q[N],vis[N],d[N],ans,maxflow;
struct did{int u,nxt,to,f,w;}e[N];
in void add(int a,int b,int c,int d)
{
	e[++cnt]={a,h[a],b,c,d},h[a]=cnt;
	e[++cnt]={b,h[b],a,0,-d},h[b]=cnt;
}
in int spfa()
{
	memset(vis,0,4*(t+1));memset(d,63,4*(t+1));
	int l=0,r=0;vis[q[++r]=s]=1,d[s]=0;
	while(l<r)
	{
		int u=q[++l];vis[u]=0;
		for(int i=h[u],v;v=e[i].to,i;i=e[i].nxt)
		if(e[i].f&&d[v]>d[u]+e[i].w)
		{
			d[v]=d[u]+e[i].w;
			if(!vis[v]) vis[q[++r]=v]=1;
		}
	}	
	return d[t]<inf;
}
int dfs(int u,int f)
{
	if(u==t) return f;vis[u]=1;int res=0;
	for(int i=h[u],v;v=e[i].to,i&&res<f;i=e[i].nxt)
	if(e[i].f&&!vis[v]&&d[v]==d[u]+e[i].w)
	{
		int t=dfs(v,min(f-res,e[i].f));
		res+=t;ans+=e[i].w*t;
		e[i].f-=t;e[i^1].f+=t;
	}
	if(!res) d[u]=inf;return vis[u]=0,res;
}
in void zkw() {while(spfa()) memset(vis,0,4*(t+1)),maxflow+=dfs(s,inf);}
in int f(int t,int x) {return t*n+x;}
int main()
{
	n=read(),m=read(),p=read(),a=read(),b=read();s=0,t=n*(2*p-1)+1; 
	for(int i=1,x;i<=p;i++) x=read(),add(s,f(0,x),1,0);
	for(int i=1;i<=m;i++) x[i]=read(),y[i]=read(); 
	for(int i=0;i<2*p;i++)
	{
		add(f(i,1),f(i+1,1),inf,0);
		for(int j=2;j<=n;j++) add(f(i,j),f(i+1,j),inf,a);
		for(int j=1;j<=m;j++) for(int k=1;k<=p;k++)
		{
			int coef=b*k*k-b*(k-1)*(k-1)+a;
			add(f(i,x[j]),f(i+1,y[j]),1,coef),add(f(i,y[j]),f(i+1,x[j]),1,coef);
		}
	}
	zkw();write(ans,'\n');
	return ot(),0;
}
//Author: disangan233