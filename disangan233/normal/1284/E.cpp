// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
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
}
using namespace fast_io;
const int N=2.5e3+5;
const long db eps=1e-20,pi=acos(-1);
long db d[N];int n,tot,x[N],y[N];ll ans;
in int l(int x) {return (x==1)?tot:x-1;}
in int r(int x) {return (x==tot)?1:x+1;}
in long db calc(int i,int j) {return (i<=j)?d[j]-d[i]:d[j]-d[i]+360;}
in ll c1(ll n) {return (ll)n*(n-1)*(n-2)/6;}
in ll c2(ll n) {return (ll)n*(n-1)*(n-2)*(n-3)/24;}
int main()
{
	n=read();for(int i=1;i<=n;i++) x[i]=read(),y[i]=read(); 
	for(int i=1;i<=n;i++)
	{
		tot=0;
		for(int j=1;j<=n;j++) if(i^j)
		{
			int nx=x[j]-x[i],ny=y[j]-y[i];if(!nx&&!ny) continue;
			if(!nx) {d[++tot]=(ny>0?0:180);continue;}
			if(!ny) {d[++tot]=(nx>0?90:270);continue;} 
			long db nw=asin(fabs((long db)nx/sqrt((ll)nx*nx+(ll)ny*ny)));nw=nw*180/pi;
			d[++tot]=(nx>0&&ny>0?nw:nx<0&&ny<0?180+nw:nx>0&&ny<0?180-nw:360-nw); 
		}
		if(tot<=3) continue;sort(d+1,d+tot+1);ans+=c2(tot);
		for(int j=1,k=1;j<=tot;j++)
		{
			while(r(k)^j&&calc(j,r(k))-eps<=180) k=r(k);
			int tmp=(j<=k?k-j+1:tot-j+k+1);if(tmp>=4) ans-=c1(tmp-1);
		}
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.