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
namespace P
{
	const int N=1<<21|1;const db pi=acos(-1);
	int n,m,len,L,r[N];
	struct I
	{
		db x,y;in I(db _x=0,db _y=0) {x=_x,y=_y;}
		in I &operator=(int a) {return x=a,y=0,*this;}
		in I &operator=(db a) {return x=a,y=0,*this;}
		in I operator+(I a) const {return I(x+a.x,y+a.y);}
		in I operator-(I a) const {return I(x-a.x,y-a.y);}
		in I operator*(I a) const {return I(x*a.x-y*a.y,x*a.y+y*a.x);}
	}a[N],b[N];
	in void fft(I *a,int n,int op)
	{
		for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(int k=1;k<=(n>>1);k<<=1)
		{
			I wi=I(cos(pi/k),op*sin(pi/k));
			for(int i=0;i<n;i+=(k<<1))
			{
				I w=I(1,0),x,y;
				for(int j=0;j<k;j++,w=w*wi) x=a[i+j],y=w*a[i+j+k],a[i+j]=x+y,a[i+j+k]=x-y;
			}
		}
	}
	in void solve()
	{
		L=ceil(log2(n+m-1));len=1<<L;
		for(int i=0;i<len;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
		for(int i=n;i<len;i++) a[i]=0; for(int i=m;i<len;i++) b[i]=0;
		// cout<<"?";
		fft(a,len,1);fft(b,len,1);for(int i=0;i<len;i++) a[i]=a[i]*b[i];
		// cout<<"!";
		fft(a,len,-1);for(int i=0;i<n+m-1;i++) a[i].x/=len;
		// cout<<"&\n";
	}
}
const int N=55,M=105,T=2e4+5;
int n,m,t,x,a[M],b[M];
db d[N][N],c[M],p[M][T<<1],f[M][T<<1],g[M][T];
void cdq(int l,int r)
{
	if(l==t) return;
	if(l==r)
	{
		for(int i=1;i<n;i++) f[i][l]=1e18;
		for(int i=1;i<=m;i++) if(a[i]^n) f[a[i]][l]=min(f[a[i]][l],g[i][l]+c[i]);
		return;
	}
	int mid=(l+r)>>1;cdq(mid+1,r);P::n=r-l;P::m=r-mid;
	for(int i=1;i<=m;i++) if(a[i]^n)
	{
		for(int j=0;j<P::n;j++) P::a[j]=p[i][j+1];
		for(int j=0;j<P::m;j++) P::b[j]=f[b[i]][r-j];
		P::solve();for(int j=l;j<=mid;j++) g[i][j]+=P::a[r-j-1].x;
	}cdq(l,mid);
}
int main()
{
	n=read(),m=read(),t=read(),x=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j) d[i][j]=1e18;
	for(int i=1;i<=m;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=d[a[i]][b[i]]=read();
		for(int j=1;j<=t;j++) p[i][j]=read()/1e5;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=0;i<t*2;i++) f[n][i]=(i<=t?0:x);
	for(int i=1;i<n;i++) for(int j=t;j<t*2;j++) f[i][j]=d[i][n]+x;
	cdq(0,2*t-1);printf("%.10lf",f[1][0]);
	return ot(),0;
}
//Author: disangan233