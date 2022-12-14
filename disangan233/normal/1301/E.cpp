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
const int N=5e2+5;
int n,m,t,a[N][N],b[N][N],c[N][N],d[N][N],f[N][N][N];
in int s(int s[][N],int a,int b,int c,int d) {return s[c][d]+s[a-1][b-1]-s[c][b-1]-s[a-1][d];}
int main()
{
	n=read(),m=read(),t=read();
	for(int i=1;i<=n;i++)
	{
		char s[N];gs(s+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(s[j]=='R');
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(s[j]=='G');
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(s[j]=='Y');
			d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(s[j]=='B');
		}
	}
	for(int k=1;k<=N<<1;k++) for(int i=k<<1;i<=n;i++) for(int j=k<<1;j<=m;j++)
	{
		f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];int k2=k+k,kk=k*k;
		f[k][i][j]+=(s(a,i-k2+1,j-k2+1,i-k,j-k)==kk&&s(b,i-k2+1,j-k+1,i-k,j)==kk&&s(c,i-k+1,j-k2+1,i,j-k)==kk&&s(d,i-k+1,j-k+1,i,j)==kk);
	}
	while(t--)
	{
		int x1=read(),y1=read(),x2=read(),y2=read(),l=0,r=min((x2-x1+1)/2,(y2-y1+1)/2),mid;
		while(l<r) mid=(l+r+1)>>1,s(f[mid],x1+mid*2-1,y1+mid*2-1,x2,y2)>0?l=mid:r=mid-1;
		write(4*l*l,'\n');
	}
	return ot(),0;
}
//Author: disangan233