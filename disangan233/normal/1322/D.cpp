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
    in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
const int N=4e3+5,K=1<<11,inf=1e9;
int n,m,ans,d[N],s[N],c[N],t[N],f[N][N];
in void cmx(int&x,int y) {if((x-y)>>31)x=y;}
int main()
{
	n=read(),m=read();t[0]=n;m+=n;
	for(int i=n;i;i--) d[i]=read();
	for(int i=n;i;i--) s[i]=read();
	for(int i=1;i<=m;i++) c[i]=read();
	for(int i=1;i<=n;i++) t[i]=t[i-1]>>1;
	for(int i=0;i<=m;i++) for(int j=1;j<=n;j++) f[i][j]=-inf;
	for(int i=1;i<=n;i++)
	{
		int p=d[i];
		for(int j=n;j;j--) cmx(f[p][j],f[p][j-1]+c[p]-s[i]);
		for(int j=p;j<=m;j++) for(int k=0;k<=t[j-p];k++) cmx(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	write(f[m][0],'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.