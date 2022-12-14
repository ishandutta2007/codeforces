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
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
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
const int N=3e2+5,p=1e4+7;
int n,m,k,f[N],g[N][N],h[N][N][N],F[N],G[N][N];char s[N];bool v[N][N][N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in int cl(int x) {return (x>>1)+(x&1);}
in int H(int i,int l,int r)
{
	if(i<0) return 0; if(v[i][l][r]) return h[i][l][r]; v[i][l][r]=1;
	if(l==1&&r==m) return h[i][l][r]=!i;
	if(l^1&&s[l-1]^s[r]) M(h[i][l][r]+=H(i-1,l-1,r));
	if(r^m&&s[l]^s[r+1]) M(h[i][l][r]+=H(i-1,l,r+1));
	if(l^1&&r^m&&s[l-1]==s[r+1]) M(h[i][l][r]+=H(i,l-1,r+1));
	return h[i][l][r];
}
in void mul(int *f,int g[][N])
{
	static int a[N];for(int i=1;i<=k;i++) a[i]=0;
	for(int j=1;j<=k;j++) for(int i=1;i<=k;i++) M(a[i]+=f[j]*g[j][i]%p);
	memcpy(f+1,a+1,4*k);
}
in void mul(int g[][N])
{
	static int a[N][N];for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) a[i][j]=0;
	for(int i=1;i<=k;i++) for(int l=i;l<=k;l++) for(int j=l;j<=k;j++) M(a[i][j]+=g[i][l]*g[l][j]%p);
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) g[i][j]=a[i][j];
}
in void qpow(int x) {while(x) {if(x&1)mul(f,g);mul(g),x>>=1;}}
int main()
{
	m=gs(s+1);n=read();k=m+cl(m);
	for(int i=0;i<m;i++)
	{
		int c=0;
		for(int j=1;j<=m;j++)
		{
			M(c+=H(i,j,j));
			if(j^m&&s[j]==s[j+1]) M(c+=H(i,j,j+1));
		}
		if(i==0) {f[m]=c,g[k][k]=26;for(int j=m;j<k;j++) g[j][j+1]=1,g[j][j]=25;}
		else g[i][k-cl(m-i)]=c,g[i][i]=24,i^1?g[i-1][i]=1:f[i]=1;
	}
	if((n+m)&1)
	{
		memcpy(F+1,f+1,4*k);
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) G[i][j]=g[i][j];
	}
	qpow(cl(n+m));if(!((n+m)&1)) return write(f[k],'\n'),ot(),0;
	int ans=f[k];memcpy(f+1,F+1,4*k);
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) g[i][j]=G[i][j];
	for(int i=0;i<m;i++)
	{
		int c=0;
		for(int j=1;j<=m;j++) if(j^m&&s[j]==s[j+1]) M(c+=H(i,j,j+1));
		if(i) g[i][k-cl(m-i)]=c; else f[m]=c,g[k][k]=0;
	}
	qpow(cl(n+m));write((ans+p-f[k])%p,'\n');
	return ot(),0;
}
//Author: disangan233