#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
namespace t1
{
	const int N=1e2+5;
	int ans,n,a[N],b[N],c[N],vis[5][5][N*1000];
	vector<int>g[5][5];
	void dfs(re u,re nw)
	{
		ans=max(ans,nw);
		for(re v=1;v<=4;v++) 
		{
			#define p g[u][v]
			#define vv vis[min(u,v)][max(u,v)][p[i]]
			for(re i=0;i<p.size();i++) if(!vv)
			vv=1,dfs(v,nw+p[i]),vv=0;
		}
	}
	in void solve() 
	{
		n=read();
		for(re i=1;i<=n;i++) 
		{
			a[i]=read(),b[i]=read(),c[i]=read();
			g[a[i]][b[i]].push_back(c[i]);
			g[b[i]][a[i]].push_back(c[i]);
		}
		for(re i=1;i<=4;i++) dfs(i,0);
		write(ans,'\n');
	}
}
namespace t2
{
	const int N=2e5+5;
	int n,a[N],h[N],cnt,sum;
	struct did{int next,to,w;}e[N<<1];
	in void Add(re x,re y,re z) {e[++cnt]=(did){h[x],y,z},h[x]=cnt;}
	in void add(re x,re y,re z) {Add(x,y,z);Add(y,x,z);}
	in void solve() 
	{
		n=read();
		for(re i=1,u,v,w;i<n;i++) u=read(),v=read(),w=read(),add(u,v,w),sum+=w;
		write(sum,'\n');
	}
}
namespace t3
{
	const int N=5e5+5;
	int n,m,ans,fa[N],vis[N];
	struct ha{
		int s,t,w;
		in bool operator <(ha x) const {return w>x.w;}
	}t[N];
	int getfa(re x) {return fa[x]^x?fa[x]=getfa(fa[x]):x;}
	in void solve()
	{
		m=read(),n=read();for(re i=1;i<=m;i++) fa[i]=i;
		for(re i=1;i<=n;i++) t[i]=(ha){read(),read(),read()};
		sort(t+1,t+n+1);
		for(re i=1;i<=n;++i)
		{
			re u=getfa(t[i].s),v=getfa(t[i].t);
			if(vis[u]&&vis[v]) continue;
			if(u!=v) fa[v]=u,ans+=t[i].w,vis[u]|=vis[v];
			else vis[vis[u]?v:u]|=1,ans+=t[i].w;
		}
//		write("0");
		write(ans,'\n');
	}
}
int main()
{
//	freopen("there.in","r",stdin);
//	freopen("there.out","w",stdout);
//	t1::solve();t2::solve();
	t3::solve();
	return ot(),0;
}
//Author: disangan23
//In my dream's scene,I can see the everything that in Cyaegha.