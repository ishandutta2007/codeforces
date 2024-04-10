#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],sz[23],nc;int C=-1,Z=0,Bi=0,ny;
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
		int y=0;if(x<0)y=1,x=-x;while(sz[++Z]=x%10+48,x/=10);
		if(y)sz[++Z]='-';while(sr[++C]=sz[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
#define pb push_back
#define chk(a,b,c,d,e,f) if((a==b)&&(c==d)&&(e==f))
const int N=1e3+5; 
int n,m,k,x,y,z,*xx,*yy,*zz,a[N][N],b[N][N];char s[N*N];
int main()
{
	int t=read();
	while(t--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=read();
		gs(s+1);x=0,y=0,z=0,xx=&x,yy=&y,zz=&z;
		for(int i=1;i<=m;i++)
		{
			*xx+=(s[i]=='D')-(s[i]=='U'),*yy+=(s[i]=='R')-(s[i]=='L');
			if(s[i]=='I') swap(yy,zz);if(s[i]=='C') swap(xx,zz);
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		{
			int sx=((i+x-1)%n+n)%n+1,sy=((j+y-1)%n+n)%n+1,sz=((a[i][j]+z-1)%n+n)%n+1;
			chk(xx,&x,yy,&y,zz,&z) b[sx][sy]=sz;chk(xx,&x,yy,&z,zz,&y) b[sx][sz]=sy;
			chk(xx,&y,yy,&x,zz,&z) b[sy][sx]=sz;chk(xx,&y,yy,&z,zz,&x) b[sy][sz]=sx;
			chk(xx,&z,yy,&x,zz,&y) b[sz][sx]=sy;chk(xx,&z,yy,&y,zz,&x) b[sz][sy]=sx;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) write(b[i][j]," \n"[j==n]);
		memset(s+1,0,k);if(t) sr[++C]='\n';
	}
	return ot(),0;
}
//Author: disangan233