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
const int N=2e5+5,p=1e9+7;
int n,T,cnt,ans=1,mn,rt,tot,siz[N],h[N],vis[N],nxt[N<<1],to[N<<1],c[N<<1],w[N<<1];
in void Add(int u,int v,int wi,int ci) {nxt[++cnt]=h[u],to[cnt]=v,w[cnt]=wi,c[cnt]=ci,h[u]=cnt;}
in void add(int u,int v,int w,int c) {Add(u,v,w,c),Add(v,u,w,c);}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
struct bit
{
	int s[N<<2],m[N<<2],t[N<<2];
	in void mul(int x,int y)
	{
		x+=n*2;
		while(x<=n*4)
		{
			if(m[x]^T) s[x]=0,t[x]=1;
			s[x]++,t[x]=1ll*t[x]*y%p,m[x]=T,x+=x&-x;
		}
	} 
	in void ask(int x,int &y,int &z)
	{
		y=1,z=0,x+=n*2;
		while(x)
		{
			if(m[x]==T) y=1ll*y*t[x]%p,z+=s[x];
			x-=x&-x;
		}
	}
}t1,t2;
void findrt(int u,int fa)
{
	siz[u]=1;int s=-1;
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(v^fa&&!vis[v]) findrt(v,u),siz[u]+=siz[v],s=max(s,siz[v]);
	s=max(s,tot-siz[u]);if(mn>s) mn=s,rt=u;
}
int m;struct did{int a,b,w;}q[N];
void dfs(int u,int fa,int a,int b,int wi)
{
	q[++m]={2*a-b,2*b-a,wi};
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(v^fa&&!vis[v]) dfs(v,u,a+(c[i]^1),b+c[i],1ll*wi*w[i]%p); 
}
in void ask(int u)
{
	T++,t1.mul(0,1),t2.mul(0,1);
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(!vis[v])
	{
		m=0;dfs(v,0,c[i]^1,c[i],w[i]);
		for(int j=1;j<=m;j++)
		{
			int w1,w2;
			t1.ask(q[j].a,w1,w2);ans=1ll*ans*w1%p*qpow(q[j].w,w2)%p;
			t2.ask(-q[j].b-1,w1,w2);ans=1ll*ans*qpow(1ll*w1*qpow(q[j].w,w2)%p,p-2)%p;
		}
		for(int j=1;j<=m;j++) t1.mul(-q[j].a,q[j].w),t2.mul(q[j].b,q[j].w);
	}
}
void solve(int u)
{
	vis[u]=1,ask(u);int sum=tot;
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(!vis[v])
	{
		tot=siz[v];if(siz[v]>siz[u]) tot=sum-siz[u];mn=1e9;
		findrt(v,0),solve(rt);
	}
}
int main()
{
	n=read();for(int i=1,x,y,z,c;i<n;i++) x=read(),y=read(),z=read(),add(x,y,z,read());
	tot=n,mn=1e9,findrt(1,0),solve(rt);write(ans,'\n');
	return ot(),0; 
}
//Author: disangan233