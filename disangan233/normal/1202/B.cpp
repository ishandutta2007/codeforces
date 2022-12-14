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
const int N=2e6+5;
int n,a[10][10][111],b[10][10][111];
char s[N];
int main()
{
	n=gs(s+1);memset(a,127,sizeof(a));memset(b,127,sizeof(b));
	for(re i=0;i<=9;i++) for(re j=0;j<=9;j++)
	{
		a[i][j][0]=0;
		for(re k=0;k<=99;k++)
		{
			a[i][j][k+i]=min(a[i][j][k+i],a[i][j][k]+1);
			a[i][j][k+j]=min(a[i][j][k+j],a[i][j][k]+1);
		}
		for(re k=1;k<=110;k++) b[i][j][k%10]=min(b[i][j][k%10],a[i][j][k]);
		if(!i||!j) b[i][j][0]=1;
	}
	for(re i=0;i<=9;i++,write("")) for(re j=0;j<=9;j++)
	{
		re ans=0,bj=1;
		for(re k=2;k<=n;k++)
		{
			re x=b[i][j][(s[k]-s[k-1]+10)%10];
			x=max(x-1,0);
			if(x>=1e9) {bj=0;write(-1,' ');break;}
			ans+=x;
		}
		if(bj) write(ans,' ');
	}
	return ot(),0;
}
//Author: disangan233