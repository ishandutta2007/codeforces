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
const int N=5e2+5;
int T,n,m;char a[N][N];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++) gs(a[i]+1);
		for(int i=1;i<=n;i+=3) for(int j=1;j<=m;j++) a[i][j]='X';
		for(int i=4;i<=n;i+=3) 
		{
			int k=m;for(int j=m;j;j--) if(a[i-1][j]=='X'||a[i-2][j]=='X') k=j;
			a[i-1][k]=a[i-2][k]='X';
		}
		if(n%3==0)
		{
			int k=m+1;
			for(int i=m;i;i--) if(a[n][i]=='X'||a[n-1][i]=='X') k=i;
			if(k<=m)
			{
				a[n][k]=a[n-1][k]='X';
				for(int i=1;i<=m;i++) if(a[n-1][i]=='X') a[n][i]=a[n-1][i]='X',k=i;
				else if(a[n][i]=='X') while(k<i) a[n][++k]='X';
			}
		} 
		for(int i=1;i<=n;i++) write(a[i]+1),memset(a[i]+1,0,m);
	}
	return ot(),0;
}
//Author: disangan233