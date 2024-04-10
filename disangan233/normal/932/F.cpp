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
#define pb push_back
#define mid ((l+r)>>1) 
const int N=2e5+5,d=1e5;
int n,m,tot,rt[N],ls[N<<5],rs[N<<5],t[N<<5];ll a[N],b[N],ans[N];
vector<int>e[N];in void add(int u,int v) {return e[u].pb(v),e[v].pb(u);}
struct ed{ll k,b;}line[N];in ll ask(int i,ll x) {return line[i].k*x+line[i].b;}
void ins(int &p,int l,int r,int x)
{
	if(!p) return p=++tot,t[p]=x,void();
	if(ask(t[p],mid)>ask(x,mid)) swap(t[p],x);
	if(ask(t[p],l)<=ask(x,l)&&ask(t[p],r)<=ask(x,r)) return;
	ask(t[p],l)>ask(x,l)?ins(ls[p],l,mid,x):ins(rs[p],mid+1,r,x);
}
ll ask(int p,int l,int r,int x)
{
	if(!p) return 1e18;
	return min(ask(t[p],x),x<=mid?ask(ls[p],l,mid,x):ask(rs[p],mid+1,r,x));
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y) return x|y;ins(x,l,r,t[y]);
	return ls[x]=merge(ls[x],ls[y],l,mid),rs[x]=merge(rs[x],rs[y],mid+1,r),x;
}
void dfs(int u,int fa)
{
	for(int v:e[u]) if(v^fa) dfs(v,u),rt[u]=merge(rt[u],rt[v],1,2*d);
	ans[u]=ask(rt[u],1,2*d,a[u]+d);if(ans[u]==1e18) ans[u]=0;
	line[u]={b[u],ans[u]-b[u]*d},ins(rt[u],1,2*d,u);
}
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<n;i++) add(read(),read());
	dfs(1,0);for(int i=1;i<=n;i++) write(ans[i],' '); 
	return ot(),0;
}
//Author: disangan233