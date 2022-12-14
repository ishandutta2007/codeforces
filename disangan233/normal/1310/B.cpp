#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
const int N=17;
int n,k,b,f[1<<N][4];
int main()
{
	n=read(),k=read(),b=1<<(n-1);
	for(int i=0;i<2*b;i++) f[i][0]=0,f[i][1]=f[i][2]=f[i][3]=-1e9;
	for(int i=1,a;i<=k;i++) a=b+(read()-1)/2,f[a][3]=f[a][1],f[a][1]=f[a][2]=1;
	for(int i=b-1;i;i--) for(int j=0;j<4;j++) for(int k=0;k<4;k++) 
	f[i][j|k]=max(f[i][j|k],f[i<<1][j]+f[i<<1|1][k]+(j|k));
	write(max({f[1][1],f[1][2],f[1][3],-1})+1,'\n');
	return ot(),0;
}
//Author: disangan233