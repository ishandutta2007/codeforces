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
const int N=1e5+5;
int t,n,op,a[N],b[N]; 
int main()
{
	n=read();int op=0;for(int i=2;i*i<=n;i++) if(!(n%i)) op=1;
	if(op&&n>4) {write("NO");return ot(),0;}
	if(n==1) {write("YES\n1");return ot(),0;}
	if(n==4) {write("YES\n1\n3\n2\n4");return ot(),0;}
	a[1]=1,a[n]=n,a[n+1>>1]=n-1,b[0]=b[1]=1;
	for(int i=2;i<n;i++) b[i]=1ll*(n-n/i)*b[n%i]%n;
	for(int i=2,s=1;i<n;i++) a[i]=1ll*i*b[s]%n,s=1ll*s*a[i]%n;
	write("YES");for(int i=1;i<=n;i++) write(a[i],'\n');
	return ot(),0;
}
//Author: disangan233