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
#define pb push_back
const int N=2e2+5,p=1e9+7; 
int n,m,f[N][N][N],g[N][2],nxt[N];char s[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
int main()
{
	n=read();m=gs(s+1);f[0][0][0]=1;
	for(int i=2,j=0;i<=m;i++) 
	{
		while(j&&s[i]^s[j+1]) j=nxt[j];
		j+=(s[i]==s[j+1]),nxt[i]=j; 
	}
	for(int i=0;i<m;i++)
	{
		int k=i,p=i;
		while(k&&s[k+1]^'(') k=nxt[k];
		while(p&&s[p+1]^')') p=nxt[p];
		k+=(s[k+1]=='('),p+=(s[p+1]==')');
		g[i][0]=p,g[i][1]=k;
	}
	g[m][0]=g[m][1]=m;
	for(int i=0;i<n*2;i++) for(int j=0;j<=n;j++) for(int k=0;k<=m;k++)
	M(f[i+1][j+1][g[k][1]]+=f[i][j][k]),j?M(f[i+1][j-1][g[k][0]]+=f[i][j][k]):void();
	write(f[n*2][0][m],'\n');
	return ot(),0;
}
//Author: disangan233