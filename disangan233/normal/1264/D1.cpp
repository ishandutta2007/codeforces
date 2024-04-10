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
const int N=1e6+5,p=998244353;
int n,m,ans,a[N],b[N],l[N],c1[N],c2[N];char s[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;} 
int main()
{
	n=gs(s+1);c1[0]=c2[0]=1;for(int i=1;i<=n;i++) m+=s[i]=='?';
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='('),l[i]=l[i-1]+(s[i]=='?');
	for(int i=n;i;i--) b[i]=b[i+1]+(s[i]==')');
	for(int i=1;i<=m;i++) c1[i]=1ll*c1[i-1]*(m-i+1)%p*qpow(i,p-2)%p,c2[i]=1ll*c2[i-1]*(m-i)%p*qpow(i,p-2)%p;
	for(int i=1;i<=m;i++) M(c1[i]+=c1[i-1]),M(c2[i]+=c2[i-1]);
	for(int i=1;i<=n;i++)
	{
		int x=a[i-1]-b[i+1]+l[i-1]-1;if(x<0) continue;
		if(s[i]==')') M(ans+=c1[min(m,x)]); if(s[i]=='?') M(ans+=c2[min(m-1,x)]);
	} 
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233