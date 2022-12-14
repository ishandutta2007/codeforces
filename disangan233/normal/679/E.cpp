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
const int N=1e5+5;
int n,m,a[N],t2[N<<2];ll t1[N<<2],t3[N<<2],mn[N<<2],b[10];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
in int g(ll x) {return lower_bound(b,b+10,x)-b;}
in void add1(int x,ll y,int v) {mn[x]=t1[x]=y;t2[x]=v;t3[x]=0;}
in void add2(int x,ll y)
{
	if(!t2[x]) mn[x]-=y,t3[x]+=y;
	else {t1[x]-=y;while(t1[x]<0)t1[x]+=b[t2[x]+1]-b[t2[x]],t2[x]++;mn[x]=t1[x];}
}
in void down(int x)
{
	if(t1[x]) add1(ls(x),t1[x],t2[x]),add1(rs(x),t1[x],t2[x]),t1[x]=t2[x]=0;
	if(t3[x]) add2(ls(x),t3[x]),add2(rs(x),t3[x]),t3[x]=0;
}
void add(int p,int l,int r,int L,int R,ll v,int x)
{
	if(R<l||r<L) return; if(L<=l&&r<=R) return add1(p,v,x);down(p);
	add(ls(p),l,mid,L,R,v,x);add(rs(p),mid+1,r,L,R,v,x);mn[p]=min(mn[ls(p)],mn[rs(p)]);
}
ll add(int p,int l,int r,int L,int R,ll v)
{
	if(R<l||r<L) return 1e18; if(L<=l&&r<=R&&(mn[p]>=v||t2[p])) return add2(p,v),mn[p];down(p);
	add(ls(p),l,mid,L,R,v);add(rs(p),mid+1,r,L,R,v);return mn[p]=min(mn[ls(p)],mn[rs(p)]);
}
ll ask(int p,int l,int r,int x)
{
	if(l==r) return b[t2[p]]-t1[p];down(p);
	return x<=mid?ask(ls(p),l,mid,x):ask(rs(p),mid+1,r,x);
}
int main()
{
	b[0]=1;for(int i=1;i<10;i++) b[i]=b[i-1]*42;
	n=read(),m=read();for(int i=1,x;i<=n;i++) x=read(),add(1,1,n,i,i,b[g(x)]-x,g(x));
	while(m--)
	{
		int op=read(),l=read(),r,x;
		if(op==1) write(ask(1,1,n,l),'\n');
		else if(op==2) r=read(),x=read(),add(1,1,n,l,r,b[g(x)]-x,g(x));
		else {r=read(),x=read();while(!add(1,1,n,l,r,x));}
	}
	return ot(),0;
}
//Author: disangan233