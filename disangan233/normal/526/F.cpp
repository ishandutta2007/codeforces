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
};
using namespace fast_io;
#define pb push_back
const int N=3e5+5;
int n,m,k,a[N],b[N],c[N],le[N<<2],x[N<<2],t[N<<2];ll ans;
unordered_map<int,int>mp;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
void build(int p,int l,int r) 
{
	le[p]=r-l+1;if(l==r) return;
	build(ls(p),l,mid);build(rs(p),mid+1,r);
}
in void add(int p,int v) {x[p]+=v;t[p]+=v;}
void add(int p,int l,int r,int L,int R,int v)
{
	if(r<L||R<l) return; if(L<=l&&r<=R) return add(p,v);
	if(t[p]) add(ls(p),t[p]),add(rs(p),t[p]),t[p]=0;
	add(ls(p),l,mid,L,R,v);add(rs(p),mid+1,r,L,R,v);
	x[p]=min(x[ls(p)],x[rs(p)]);le[p]=le[ls(p)]*(x[ls(p)]==x[p])+le[rs(p)]*(x[rs(p)]==x[p]); 
}
int main()
{
	n=read();for(int i=1;i<=n;i++) a[read()]=read();
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		while(m&&a[b[m]]<a[i]) add(1,1,n,b[m-1]+1,b[m],-a[b[m]]),m--;
		while(k&&a[c[k]]>a[i]) add(1,1,n,c[k-1]+1,c[k],a[c[k]]),k--;
		add(1,1,n,mp[a[i]]+1,i,-1),mp[a[i]]=b[++m]=c[++k]=i;
		add(1,1,n,b[m-1]+1,i,a[i]);add(1,1,n,c[k-1]+1,i,-a[i]);ans+=le[1]; 
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233