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
const int N=5e2+5,K=11;
int n,m,k,a[N][N],b[N][N],f[N][N][K];
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) a[i][j]=read();
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) b[i][j]=read();
	if(k&1)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) write(-1," \n"[j==m]);
		return ot(),0;
	}k>>=1;
	memset(f,63,sizeof(f));for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j][0]=0;
	for(int d=1;d<=k;d++) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(i>1) f[i][j][d]=min(f[i][j][d],f[i-1][j][d-1]+b[i-1][j]);
		if(i<n) f[i][j][d]=min(f[i][j][d],f[i+1][j][d-1]+b[i][j]);
		if(j>1) f[i][j][d]=min(f[i][j][d],f[i][j-1][d-1]+a[i][j-1]);
		if(j<m) f[i][j][d]=min(f[i][j][d],f[i][j+1][d-1]+a[i][j]);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) write(f[i][j][k]*2," \n"[j==m]);
	return ot(),0;
}