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
int n,m,k,cnt,s[N];
char t[N];
void dfs(re x)
{
	if(!x) return;
	for(re i=1;;i++) if(i*(i-1)/2>x)
	return s[++k]=i-1,dfs(x-(i-1)*(i-2)/2),void();
}
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	{
		m=read(),cnt=k=0;dfs(m);sr[++C]='1';
		for(re j=k;j;j--)
		{
			while(cnt<s[j]) cnt++,sr[++C]='3';
			sr[++C]='7';
		}
		sr[++C]='\n';
	}
	return ot(),0;
}
//Author: disangan233