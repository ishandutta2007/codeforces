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
const int N=2e5+5;
int n,m,s[N<<2],lmx[N<<2],lmn[N<<2],rmx[N<<2],rmn[N<<2],ld[N<<2],rd[N<<2],mad[N<<2],t[N<<2];char a[N];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
in void up(int x)
{
	s[x]=s[ls(x)]+s[rs(x)];
	lmx[x]=max(lmx[ls(x)],s[ls(x)]+lmx[rs(x)]);rmx[x]=max(rmx[rs(x)],s[rs(x)]+rmx[ls(x)]);
	lmn[x]=min(lmn[ls(x)],s[ls(x)]+lmn[rs(x)]);rmn[x]=min(rmn[rs(x)],s[rs(x)]+rmn[ls(x)]);
	ld[x]=max(ld[ls(x)],max(ld[rs(x)]-s[ls(x)],mad[ls(x)]+lmx[rs(x)]));
	rd[x]=max(rd[rs(x)],max(s[rs(x)]+rd[ls(x)],mad[rs(x)]-rmn[ls(x)]));
	mad[x]=max(mad[ls(x)]+s[rs(x)],mad[rs(x)]-s[ls(x)]);
	t[x]=max(max(t[ls(x)],t[rs(x)]),max(ld[rs(x)]-rmn[ls(x)],rd[ls(x)]+lmx[rs(x)]));
}
void build(int p,int l,int r)
{
	if(l==r) 
	{
		int v=a[l]=='('?1:-1;s[p]=v;lmx[p]=rmx[p]=max(v,0),lmn[p]=rmn[p]=min(v,0);
		ld[p]=rd[p]=mad[p]=t[p]=1;return;
	}
	build(ls(p),l,mid),build(rs(p),mid+1,r),up(p);
}
void add(int p,int l,int r,int x,int v)
{
	if(l==r) return s[p]=v,lmx[p]=rmx[p]=max(v,0),lmn[p]=rmn[p]=min(v,0),ld[p]=rd[p]=mad[p]=t[p]=1,void();
	x<=mid?add(ls(p),l,mid,x,v):add(rs(p),mid+1,r,x,v);up(p); 
}
int main()
{
	n=read()-1<<1,m=read();gs(a+1);
	build(1,1,n);write(t[1],'\n');
	while(m--)
	{
		int x=read(),y=read();
		if(a[x]^a[y]) swap(a[x],a[y]),add(1,1,n,x,a[x]=='('?1:-1),add(1,1,n,y,a[y]=='('?1:-1);
		write(t[1],'\n'); 
	}
	return ot(),0;
}
//Author: disangan233