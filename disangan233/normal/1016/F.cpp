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
	in db find() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int N=3e5+5;
using namespace std;
ll n,m,ans,t,r,tg,f[N],d[N],siz[N],vis[N],a[N],q[N],s[N];
vector<pii>e[N];in void add(int u,int v,int w) {e[u].pb({v,w}),e[v].pb({u,w});} 
int dfs(int u,int fa)
{
	if(u==n) return 1;
	for(auto [v,w]:e[u]) if(v^fa)
	{
		s[++t]=v,a[t]=w,vis[v]=1;
		if(dfs(v,u)) return 1;t--;vis[v]=0;
	}return 0;
}
void dp(int u,int fa)
{
	siz[u]=1;
	for(auto [v,w]:e[u]) if(v^fa&&!vis[v]) dp(v,u),siz[u]+=siz[v],f[u]=max(f[u],f[v]+w); 
}
int main()
{
	n=read(),m=read();ans=-1e18;
	for(int i=1,u,v;i<n;i++) u=read(),v=read(),add(u,v,read());
	s[t=1]=vis[1]=1;dfs(1,0);
	for(int i=1;i<=t;i++) d[i]=d[i-1]+a[i];
	for(int i=1;i<=t;i++) dp(s[i],0),tg|=siz[s[i]]>2;
	if(siz[s[1]]>1||siz[s[2]]>1) ans=max(ans,f[s[1]]+f[s[2]]+d[t]-d[2]);
	q[r=1]=1;
	for(int i=3;i<=t;i++)
	{
		ans=max(ans,f[s[i]]+f[s[q[1]]]+d[q[1]]+d[t]-d[i]);
		if(siz[s[i]]>1||siz[s[i-1]]>1) ans=max(ans,f[s[i]]+f[s[i-1]]+d[t]-d[i]+d[i-1]);
		while(r&&f[s[i-1]]+d[i-1]>=f[s[q[r]]]+d[q[r]]) r--;q[++r]=i-1;
	}
	while(m--) {int x=read();write(tg?d[t]:min(d[t],ans+x),'\n');}
	return ot(),0;
}
//Author: disangan233