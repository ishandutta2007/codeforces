// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1) if(nc==45) y=-1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58) x=(x<<3)+(x<<1)+(nc^48);return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=3e5;
int n,t,a1[N],a2[N],b1[N],b2[N],mxa1[N],mxa2[N],mna1[N],mna2[N];
int mxb1[N],mxb2[N],mnb1[N],mnb2[N],s1[N],s2[N];
char s[N];
in void calc(re n,re *s,re *a,re *b,re *mna,re *mxa,re *mnb,re *mxb)
{
	for(re i=1;i<=n;i++) a[i]=a[i-1]+s[i],mna[i]=s[i]+min(0,mna[i-1]),mxa[i]=s[i]+max(0,mxa[i-1]);
	for(re i=n;i;i--) b[i]=b[i+1]+s[i],mnb[i]=min(mnb[i+1],b[i]),mxb[i]=max(mxb[i+1],b[i]);
}
in ll solve(re i,re *b,re *mxa,re *mna,re *mxb,re *mnb)
{
	return min(
		max(mxb[i+1],b[i+1]+1+max(mxa[i],0))-min(mnb[i+1],b[i+1]+1+min(mna[i],0)),
		max(mxb[i+1],b[i+1]-1+max(mxa[i],0))-min(mnb[i+1],b[i+1]-1+min(mna[i],0))
	)+1;
}
int main()
{
	t=read();
	for(re tt=1;tt<=t;tt++)
	{
		re n=gs(s+1),n1=0,n2=0;
		for(re i=1;i<=n;i++)
		{
			if(s[i]=='W') s1[++n1]=1;
			if(s[i]=='S') s1[++n1]=-1;
			if(s[i]=='A') s2[++n2]=1;
			if(s[i]=='D') s2[++n2]=-1;
		}
		calc(n1,s1,a1,b1,mna1,mxa1,mnb1,mxb1);
		calc(n2,s2,a2,b2,mna2,mxa2,mnb2,mxb2);
		ll ans=(ll)(mxb2[1]-mnb2[1]+1)*(mxb1[1]-mnb1[1]+1);
		for(re i=0;i<=n1;i++) ans=min(ans,(ll)(mxb2[1]-mnb2[1]+1)*solve(i,b1,mxa1,mna1,mxb1,mnb1));
		for(re i=0;i<=n2;i++) ans=min(ans,(ll)(mxb1[1]-mnb1[1]+1)*solve(i,b2,mxa2,mna2,mxb2,mnb2));
		write(ans,'\n');
		for(re i=0;i<=n+1;i++) a1[i]=a2[i]=b1[i]=b2[i]=mxa1[i]=mxa2[i]=mna1[i]=mna2[i]=mxb1[i]=mxb2[i]=mnb1[i]=mnb2[i]=s1[i]=s2[i]=0;
	};
	return ot(),0;
}
//Author: disangan233