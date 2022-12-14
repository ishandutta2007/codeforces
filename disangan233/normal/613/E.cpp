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
const int N=2e3+5,p=1e9+7;
in void M(int &x) {x-=p;x+=x>>31&p;}
int n,m,ans,lp1[2][N][N],lp2[2][N][N],ls1[2][N][N],ls2[2][N][N],f[2][N][N],g[2][N][N];
bool u1[2][N][N],u2[2][N][N];
char s[2][N],t[N];
void calc()
{
	for(int i=0;i<2;i++)
	{
		for(int k=m;k;k--)
		{
			for(int j=n;j;j--) lp1[i][j][k]=(s[i][j]==t[k])?lp1[i][j+1][k+1]+1:0;
			for(int j=1;j<=n;j++) lp2[i][j][k]=(s[i][j]==t[k])?lp2[i][j-1][k+1]+1:0;
		}
		for(int k=1;k<=m;k++)
		{
			for(int j=n;j;j--) ls1[i][j][k]=(s[i][j]==t[k])?ls1[i][j+1][k-1]+1:0;
			for(int j=1;j<=n;j++) ls2[i][j][k]=(s[i][j]==t[k])?ls2[i][j-1][k-1]+1:0;
		}
	}
	for(int i=0;i<2;i++) for(int j=1;j<=n;j++)
	{
		for(int k=2;k<=min(n-j+1,m/2);k++) u1[i][j][k]=ls1[!i][j][m]>=k&&ls2[i][j+k-1][m-k]>=k;
		for(int k=2;k<=min(j,m/2);k++) u2[i][j][k]=lp1[i][j-k+1][k+1]>=k&&lp2[!i][j][1]>=k;
	}
	if(~m&1) for(int i=1;i<=n;i++)
	{
		M(ans+=u1[1][i][m/2]),M(ans+=u2[1][i][m/2]);
		for(int j=0;j<2;j++) for(int k=2;k<=m/2-2;k++) M(ans+=u2[j][i][k]&&u1[j][i+1][m/2-k]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(s[j][i]==t[1]) M(f[j][i][1]+=1);
			for(int k=2;k<=m/2;k++) if(u2[j][i-1][k]&&s[j][i]==t[k+k+1]) M(f[j][i][k+k+1]+=1);
			for(int k=1;k<=m;k++) if(s[j][i]==t[k+1]) M(f[j][i][k+1]+=f[j][i-1][k]),M(f[j][i][k+1]+=g[j][i-1][k]);
			for(int k=1;k<=m;k++) if(s[!j][i]==t[k+1]) M(g[!j][i][k+1]+=f[j][i][k]);
		}
		for(int j=0;j<2;j++)
		{
			M(ans+=f[j][i][m]),M(ans+=g[j][i][m]);
			for(int k=2;k<=m/2;k++) if(u1[j][i+1][k])
			M(ans+=f[j][i][m-k-k]),M(ans+=g[j][i][m-k-k]);
		}
	}
}
int main()
{
	n=gs(s[0]+1);gs(s[1]+1);m=gs(t+1);
	if(m==1)
	{
		for(int i=0;i<2;i++) for(int j=1;j<=n;j++) ans+=s[i][j]==t[1];
	}
	else if(m==2)
	{
		for(int i=0;i<2;i++) for(int j=1;j<=n;j++) if(s[i][j]==t[1])
		ans+=(s[!i][j]==t[2])+(s[i][j-1]==t[2])+(s[i][j+1]==t[2]);
	}
	else
	{
		calc();reverse(t+1,t+m+1);
		memset(f,0,sizeof(f));memset(g,0,sizeof(g));calc();
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233