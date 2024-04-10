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
        ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;
        x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48);return x*y;
    }
    in db gf() {re a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
    in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
    in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
    in void flush() {if(C>1<<22) ot();}
    template <typename T>
    in void write(T x,char t)
    {
        re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
        if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
    }
    in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
const int N=1e6+5;
char s[N],t[N];
int n,m,ans,a[N],b[N],cnt[26];
in int calc1(re l,re r,re x)
{
	while(l<=r)
	{
		re mid=(l+r)>>1;
		if(a[mid]>=x) r=mid-1;
		else l=mid+1;
	}
	return l;
}
in int calc2(re l,re r,re x)
{
	while(l<=r)
	{
		re mid=(l+r)>>1;
		if(b[mid]>=m-x+1) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	n=gs(s+1);m=gs(t+1);
	for(re i=1;i<=n;i++) a[i]=a[i-1]+(s[i]==t[a[i-1]+1]);
	for(re i=n;i;i--) b[i]=b[i+1]+(s[i]==t[m-b[i+1]]);
	for(re i=1;i<m;i++)
	{
		re r=calc2(1,n,i+1),l=calc1(1,r-1,i);
		ans=max(ans,r-l-1);
	}
	write(max(ans,max(calc2(1,n,1)-1,n-calc1(1,n,m))),'\n');
	return ot(),0;
}