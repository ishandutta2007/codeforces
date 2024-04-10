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
const int N=2e5+5;
int n,l;ll lx=-1e18,rx=1e18,ly=-1e18,ry=1e18;
struct did
{
	ll t,x,y,k;int w;
	in void init()
	{
		t=read();ll p=read(),q=read();
		if((t^p^q)&1) write("NO"),ot(),exit(0);
		k=t/l;w=t%l;x=(p+q+t)/2;y=(q-p+t)/2;
	}
	in bool operator<(did x)const{return w<x.w;}
}a[N];
int main()
{
	n=read(),l=read();for(int i=1;i<=n;i++) a[i].init();
	sort(a+1,a+n+1);a[++n].k=-1;a[n].w=l;
	for(int i=1;i<=n;i++)
	{
		ll k=a[i].k-a[i-1].k;int w=a[i].w-a[i-1].w;
		if(!k)
		{
			if(a[i].x-a[i-1].x-w>0||a[i].x-a[i-1].x<0) write("NO"),ot(),exit(0);
			if(a[i].y-a[i-1].y-w>0||a[i].y-a[i-1].y<0) write("NO"),ot(),exit(0);
		}
		else if(k>0)
		{
			lx=max(lx,(ll)ceil(1.0L*(a[i].x-a[i-1].x-w)/k));
			ly=max(ly,(ll)ceil(1.0L*(a[i].y-a[i-1].y-w)/k));
			rx=min(rx,(ll)floor(1.0L*(a[i].x-a[i-1].x)/k));
			ry=min(ry,(ll)floor(1.0L*(a[i].y-a[i-1].y)/k));
		}
		else
		{
			k*=-1;
			lx=max(lx,(ll)ceil(1.0L*(a[i-1].x-a[i].x)/k));
			ly=max(ly,(ll)ceil(1.0L*(a[i-1].y-a[i].y)/k));
			rx=min(rx,(ll)floor(1.0L*(a[i-1].x-a[i].x+w)/k));
			ry=min(ry,(ll)floor(1.0L*(a[i-1].y-a[i].y+w)/k));
		}
	}
	if(lx>rx||ly>ry) write("NO"),ot(),exit(0);
	for(int i=1;i<=n;i++)
	{
		int dx=(a[i].x-a[i].k*lx)-(a[i-1].x-a[i-1].k*lx);
		int dy=(a[i].y-a[i].k*ly)-(a[i-1].y-a[i-1].k*ly);
		int t=a[i].w-a[i-1].w,x=0,y=0;
		while(t--)
		{
			if(x<dx) x++,y<dy?(sr[++C]='U',y++):sr[++C]='R';
			else y<dy?(sr[++C]='L',y++):sr[++C]='D';
		}
	}
	return ot(),0;
}
//Author: disangan233