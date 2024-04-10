#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
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
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+5;
int n,rt,w[N],siz[N],vis[N],ans1;db sum,sd,d[N],ans2=1e100;
vector<pii>e[N];in void add(int u,int v,int w) {e[u].eb(v,w);e[v].eb(u,w);}
void dfs(int u,int fa,int t)
{
	siz[u]=1;int mx=0;
	for(auto [v,w]:e[u]) if(!vis[v]&&v^fa) dfs(v,u,t),siz[u]+=siz[v],mx=max(mx,siz[v]);
	mx=max(mx,t-siz[u]);if(mx<=(t>>1)) rt=u;
}
void calc(int u,int fa,int p,int x)
{
	sum+=pow(x,1.5)*w[u];d[p]+=pow(x,0.5)*1.5*w[u];
	for(auto [v,w]:e[u]) if(v^fa) calc(v,u,p,x+w);
}
void solve(int u,int t)
{
	dfs(u,0,t),u=rt,dfs(u,0,t); if(vis[u]) return;
	vis[u]=1;sum=sd=0;
	for(auto [v,w]:e[u]) d[v]=0,calc(v,u,v,w),sd+=d[v];
	if(sum<ans2) ans1=u,ans2=sum;
	for(auto [v,w]:e[u]) if(sd-d[v]*2<0) {solve(v,siz[v]);break;}
}
int main()
{
	n=read();for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1,u,v;i<n;i++) u=read(),v=read(),add(u,v,read());
	solve(1,n);printf("%d %.10lf\n",ans1,ans2);
	return ot(),0;
}
//Author: disangan233