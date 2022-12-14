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
#define pb push_back
const int N=2e5+5;
int n,m,q,i,j,cc,bs,p[N],a[N],lst[N],nxt[N],pre[N],c[N],d[N],nd[N],r[N],lj[N];
vector<int>e[N];
void dfs(int u)
{
	nd[d[u]]=u;r[u]=(d[u]>=n)?nd[d[u]-n+1]:m+1;
	for(int v:e[u]) d[v]=d[u]+1,dfs(v); 
}
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) nxt[p[i]=read()]=p[i-1];
	nxt[p[1]]=p[n];
	for(int i=1;i<=m;i++)
	{
		a[i]=read(),pre[i]=lst[a[i]],lst[a[i]]=i;
		for(int j=lst[nxt[a[i]]];j&&!c[j];j=pre[j]) c[j]=i;
	}
	for(int i=1;i<=m;e[c[i]].pb(i),i++) if(!c[i]) c[i]=m+1;
	dfs(m+1);for(int i=m-1;i;i--) r[i]=min(r[i+1],r[i]);
	while(q--)
	{
		int i=read(),j=read();
		sr[++C]=48+(r[i]<=j);
	}
	return ot(),0;
}
//Author: disangan233