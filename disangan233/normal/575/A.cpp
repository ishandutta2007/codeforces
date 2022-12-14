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
const int N=5e4+5;
int n,m,p,s[N];ll k,l;
in void M(int &x) {x-=p;x+=x>>31&p;}
struct mat
{
	int n,m,a[2][2];in mat(int p=2,int q=2,int x=0) {n=p,m=q;memset(a,0,sizeof(a));a[0][0]=a[1][1]=x;}
	in int* operator[](int x) {return a[x];}
	in mat operator*(mat b)
	{
		mat c(n,b.m);
		for(int k=0;k<m;k++) for(int i=0;i<c.n;i++) for(int j=0;j<c.m;j++) M(c[i][j]+=1ll*a[i][k]*b[k][j]%p);
		return c;
	}
	in mat operator^(ll x) {mat a=*this,b(a.n,a.m,1);for(;x;x>>=1,a=a*a)if(x&1)b=b*a;return b;}
}a[N],b[N],f(1,2),t[N<<2];
struct qry{
	ll x,k;int y;
	in bool operator<(qry a) const {return x<a.x;}
}q[N<<1];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
in void up(int p) {t[p]=t[ls(p)]*t[rs(p)];}
void build(int p,int l,int r)
{
	if(l==r) return t[p]=a[l],void();
	build(ls(p),l,mid);build(rs(p),mid+1,r);up(p);
}
void add(int p,int l,int r,int x,mat v)
{
	if(l==r) return t[p]=v,void();
	x<=mid?add(ls(p),l,mid,x,v):add(rs(p),mid+1,r,x,v);up(p);
}
int main()
{
	k=read(),p=read(),n=read();for(int i=0;i<n;i++) s[i]=read()%p;
	for(int i=1;i<=n;i++) a[i][0][1]=s[i-1],a[i][1][1]=s[i%n],a[i][1][0]=1,b[i]=a[i];
	build(1,1,n);m=read();
	for(int i=1;i<=m;i++) q[i].x=read(),q[m+i].x=q[i].x+1,q[i].k=1,q[m+i].y=q[i].y=read()%p;
	m<<=1;sort(q+1,q+m+1);while(m&&q[m].x>k) m--;f[0][1]=1;
	for(int i=1,j=1;i<=m;i=++j)
	{
		ll w=(q[i].x-1)/n;while(j<m&&w==(q[j+1].x-1)/n) j++;
		f=f*(t[1]^(w-l));l=w;
		for(int k=i,d;k<=j;k++) d=(q[k].x-1)%n+1,b[d][q[k].k][1]=q[k].y,add(1,1,n,d,b[d]);
		if(w==k/n) break;
		mat x=f*t[1];f=f*t[1];l=w+1;
		for(int k=i,d;k<=j;k++) d=(q[k].x-1)%n+1,add(1,1,n,d,b[d]=a[d]);
	}
	ll w=k/n;f=f*(t[1]^(w-l));for(int i=1;i<=k%n;i++) f=f*b[i];
	write(f[0][0],'\n');
	return ot(),0;
}
//Author: disangan233