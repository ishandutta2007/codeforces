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
#define eb emplace_back
#define fi first
#define se second
const int N=2e3+5;
int n,m,S,T,a[N],cs,ct,c[N][N],ns[N][N],nt[N][N],vis[N];
ll ds[N],dt[N],sm[N],f[2][N][N],s[N][N];
vector<pair<int,int>>e[N];in void add(int u,int v,int w) {e[u].eb(v,w),e[v].eb(u,w);}
in void dijkstra(int s,ll *d,int &c)
{
	for(int i=1;i<=n;i++) d[i]=1e18,vis[i]=0;
	priority_queue<pair<ll,int>>q;d[s]=0;q.push(make_pair(0,s));
	while(q.size())
	{
		int u=q.top().se;q.pop();if(vis[u])continue;vis[u]=1;
		for(auto x:e[u]) if(d[x.fi]>d[u]+x.se) d[x.fi]=d[u]+x.se,q.push(make_pair(-d[x.fi],x.fi));
	}
	memcpy(sm+1,d+1,8*n);sort(sm+1,sm+n+1);c=unique(sm+1,sm+n+1)-sm-1;
	for(int i=1;i<=n;i++) d[i]=lower_bound(sm+1,sm+c+1,d[i])-sm;
}
int main()
{
	n=read(),m=read(),S=read(),T=read();for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1,u,v;i<=m;i++) u=read(),v=read(),add(u,v,read());
	dijkstra(S,ds,cs);dijkstra(T,dt,ct);
	for(int i=1;i<=n;i++) c[ds[i]][dt[i]]++,s[ds[i]][dt[i]]+=a[i];
	for(int i=cs;i;i--) for(int j=ct;j;j--)
	{
		s[i][j]+=s[i+1][j]+s[i][j+1]-s[i+1][j+1];
		ns[i][j]=min(i==cs?cs:ns[i+1][j],j==ct?cs:ns[i][j+1]);
		nt[i][j]=min(i==cs?ct:nt[i+1][j],j==ct?ct:nt[i][j+1]);
		if(c[i][j]) ns[i][j]=i,nt[i][j]=j;
		f[0][i][j]=s[i][j]-f[1][ns[i][j]+1][j];f[1][i][j]=s[i][j]-f[0][i][nt[i][j]+1];
		if(i==1&&j==1) continue;
		f[0][i][j]=min(f[0][i][j],f[0][i][j+1]);f[1][i][j]=min(f[1][i][j],f[1][i+1][j]);
	}
	ll ans=s[1][1]-2*f[0][1][1];
	ans<0?write("Break a heart"):(ans>0?write("Cry"):write("Flowers"));
	return ot(),0;
}
//Author: disangan233